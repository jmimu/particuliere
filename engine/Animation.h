/*
 *      Animation.h
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


#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

/* 
 * Animations
 * where the images are
 */
class Animation
{
	public:
		Animation();
		virtual ~Animation();
		bool load_animation(std::string file_name,unsigned int size_x,unsigned int size_y,std::vector <unsigned int> & time_for_each_image,bool _loop=true);
		sf::Image * get_image(unsigned int time);
		unsigned int anim_length(){return timing.size();}
		const bool is_loop(){return loop;}
	private:
		/* add your private declarations */
		std::vector <sf::Image> images;
		std::vector <int> timing;//index of images [0 0 0 1 1 2 3 3 4 4 4]
		bool loop;//is it a loop ?
};

#endif /* ANIMATION_H */ 
