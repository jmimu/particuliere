/*
 * Level.h
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

#ifndef LEVEL_H_
#define LEVEL_H_

#include <list>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "Ground_Plane.h"
#include "Phys_Object.h"
#include "Particle.h"
#include "Particle_Src.h"

class Level {
	friend class Game;
	public:
		Level();
		virtual ~Level();
		void draw(sf::RenderWindow & App,float time);
		virtual bool load_level();//loads bg, fg, ...
		virtual void update();//dynamic of objs
		std::list <Phys_Object *> & get_objs(){return objs;};
		
	protected:
		std::vector <Ground_Plane> bg;//background
		std::vector <Ground_Plane> fg;//foreground

		Camera cam;

		void draw_bg(sf::RenderWindow & App);
		void draw_fg(sf::RenderWindow & App);
		float gravity_value;
		std::list <Phys_Object *> objs;
};

#endif /* LEVEL_H_ */

/* back_ground
 	sf::Image bg0_img;
	sf::Sprite bg0_spr;
	float bg0_speed;
	* 
	bg0_img.LoadFromFile("data/bg0.png");
	bg0_spr.SetImage(bg0_img);
	bg0_speed=0.1;
	* 
	bg0_spr.SetPosition(-(x-size_x/2)*bg0_speed,-(y-size_y/2)*bg0_speed);
	App.Draw(bg0_spr);
*/
