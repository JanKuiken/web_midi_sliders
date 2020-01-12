# Web MIDI Sliders

This is a small and quick program for use with my rp3synth project.

It uses the witty library (https://www.webtoolkit.eu/wt) to create a
webserver which has only one page with some sliders which emit MIDI controller events.

The code based the 'painting' example of WT (because that one uses WSlider's)

I used a simple Makefile like the one i used for rp3synth.

Some caveats:
- you need a link to /usr/share/Wt/resources/ named resouces in the directory where you run the program
- you need to connect the MIDI output of the program to your synth (aconnect is your friend)
- you need to vist the provided webpage before you can use aconnect


