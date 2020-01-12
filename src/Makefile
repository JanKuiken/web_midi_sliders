
APP         := web_sliders

EXEDIR      := ../run

OBJS        := main.o        \
               web_midi_sliders.o 

CC          := g++
LINK        := g++

CCLAGS      := -std=c++14 -Wall -O2

LIBS        := -lm -lasound -lpthread -lwt -lwthttp
LINKFLAGS   := -O2

EXECUTABLE  := $(EXEDIR)/$(APP)


all: $(EXECUTABLE)

clean:
	rm -f $(OBJS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJS) 
	$(LINK) $(LINKFLAGS) $^ $(LIBS) -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

