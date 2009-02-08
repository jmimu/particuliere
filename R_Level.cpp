/*
 *      R_Level.cpp
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


#include "R_Level.h"


R_Level::R_Level()
	: Level()
{
	std::cout<<"Create R_Level\n";
	load_level();
}


R_Level::~R_Level()
{
	
}

bool R_Level::load_level()
{
	//background
	bg.push_back(Ground_Plane(0,0));
	bg.push_back(Ground_Plane(1,0.2));
	bg.push_back(Ground_Plane(2,0.4));
	bg.push_back(Ground_Plane(3,0.8));
	//foreground
	fg.push_back(Ground_Plane(1,2,false,true));
	fg.push_back(Ground_Plane(2,3,false,false,true));
	//objects
	for (unsigned int i=0;i<100;i++)
	{
		Particle * obj=new Particle(0);
		obj->x=rand()%600-300;
		obj->y=rand()%50+150;
		obj->speed_y=rand()%20-10;
		obj->scale_speed=-(rand()%5+5)/100.0;
		obj->mass=-1;
		//obj->mass=(rand()%3)-1;
		objs.push_back(obj);
	}
	return true;
}
