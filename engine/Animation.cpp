/*
 *      Animation.cpp
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


#include "Animation.h"


Animation::Animation()
{
	
}


Animation::~Animation()
{
		
}

bool Animation::load_animation(std::string file_name,unsigned int size_x,unsigned int size_y,std::vector <unsigned int> & time_for_each_image,bool _loop)
{
	loop=_loop;
	sf::Image image;
	images.clear();
	if (!image.LoadFromFile(file_name.c_str()))
	{
		std::cout<<"Error: "<<file_name<<" not found\n";
		return false;
	}

	unsigned int nbr_x = image.GetWidth()/size_x;
	unsigned int nbr_y = image.GetHeight()/size_y;
	if ((nbr_x==0)||(nbr_y==0))
	{
		std::cout<<"Error: "<<file_name<<" size not correct ("<<size_x<<","<<size_y<<")\n";
		return false;
	}
	std::cout<<"Animation "<<file_name<<"  size : "<<nbr_x<<" "<<nbr_y<<"   ("<<size_x<<","<<size_y<<")\n";
	for (unsigned int y=0;y<nbr_y;y++)
	{
		for (unsigned int x=0;x<nbr_x;x++)
		{
			sf::Image * img=new sf::Image(size_x,size_y);
			//std::cout<<"Loading "<<x*size_x<<" "<<y*size_y<<" "<<(x+1)*size_x-1<<" "<<(y+1)*size_y-1<<std::endl;
			img->Copy(image,0,0,sf::IntRect(x*size_x, y*size_y, (x+1)*size_x, (y+1)*size_y));
			images.push_back(*img);
		}
	}
	for (unsigned int i=time_for_each_image.size();i<=nbr_x*nbr_y;i++)
		time_for_each_image.push_back(1);
	time_for_each_image.resize(nbr_x*nbr_y);
	
	unsigned int time_length=0;
	for (unsigned int i=0;i<time_for_each_image.size();i++)
		time_length+=time_for_each_image[i];
	
	timing.clear();
	for (unsigned int i=0;i<time_for_each_image.size();i++)
		for (unsigned int j=0;j<time_for_each_image[i];j++)
		{
			//std::cout<<"timing : "<<i<<std::endl;
			timing.push_back(i);
		}
	
	return true;
}

bool Animation::load_animation(std::string file_name,unsigned int size_x,unsigned int size_y,bool _loop)
{
	std::vector <unsigned int> anim_rythm;
	return load_animation(file_name,size_x,size_y,anim_rythm,_loop);
}

sf::Image * Animation::get_image(unsigned int time)
{
	unsigned int time_corrected=time;
	time_corrected%=anim_length();
	//std::cout<<"time: "<<time_corrected<<"   image: "<<timing[time_corrected]<<std::endl;
	return &images[timing[time_corrected]];
}
