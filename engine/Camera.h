/*
 * Camera.h
 *
 *  Created on: 12 juil. 2008
 *      Author: JMM
 */
/*
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef CAMERA_H_
#define CAMERA_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Anim_Sprite.h"
#include "Phys_Object.h"

class Camera {
protected:
	float x,y;
	int size_x,size_y;
	float min_x,min_y,max_x,max_y;//cam limits
	int inertia;
	float invert_speed;
public:
	Camera(float _x, float _y,int _size_x,int _size_y,float _min_x,float _min_y,float _max_x,float _max_y);
	virtual ~Camera();
	void set_position(float interest_x,float interest_y);
	float get_x(){return x;};
	float get_y(){return y;};
	int half_res_x(){return size_x/2;}
	int half_res_y(){return size_y/2;}
	bool draw_spr(sf::RenderWindow & App,Anim_Sprite spr);//add the camera shift
	bool draw_spr(sf::RenderWindow & App,Phys_Object spr,bool draw_shape=false);//draw shape, and add the camera shift
};

#endif /* CAMERA_H_ */
