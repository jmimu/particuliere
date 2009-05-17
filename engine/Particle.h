/*
 *      Particle.h
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


#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <iostream>
#include "Animation.h"
#include "Phys_Object.h"

/**
 * Particle class :
 * simple phys obj with an animation, a rotation and a scale speed
 * disapears when too little
 * 
 * to add : disapears when out of area
 * */

class Particle: public Phys_Object
{
	public:
		enum Type
		{
			SMOKE,
			SPARK,
			WATER
		};
		
	public:
		Particle(int part_type);
		~Particle();
		virtual bool update();//return true if object is deleted
		
		float scale;
		float scale_speed;
		float angle;

		static void delete_anims();

	private:
		
		static std::vector <Animation *> particle_anims;
		static int nbr_particles;
		static bool load_particle_animations();
		
		static int masses[3];//masses of differents types of particle
};

#endif /* PARTICLE_H */ 
