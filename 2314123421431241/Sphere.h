#pragma once
#include "Ray.h"
#include "Light.h"

class Sphere {
public:
	float x, y, z, intersection;
	float radius_sphere;
	vec3 Center;
	Sphere(float x, float y,float z, float raidus);
	
	float intersect(Ray r, int p, int q);
	float diffuseShading(Ray ray, Light light, int color);
	float phongShading(Ray ray, Light light, int color);
	

};