CXXFLAGS =	-O0 -g -Wall -fmessage-length=0
#CXXFLAGS =	-O9

ENGINE_OBJS = Camera.o Level.o Game.o Ground_Plane.o Animation.o Anim_Sprite.o Phys_Object.o Particle.o Particle_Src.o divers.o
SFML = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIBS = $(SFML)

all:	$(ENGINE_OBJS)

Game.o : Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c Game.cpp
	
Animation.o : Animation.cpp Animation.h
	$(CXX) $(CXXFLAGS) -c Animation.cpp

Anim_Sprite.o : Anim_Sprite.cpp Anim_Sprite.h
	$(CXX) $(CXXFLAGS) -c Anim_Sprite.cpp

Phys_Object.o : Phys_Object.cpp Phys_Object.h
	$(CXX) $(CXXFLAGS) -c Phys_Object.cpp

Particle.o : Particle.cpp Particle.h
	$(CXX) $(CXXFLAGS) -c Particle.cpp

Particle_Src.o : Particle_Src.cpp Particle_Src.h
	$(CXX) $(CXXFLAGS) -c Particle_Src.cpp

divers.o : divers.cpp divers.h
	$(CXX) $(CXXFLAGS) -c divers.cpp

Ground_Plane.o : Ground_Plane.cpp Ground_Plane.h
	$(CXX) $(CXXFLAGS) -c Ground_Plane.cpp
	
Camera.o : Camera.cpp Camera.h
	$(CXX) $(CXXFLAGS) -c Camera.cpp

Level.o : Level.cpp Level.h
	$(CXX) $(CXXFLAGS) -c Level.cpp

clean:
	rm -f *.o

