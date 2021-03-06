/*
    Copyright (C) 2015 Panagiotis Roubatsis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "PopulationMap.h"
#include "Random.h"
#include <functional>

std::vector<std::vector<float> > Procedural::Map::generatePopulationMap(const int& width, const int& height)
{
	const float SCALE = 1.25f;	//Used to scale the coordinates to zoom in and out of the noise

	//Linear interpolation
	std::function<float(float,float,float)> lerp = [](float a, float b, float t) -> float {return t * (b-a) + a;};
	
	//Smooth function to be used with lerp so that the output is not blocky
	std::function<float(float)> smooth = [](float t) -> float {return t*t*(3-2*t);};

	//Gradient vectors for use with perlin noise
	std::vector<std::vector<float*> > gradients;
	for(int y = 0; y < height; y++)
	{
		std::vector<float*> row;
		for(int x = 0; x < width; x++)
		{
			float vec[2] = {Random::nextFloat(-1, 1), Random::nextFloat(-1, 1)};
			row.push_back(vec);
		}
		gradients.push_back(row);
	}

	//Returns the dot product of two vectors from the set of gradients
	std::function<float(int,int,float,float)> noise = [&](int x, int y, float fx, float fy) -> float {return gradients[y%height][x%width][0] * fx + gradients[y%height][x%width][1] * fy;};

	//Create the population map
	std::vector<std::vector<float> > populationMap;
	for(int y = 0; y < height; y++)
	{
		std::vector<float> row;
		for(int x = 0; x < width; x++)
		{
			float sx = (x/(float)width) * SCALE;
			float sy = (y/(float)height) * SCALE;
			int ix = (int)sx;
			int iy = (int)sy;
			float fx = sx - ix;
			float fy = sy - iy;

			float top = lerp(noise(ix,iy,fx,fy), noise(ix+1,iy,fx-1,fy), smooth(fx));
			float bottom = lerp(noise(ix,iy+1,fx,fy-1), noise(ix+1,iy+1,fx-1,fy-1), smooth(fx));

			row.push_back( lerp(top, bottom, smooth(fy)) );
		}
		populationMap.push_back(row);
	}

	return populationMap;
}