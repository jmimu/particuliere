/*
 *      divers.cpp
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


#include "divers.h"


double divers::Random_Gaussian_JM(double m,double s)
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


