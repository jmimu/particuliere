/*
 *      Ground_Plane.h
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


#ifndef GROUND_PLANE_H
#define GROUND_PLANE_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Camera.h"

//foreground or background
class Ground_Plane
{
	public:
		static void Load_Ground_Planes();
		Ground_Plane(int num_image,float _scroll_speed,bool bg=true,bool _repeat_x=false,bool _repeat_y=false);
		virtual ~Ground_Plane();
		bool draw(sf::RenderWindow & App, Camera & cam);
	
	protected:
		static std::vector <sf::Image *> images_bg;
		static std::vector <sf::Image *> images_fg;
		sf::Sprite spr;
		float scroll_speed;
		float pos_x,pos_y;
		int half_size_x,half_size_y;
		int size_x,size_y;
		bool repeat_x;
		bool repeat_y;
};

#endif /* GROUND_PLANE_H */ 
