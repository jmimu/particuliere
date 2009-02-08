/*
 *      Phys_Object.h
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


#ifndef PHYS_OBJECT_H
#define PHYS_OBJECT_H

#include "Anim_Sprite.h"
/*
 * Phys_Object : physical object
 * animated sprite with collision rectangle
 * mass, and speed
 * */
class Phys_Object: public Anim_Sprite
{
	public:
		Phys_Object(int size_x,int size_y);
		virtual ~Phys_Object();
		const int get_rect_size_x(){return rect_size_x;};
		const int get_rect_size_y(){return rect_size_y;};
		const float get_mass(){return mass;};
		sf::Shape * get_rect(){return &rect;};
		virtual bool update();//return true if object is to be deleted

		void set_rect_size(int s_x,int s_y);
		
		float speed_x,speed_y;
		float mass;
	protected:
		//collision rectangle
		int rect_size_x,rect_size_y;//the sprite coord are the top-left corner
		sf::Shape rect;
};

#endif /* PHYS_OBJECT_H */ 
