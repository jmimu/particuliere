/*
 *      Anim_Sprite.h
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


#ifndef ANIM_SPRITE_H
#define ANIM_SPRITE_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Animation.h"

/**
 * SFML Sprite with several animations.
 * Images are stocked static in every class
 * 
 * Needs an enum Type for every class
 * 
 * Needs a time counter to know which pictire to draw
 */

class Anim_Sprite: public sf::Sprite
{
	public:
		enum Type
		{
			STAND,
			WALK
		};

	public:
		Anim_Sprite();
		virtual ~Anim_Sprite();
		bool set_anim_image(float time);//find the image of anim with current time and animation begin time
		bool set_position(unsigned int pos,float time);//set a new position at that time
		void return_to_default_position(float time){position=default_position;time_begin_anim=time;};
		bool set_default_position(unsigned int pos);
		
		const unsigned int get_position(){return position;};
		const bool is_default_position(){return position==default_position;};
		float x,y; //actual coord of center. The sf::Sprite coord are used only for drawing !
		bool add_anim(Animation * anim);
		void set_flipX(bool flip);
		bool isXflipped(){return Xflipped;};

	protected:
		std::vector <Animation *> anims;
		unsigned int position;//in an enumeration
		unsigned int default_position;//in an enumeration
		float animation_speed;
		float time_begin_anim;//if animation is not a loop
		bool Xflipped;
		
};

#endif /* ANIM_SPRITE_H */ 
