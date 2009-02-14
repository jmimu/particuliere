cmake_minimum_required(VERSION 2.6)

PROJECT( roues_auto )

SET( ENGINE_PATH "../engine" CACHE PATH "Path to engine" )

ADD_EXECUTABLE(
                moteur01 moteur01.cpp				
                R_Game.cpp
		R_Game.h
                R_Level.cpp
		R_Level.h
                ${ENGINE_PATH}/Game.cpp
                ${ENGINE_PATH}/Game.h
                ${ENGINE_PATH}/Animation.cpp
                ${ENGINE_PATH}/Animation.h  
                ${ENGINE_PATH}/Anim_Sprite.cpp
                ${ENGINE_PATH}/Anim_Sprite.h
                ${ENGINE_PATH}/Phys_Object.cpp
                ${ENGINE_PATH}/Phys_Object.h
                ${ENGINE_PATH}/Particle.cpp
                ${ENGINE_PATH}/Particle.h
                ${ENGINE_PATH}/Particle_Src.cpp
                ${ENGINE_PATH}/Particle_Src.h
                ${ENGINE_PATH}/divers.cpp
                ${ENGINE_PATH}/divers.h
                ${ENGINE_PATH}/Ground_Plane.cpp
                ${ENGINE_PATH}/Ground_Plane.h
                ${ENGINE_PATH}/Camera.cpp
                ${ENGINE_PATH}/Camera.h
                ${ENGINE_PATH}/Level.cpp
                ${ENGINE_PATH}/Level.h
)

SET(CMAKE_CXX_FLAGS "-O0 -g -Wall -fmessage-length=0")

TARGET_LINK_LIBRARIES( moteur01 sfml-audio sfml-graphics sfml-window sfml-system)

