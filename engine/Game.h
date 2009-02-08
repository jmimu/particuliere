/*
 *      Game.h
 *      
 *      Copyright 2009 JMMuller <jmmuller@ts>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */


#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "Level.h"
#include "Phys_Object.h"
#include "Particle.h"
#include "Particle_Src.h"

class Game //make it virtual ?
{
	Anim_Sprite spr1;
	
	public:
		Game(std::string window_name,float _FPS);
		virtual ~Game();
		bool run();//main loop return error ?
		bool get_input();
		virtual bool load_level();
		float get_FPS() {return FPS;};
		sf::RenderWindow * get_App(){return &App;};
	protected:
		Level * level;//just one level now...
		float FPS;
		sf::RenderWindow App;
};

#endif /* GAME_H */ 
