/*
 * Camera.cpp
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

#include "Camera.h"

Camera::Camera(float _x, float _y,int _size_x,int _size_y,float _min_x,float _min_y,float _max_x,float _max_y)
	: x(_x),y(_y),size_x(_size_x),size_y(_size_y),min_x(_min_x),min_y(_min_y),max_x(_max_x),max_y(_max_y),inertia(0),invert_speed(20.0)
{

}

Camera::~Camera() {

}

bool Camera::draw_spr(sf::RenderWindow & App,Anim_Sprite spr)//add the camera shift (x,y) in ground ref 
{
	sf::Vector2f spr_size=spr.GetSize();	
	int x2=spr.x-x+size_x/2-spr_size.x/2;
	int y2=spr.y-y+size_y/2-spr_size.y/2;
	spr.SetPosition(x2,y2);
	App.Draw(spr);
	//std::cout<<"Draw "<<_x<<"  "<<_y<<"    "<<x2<<" "<<y2<<std::endl;
	return true;
}

bool Camera::draw_spr(sf::RenderWindow & App,Phys_Object spr,bool draw_shape)//draw shape, and add the camera shift
{
	if (draw_shape)
	{
		int x2=spr.x-x+size_x/2;
		int y2=spr.y-y+size_y/2;
		spr.get_rect()->SetPosition(x2,y2);
		App.Draw(*spr.get_rect());
	}

	return draw_spr(App,(Anim_Sprite) spr);//draw picture
}


void Camera::set_position(float interest_x,float interest_y)
{
	//std::cout<<"camera at "<<x<<" "<<y<<std::endl;
	//std::cout<<"invert_speed "<<invert_speed<<std::endl;
	if (interest_x-inertia>x) x+=(interest_x-inertia-x)/invert_speed;
	if (interest_x+inertia<x) x+=(interest_x+inertia-x)/invert_speed;
	if (interest_y-inertia>y) y+=(interest_y-inertia-y)/invert_speed;
	if (interest_y+inertia<y) y+=(interest_y+inertia-y)/invert_speed;
	if (x<min_x) x=min_x;
	if (y<min_y) y=min_y;
	if (x>max_x) x=max_x;
	if (y>max_y) y=max_y;
}




