
#include <Wt/WApplication>

#include "web_midi_sliders.h"

using namespace Wt;

class MApplication: public WApplication
{
public:
  MApplication(const WEnvironment &env): WApplication(env) {
    setTitle("Web MIDI sliders");
    
    new WebMidiSliders(root());
  }
};

WApplication *createApplication(const WEnvironment& env)
{
  return new MApplication(env);
}

int main(int argc, char **argv)
{
  return WRun(argc, argv, &createApplication);
}

