/*
 *      R_Game.cpp
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


#include "R_Game.h"


R_Game::R_Game(float _FPS)
	: Game("R",_FPS)
{
	std::cout<<"Create R_Game\n";	
	load_level();
}


R_Game::~R_Game()
{
	
}

bool R_Game::load_level()
{
	std::cout<<"load_level\n";	
	level = new R_Level();
	return true;
}
