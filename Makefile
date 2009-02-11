CXXFLAGS =	-O0 -g -Wall -fmessage-length=0
#CXXFLAGS =	-O9

OBJS =		moteur01.o R_Level.o R_Game.o
SFML = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIBS = $(SFML)

TARGET =	moteur01

all: engine_ $(TARGET)

engine_:
	(cd engine && $(MAKE))

$(TARGET): engine_ $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) engine/*.o $(LIBS)

moteur01.o : moteur01.cpp
	$(CXX) $(CXXFLAGS) -c moteur01.cpp

R_Game.o : R_Game.cpp R_Game.h
	$(CXX) $(CXXFLAGS) -c R_Game.cpp
		
R_Level.o : R_Level.cpp R_Level.h
	$(CXX) $(CXXFLAGS) -c R_Level.cpp

clear:
	rm -f *.o engine/*.o

