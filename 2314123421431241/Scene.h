#pragma once
#include "Sphere.h"
#include <vector>
class Scene
{
public:

	Sphere listOfShapes[3];
	Scene();
	void addShape(Sphere shape);

};

