/*
 *      Game.cpp
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


#include "Game.h"

using namespace std;

Game::Game(string window_name,float _FPS)
	: FPS(_FPS),App(sf::VideoMode(640, 400, 32), window_name.c_str()),spr1()
{
 	std::cout<<"Create Game\n";
	App.SetFramerateLimit(FPS);
    srand ( time(NULL) );
}


Game::~Game()
{
	
}

bool Game::load_level()
{
	level=new Level();
	return true;
}

bool Game::run()
{
	cout<<"Start running game\n";
	float see_x=0;
	float see_y=0;
	
	//sf::Image target_img;
	//target_img.LoadFromFile("data/target.png");
	//sf::Sprite target;//(target_img);
	std::vector <unsigned int> anim_rythm;
	Animation *anim2=new Animation();
	anim2->load_animation("data/sjm/marche.png",32,64,anim_rythm,false);
	spr1.add_anim(anim2);
	spr1.set_position(0,0);
	spr1.set_default_position(0);
	
	
	float t=0;
	int t_int=0;
    bool running=true;
	while (running)
	{

        sf::Event Event;
        while (App.GetEvent(Event))
        {
			if ((Event.Type==sf::Event::Closed)||((Event.Type==sf::Event::KeyPressed)&&(Event.Key.Code==sf::Key::Escape)))
				return EXIT_SUCCESS;
        }
        get_input();
        
        //std::cout<<"look at "<<see_x<<" "<<see_y<<std::endl;        
        if (App.GetInput().IsKeyDown(sf::Key::Left)) {see_x-=5;spr1.set_flipX(true);if (spr1.is_default_position()) spr1.set_position(Anim_Sprite::WALK,t);}
        if (App.GetInput().IsKeyDown(sf::Key::Right)) {see_x+=5;spr1.set_flipX(false);if (spr1.is_default_position()) spr1.set_position(Anim_Sprite::WALK,t);}
        if (App.GetInput().IsKeyDown(sf::Key::Up)) see_y-=5;
        if (App.GetInput().IsKeyDown(sf::Key::Down)) see_y+=5;
        if (App.GetInput().IsKeyDown(sf::Key::A)) spr1.set_position(Anim_Sprite::STAND,t);
        if (App.GetInput().IsKeyDown(sf::Key::B)) spr1.set_position(Anim_Sprite::WALK,t);
        if (App.GetInput().IsKeyDown(sf::Key::Space)) spr1.return_to_default_position(t);
        
        if (App.GetInput().IsKeyDown(sf::Key::X))
        {
        	Particle_Src<Particle> src1(see_x,see_y,level->get_objs(),0,0,0,1,50,10,3*(int)!spr1.isXflipped(),0.1,0,0);
		}

       
        t+=0.2;
        t_int++;
        if (t>=100000000.) t=0;
        level->update();
   		level->cam.set_position(see_x,see_y);
        
        level->draw(App,t);
        
 
        spr1.set_anim_image(t);
        spr1.x=see_x;spr1.y=see_y;
        level->cam.draw_spr(App,spr1);
        level->draw_fg(App);

        App.Display();
        
        if (t_int%20==0)std::cout<<level->get_objs().size()<<"   "<<t_int<<"\n";
    }
    return true;
}

bool Game::get_input()
{
	/*bool button=App.GetInput().IsJoystickButtonDown(0, 1);

    if (attacking>=0)
    {
    	if ((App.GetInput().GetJoystickAxis(0, sf::Joy::AxisX)!=0)||(App.GetInput().GetJoystickAxis(0, sf::Joy::AxisY)!=0))
    	{
    		vx=(int)(App.GetInput().GetJoystickAxis(0, sf::Joy::AxisX)/20.0);
			vy=(int)(App.GetInput().GetJoystickAxis(0, sf::Joy::AxisY)/20.0);
    	}else{
        	if (!(App.GetInput().IsKeyDown(sf::Key::Left))&&(!(App.GetInput().IsKeyDown(sf::Key::Left)))) vx=0;
        	if (!(App.GetInput().IsKeyDown(sf::Key::Up))&&(!(App.GetInput().IsKeyDown(sf::Key::Down)))) vy=0;
        	if (App.GetInput().IsKeyDown(sf::Key::Left))
        		vx=-5;
        	if (App.GetInput().IsKeyDown(sf::Key::Right))
        		vx=5;
        	if (App.GetInput().IsKeyDown(sf::Key::Up))
        		vy=-5;
        	if (App.GetInput().IsKeyDown(sf::Key::Down))
        		vy=5;
        	if (App.GetInput().IsKeyDown(sf::Key::Space))
        		button=true;
        	else button=App.GetInput().IsJoystickButtonDown(0, 1);
        }
    }*/
	return false;
}
