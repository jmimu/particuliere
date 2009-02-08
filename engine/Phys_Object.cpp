/*
 *      Phys_Object.cpp
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


#include "Phys_Object.h"


Phys_Object::Phys_Object(int size_x,int size_y)
	: Anim_Sprite(),speed_x(0.0),speed_y(0.0),mass(1.0),rect_size_x(size_x),rect_size_y(size_y),
	 rect(sf::Shape::Rectangle(0, 0, rect_size_x, rect_size_y, sf::Color(0, 255, 255, 100)))
{
	/*std::vector <unsigned int> anim_rythm;
    Animation *anim1=new Animation();
    anim1->load_animation("data/sjm/debout.png",32,64,anim_rythm);
    anims.push_back(anim1);
    
    anim_rythm.clear();
    Animation *anim2=new Animation();
    anim2->load_animation("data/sjm/marche.png",32,64,anim_rythm,false);
    anims.push_back(anim2);*/
    
    //this->SetImage(*(anims[0]->get_image(0.0)));
}

bool Phys_Object::update()//return true if object is deleted
{
	//if (y>200-rect_size_y) {speed_y=0;mass=-1;}
	//if (y<-200) {speed_y=0;mass=1;}
	return false;
}


Phys_Object::~Phys_Object()
{
	
}

//is it good?
void Phys_Object::set_rect_size(int s_x,int s_y)
{
	rect_size_x=s_x;
	rect_size_y=s_y;
	rect= sf::Shape::Rectangle(0, 0, rect_size_x, rect_size_y, sf::Color(0, 255, 255, 100));
}
