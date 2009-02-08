/*
 * corbo.cpp
 *
 *  Created on: 14 juil. 2008
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

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "R_Game.h"

using namespace std;

int main(void) {

	R_Game game(50.);
	game.run();

	return EXIT_SUCCESS;
}
