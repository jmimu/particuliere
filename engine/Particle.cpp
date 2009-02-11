/*
 *      Particle.cpp
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


#include "Particle.h"

using namespace std;
vector <Animation *> Particle::particle_anims;
int Particle::nbr_particles=0;

Particle::Particle(int part_type)
	: Phys_Object(0,0),scale_speed(0.0),scale(1.0),angle(0.0)
{
	//cout<<"One particle to create\n";
	if (nbr_particles==0) load_particle_animations();
	anims.push_back(particle_anims[part_type]);
	nbr_particles++;
	
	int size_x=(anims[0]->get_image(0.0))->GetWidth();
	int size_y=(anims[0]->get_image(0.0))->GetHeight();
	
	this->SetImage(*(anims[0]->get_image(0.0)));
	set_rect_size(size_x,size_y);
	animation_speed=0.5;
	
	//cout<<"One particle created\n";
}


Particle::~Particle()
{
	//cout<<"One particle destroyed\n";
	nbr_particles--;
	if (nbr_particles==0) delete_anims();
}

bool Particle::update()//return true if object is deleted
{
	Phys_Object::update();
	angle+=10;
	this->SetRotation(angle);
	
	scale+=scale_speed/10.0;
	this->SetScale(scale,scale);
	//cout<<"size : "<<this->GetImage()->GetHeight()<<endl;
	//->GetWidth()*scale<<"  "<<GetImage()->GetHeight()*scale<<endl;
	rect_size_x=GetImage()->GetWidth()*scale;
	rect_size_y=GetImage()->GetHeight()*scale;
	rect.SetScale(scale,scale);
	
	//change collision rectangle with scale ?
	
	if (scale<0.01) return true; //delete
	
	return false;	
}

void Particle::delete_anims()
{
	cout<<"delete particle anims\n";
	for (unsigned int i=0;i<particle_anims.size();i++)
		delete particle_anims[i];
	particle_anims.clear();
}

bool Particle::load_particle_animations()
{
	cout<<"load paricle anims\n";
	particle_anims.clear();
	std::vector <unsigned int> anim_rythm;
    Animation *anim1=new Animation();
    anim1->load_animation("data/divers/smoke.png",64,64,anim_rythm);
    particle_anims.push_back(anim1);
    
    anim_rythm.clear();
    Animation *anim2=new Animation();
    anim2->load_animation("data/divers/spark.png",64,64,anim_rythm);
    particle_anims.push_back(anim2);
    
    //cout<<"Part animations loaded\n";
    return true;
}

