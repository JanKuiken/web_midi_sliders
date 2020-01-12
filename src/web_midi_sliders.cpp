
#include <Wt/WContainerWidget>
#include <Wt/WGridLayout>
#include <Wt/WSlider>
#include <Wt/WText>

#include <iostream>
#include <string>
#include <stdlib.h>     // for exit and EXIT_FAILURE

#include "web_midi_sliders.h"

using namespace Wt;

WebMidiSliders::WebMidiSliders(WContainerWidget *root)
  : WContainerWidget(root)
{
  const auto labels = std::list<std::string>({
    "Attack", 
    "Decay", 
    "Sustain",
    "Release"
  });


  WContainerWidget *emweb = new WContainerWidget(this);
  emweb->setMargin(WLength::Auto, Left | Right);

  WGridLayout *layout = new WGridLayout();
  emweb->setLayout(layout);

  int row = 0;
  for (auto label : labels) {

    int offset = row * 1000;

    WSlider *slider = new WSlider(Horizontal);
    slider->setMinimum(offset + 0);
    slider->setMaximum(offset + 127);
    slider->setTickInterval(16);
    slider->setTickPosition(Wt::WSlider::TicksBothSides);
    slider->resize(500, 20);
    slider->sliderMoved().connect(this, &WebMidiSliders::sliderMove);

    WText *value = new WText("000");
    textValues.push_back(value);

    layout->addWidget(new WText(label), row, 0, AlignRight | AlignMiddle);
    layout->addWidget(slider, row, 1, AlignCenter | AlignMiddle);
    layout->addWidget(value, row, 2, AlignLeft | AlignMiddle);

    row++; 

  }
  
  // set up ALSA
  if (snd_seq_open(&seq_handle, "default", SND_SEQ_OPEN_DUPLEX, 0) < 0) {
    std::cout <<  "Error opening ALSA sequencer." << std::endl;
    exit (EXIT_FAILURE);
  }
  if (snd_seq_set_client_name(seq_handle, "WebSliders") < 0) {
    std::cout <<  "Error setting client name" << std::endl;
    exit (EXIT_FAILURE);
  }
  if ((out_port = snd_seq_create_simple_port(seq_handle, "WebSliders",
              SND_SEQ_PORT_CAP_READ|SND_SEQ_PORT_CAP_SUBS_READ,
              SND_SEQ_PORT_TYPE_APPLICATION)) < 0) {
      std::cout << "Error creating sequencer port." << std::endl;
      exit (EXIT_FAILURE);
  }
   

}

void WebMidiSliders::sliderMove(int v)
{
  int slider = v / 1000;
  int value = v % 1000;
  std::cout << "=====================" << std::endl;
  std::cout << "slider " << slider << " : " << value << std::endl;
  std::cout << "=====================" << std::endl;
  textValues[slider]->setText(std::to_string(value));

  // send modulation event
  snd_seq_event_t ev;
  snd_seq_ev_clear(&ev);
  snd_seq_ev_set_subs(&ev);
  snd_seq_ev_set_direct(&ev);
  snd_seq_ev_set_controller(&ev, 0, slider + 20, value);
  snd_seq_event_output_direct(seq_handle, &ev);
}

