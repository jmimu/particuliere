/*
 *      Anim_Sprite.cpp
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


#include "Anim_Sprite.h"


Anim_Sprite::Anim_Sprite()
	: sf::Sprite(),x(0.0),y(0.0),position(0),default_position(0),animation_speed(1.0),time_begin_anim(0.0),Xflipped(false)
{

}


Anim_Sprite::~Anim_Sprite()
{
	
}

void Anim_Sprite::set_flipX(bool flip)
{
	FlipX(flip);
	Xflipped=flip;
}

bool Anim_Sprite::set_anim_image(float time)
{
	if ((!anims[position]->is_loop())&&((time-time_begin_anim)*animation_speed>anims[position]->anim_length()))
	{
		position=default_position;
		time_begin_anim=time;
	}
		
	this->SetImage(*(anims[position]->get_image((time-time_begin_anim)*animation_speed)));
	return true;
}

bool Anim_Sprite::set_position(unsigned int pos,float time)
{
	if (pos>=anims.size()) return false;
	position=pos;
	time_begin_anim=time;
	return true;
}

bool Anim_Sprite::set_default_position(unsigned int pos)
{
	if (pos>=anims.size()) return false;
	default_position=pos;
	return true;
}

bool Anim_Sprite::add_anim(Animation * anim)
{
	anims.push_back(anim);
	return true;
}
