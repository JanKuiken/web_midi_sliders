# Web MIDI Sliders

This is a small and quick accompening program for my rp3synth project.

It uses the witty library (https://www.webtoolkit.eu/wt) to create a
webserver which has only one page with some sliders which emit MIDI controller events.
I used a simple Makefile like the one i used for rp3synth.

The code is a rewrite of the 'painting' example of WT (because that one
uses WSlider's)

Some caveats:

- you need a link to /usr/share/Wt/resources/ named resouces in the directory where you run the program

- you need to connect the MIDI output of the program to your synth (aconnect is your friend)

