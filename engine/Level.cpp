/*
 * Level.cpp
 *
 *  Created on: 17 juil. 2008
 *      Author: JMM
 */
/*
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "Level.h"

using namespace std;

Level::Level()
	: cam(0,0,640,400,-500,-400,500,0),gravity_value(9.8)
{
	std::cout<<"Create Level\n";
	
}

Level::~Level() {
	//delete background, foreground, objects

}


void Level::draw(sf::RenderWindow & App,float time)
{
    draw_bg(App);
    
    //std::cout<<"nbr objs: "<<objs.size()<<std::endl;
    for (list<Phys_Object*>::iterator iter = objs.begin();iter != objs.end();iter++)
    {
		(*iter)->set_anim_image(time);
    	cam.draw_spr(App,(**iter),false);
	}
	
	/*for (unsigned int i=0;i<objs.size();i++)
    {
    	objs[i]->set_anim_image(time);
    	cam.draw_spr(App,(*objs[i]),true);
    }*/
}

void Level::update()
{
	for (list<Phys_Object*>::iterator iter = objs.begin();iter != objs.end();iter++)
    {
    	//std::cout<<"   speed x : "<<(*iter)->speed_x<<" "<<(*iter)->x<<"\n";
    	(*iter)->speed_y+=(*iter)->mass*gravity_value/10.0;
    	(*iter)->x+=(*iter)->speed_x/10.0;
    	(*iter)->y+=(*iter)->speed_y/10.0;
    	if ((*iter)->update())
    	{
    		//destroy
    		Phys_Object * obj= *iter;
    		delete obj;
    		iter=objs.erase( iter ); 		
		}
    }
}

void Level::draw_bg(sf::RenderWindow & App)
{
	for (unsigned int i=0;i<bg.size();i++)
    {
    	bg[i].draw(App,cam);
    }
}

void Level::draw_fg(sf::RenderWindow & App)
{
	for (unsigned int i=0;i<fg.size();i++)
    {
    	fg[i].draw(App,cam);
    }
}

bool Level::load_level()
{
	return true;
}
