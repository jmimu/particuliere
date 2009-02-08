/*
 *      Ground_Plane.cpp
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


#include "Ground_Plane.h"

//static members have to be redefined in the cpp file
std::vector <sf::Image *> Ground_Plane::images_bg;
std::vector <sf::Image *> Ground_Plane::images_fg;


Ground_Plane::Ground_Plane(int num_image,float _scroll_speed,bool bg,bool _repeat_x,bool _repeat_y)
	: scroll_speed(_scroll_speed),pos_x(0),pos_y(0),repeat_x(_repeat_x),repeat_y(_repeat_y)
{
	std::cout<<"Create Ground_Plane\n";
	if (images_bg.size()+images_fg.size()==0) Load_Ground_Planes();
	if (bg) spr.SetImage(*images_bg[num_image]);//check ?
	else spr.SetImage(*images_fg[num_image]);//check ?
	size_x=spr.GetImage()->GetWidth();
	size_y=spr.GetImage()->GetHeight();
	half_size_x=size_x/2;
	half_size_y=size_y/2;
}


Ground_Plane::~Ground_Plane()
{
	//clean memory
}

void Ground_Plane::Load_Ground_Planes()
{
	sf::Image * img1=new sf::Image();
    img1->LoadFromFile("data/bg0.png");
    images_bg.push_back(img1);
    sf::Image * img2=new sf::Image();
    img2->LoadFromFile("data/bg1.png");
    images_bg.push_back(img2);
    sf::Image * img3=new sf::Image();
    img3->LoadFromFile("data/bg2.png");
    images_bg.push_back(img3);
    sf::Image * img4=new sf::Image();
    img4->LoadFromFile("data/bg3.png");
    images_bg.push_back(img4);
    
    sf::Image * img5=new sf::Image();
    img5->LoadFromFile("data/fg0.png");
    images_fg.push_back(img5);
    sf::Image * img6=new sf::Image();
    img6->LoadFromFile("data/fg1.png");
    images_fg.push_back(img6);
    sf::Image * img7=new sf::Image();
    img7->LoadFromFile("data/fg2.png");
    images_fg.push_back(img7);
}


bool Ground_Plane::draw(sf::RenderWindow & App, Camera & cam)
{
	int nbr_repeat_x=1;
	int nbr_repeat_y=1;
	if (repeat_x) nbr_repeat_x=cam.half_res_x()/half_size_x+3;//at least repeat 3 times
	if (repeat_y) nbr_repeat_y=cam.half_res_y()/half_size_y+3;//at least repeat 3 times
	
	if (!repeat_x && !repeat_y)
	{
		int x=pos_x-cam.get_x()*scroll_speed-half_size_x+cam.half_res_x();
		int y=pos_y-cam.get_y()*scroll_speed-half_size_y+cam.half_res_y();
		spr.SetPosition(x,y);
		App.Draw(spr);
	}

	if (repeat_x && !repeat_y)
	{
		for (int i=0;i<nbr_repeat_x;i++)
		{
			int x=(i-nbr_repeat_x/2)*(half_size_x*2)-half_size_x+cam.half_res_x()+((int)(pos_x-cam.get_x()*scroll_speed))%(half_size_x*2);
			int y=pos_y-cam.get_y()*scroll_speed-half_size_y+cam.half_res_y();
			spr.SetPosition(x,y);
			App.Draw(spr);
		}
	}
	if (repeat_y && !repeat_x)
	{
		for (int j=0;j<nbr_repeat_y;j++)
		{
			int x=pos_x-cam.get_x()*scroll_speed-half_size_x+cam.half_res_x();
			int y=(j-nbr_repeat_y/2)*(half_size_y*2)-half_size_y+cam.half_res_y()+((int)(pos_y-cam.get_y()*scroll_speed))%(half_size_y*2);
			spr.SetPosition(x,y);
			App.Draw(spr);
		}
	}
	if (repeat_x && repeat_y)
	{
		for (int i=0;i<nbr_repeat_x;i++)
		{
			for (int j=0;j<nbr_repeat_y;j++)
			{
				int x=(i-nbr_repeat_x/2)*(half_size_x*2)-half_size_x+cam.half_res_x()+((int)(pos_x-cam.get_x()*scroll_speed))%(half_size_x*2);
				int y=(j-nbr_repeat_y/2)*(half_size_y*2)-half_size_y+cam.half_res_y()+((int)(pos_y-cam.get_y()*scroll_speed))%(half_size_y*2);
				spr.SetPosition(x,y);
				App.Draw(spr);
			}
		}
	}
	return true;
}
/*
 * 	spr.SetPosition(-cam.get_x()*scroll_speed,-cam.get_y()*scroll_speed);
	App.Draw(spr);
	* 
	*
	if (repeat_x)
	{
		for (int i=0;i<nbr_repeat_x;i++)
		{
			int x=(i-nbr_repeat_x/2)*(half_size_x*2)-half_size_x+cam.half_res_x()+((int)(pos_x-cam.get_x()*scroll_speed))%(half_size_x*2);
			int y=pos_y-cam.get_y()*scroll_speed-half_size_y+cam.half_res_y();
			spr.SetPosition(x,y);
			App.Draw(spr);
		}
	}
	* * */
