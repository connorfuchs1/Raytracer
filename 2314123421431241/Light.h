#pragma once
#include "vec3.h"
class Light
{
public:
	float intensity;
	vec3 Location;

	Light(vec3 location, float intensity);
};

