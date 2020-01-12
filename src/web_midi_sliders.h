// This may look like C code, but it's really -*- C++ -*-
/*
 * Copyright (C) 2008 Emweb bvba, Kessel-Lo, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#ifndef WEB_MIDI_SLIDERS_H_
#define WEB_MIDI_SLIDERS_H_

#include <Wt/WContainerWidget>
#include <Wt/WText>

#include <vector>
#include <alsa/asoundlib.h>

using namespace Wt;

class WebMidiSliders: public WContainerWidget
{
public:
  WebMidiSliders(WContainerWidget *root);

private:
  int out_port;
  snd_seq_t *seq_handle;
  std::vector<WText*> textValues;
  void sliderMove(int v);
};

#endif // WEB_MIDI_SLIDERS_H_
