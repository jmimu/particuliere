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
      Particle * obj=new Particle(Particle::SMOKE);
      obj->x=rand()%600-300;
      obj->y=rand()%50+150;
      obj->speed_y=rand()%20-10;
      //obj->scale_speed=-(rand()%5+5)/100.0;
      objs.push_back(obj);
    }
  Particle_Src<Particle> *src =new Particle_Src<Particle>(Particle::WATER,0,0,objs,0,0,0,1,50,4,-1.5708,0.1,1,0.1);
  //src->speed_x=10;
  Animation *anim1=new Animation();
  anim1->load_animation("data/divers/1.png",32,32);
  src->add_anim(anim1);
  
  objs.push_back(src);

  Particle_Src<Particle> *fire1_smoke =new Particle_Src<Particle>(Particle::SMOKE,150,0,objs,0,0 ,0,1,1,1,-1.5708,0.1,0.2,0.1);
  objs.push_back(fire1_smoke);
  Particle_Src<Particle> *fire1 =new Particle_Src<Particle>(Particle::FIRE,150,0,objs,0,0,0,1, 10,1,-1.5708,0.1, 0.1,0.1);
  objs.push_back(fire1);


  return true;
}
