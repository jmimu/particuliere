/*
 *      Particle_Src.h
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


#ifndef PARTICLE_SRC_H
#define PARTICLE_SRC_H

#include <math.h>
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "Phys_Object.h"
#include "Particle.h"
//#include "divers.h"

#define MATH_PI 3.15149
/**
 * Particle_Src : Particle source
 * only Gaussian proba
 */
template<class T>
class Particle_Src: public Phys_Object
{
	public:
//		Particle_Src();
		//Particle_Src(int size_x,std::list <Phys_Object*> *objs);//,int size_x,int size_y,int nbr_total_part,int nbr_part_now,float _speed_m=0,float _speed_s=0,float _angle_m=0,float _angle_s=0,float _density_m=0,float _density_s=0);
	public:
		double Random_Gaussian_JM(double m,double s);
		//nbr_total_part < 0 : infinite
		//m : mean, s : sigma
		//add new Particles to objs
		Particle_Src(float _x,float _y,std::list <Phys_Object*> &objs,int size_x,int size_y,int nbr_total_part,unsigned int nbr_part_now,float _speed_m=0,float _speed_s=0,float _angle_m=0,float _angle_s=0,float _density_m=0,float _density_s=0);
		//virtual ~Particle_Src();
		const bool get_is_finished(){return is_finished;}
		
	private:
		int particules_remaining;//0 => destroy
		//params for particles : gaussian law
		float speed_m;
		float speed_s;
		float angle_m;
		float angle_s;
		float density_m;
		float density_s;
		bool is_finished;
};

template<class T>
double Particle_Src<T>::Random_Gaussian_JM(double m,double s)
{
	unsigned  n1,n2;
	double    x1,x2,y;
	// on ne veut pas que <x1> et <x2> soit nuls
	while((n1 = rand(),0 == n1));
	while((n2 = rand(),0 == n2));
	x1 = n1/((double)(unsigned)(-2));
	x2 = n2/((double)(unsigned)(-2));
	// methode de Boc-Muller
	// <y> suit une loi normale reduite (m=0,s=1)
	y = sqrt(-2*log(x1))*cos(2.*MATH_PI*x2);
	return m + s*y;
}

template<class T>
Particle_Src<T>::Particle_Src(float _x,float _y,std::list <Phys_Object *> &objs,int size_x,int size_y,int nbr_total_part,unsigned int nbr_part_now,float _speed_m,float _speed_s,float _angle_m,float _angle_s,float _density_m,float _density_s)
	: Phys_Object(size_x,size_y),speed_m(_speed_m),speed_s(_speed_s),angle_m(_angle_m),angle_s(_angle_s),density_m(_density_m),density_s(_density_s)
{
	x=_x;y=_y;
	//std::cout<<"Create a Particle_Src\n";
	for (unsigned int i=0;i<nbr_part_now;i++)
	{
		Particle * obj=new Particle(0);
		obj->x=x;
		obj->y=y;
		float speed=Random_Gaussian_JM(speed_m,speed_s);
		float alpha=Random_Gaussian_JM(angle_m,angle_s);
		obj->speed_x=speed*cos(alpha);
		obj->speed_y=speed*sin(alpha);
		obj->scale_speed=-0.1;
		obj->mass=-1;
		objs.push_back(obj);
	}
}

#endif /* PARTICLE_SRC_H */ 
