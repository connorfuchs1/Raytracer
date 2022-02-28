
#include "Sphere.h"
#include <iostream>



using namespace std;

	//constructor for sphere
	Sphere::Sphere(float x, float y, float z,  float radius) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->Center = vec3(x, y, z);
		this->radius_sphere = radius;
	}

//https://fiftylinesofcode.com/ray-sphere-intersection/

	float  Sphere::intersect(Ray ray, int start, int length) {
		
		vec3 o_minus_c = ray.rayOrigin - Center;
		float p = dotprod(ray.rayDirection, o_minus_c);
		float q = dotprod(o_minus_c, o_minus_c) - (radius_sphere * radius_sphere);


		float discriminant = (p * p) - q;

		if (discriminant < 0) {
			return NULL;
		}
		
		float dRoot = sqrt(discriminant);
		float intersection1 = -p - dRoot;
		float intersection2 = -p + dRoot;

		
		if (intersection1 < intersection2) {
			this->intersection = intersection1;
			return intersection1;

		}
		//this->intersection = intersection2;
		this->intersection = intersection2;
		return intersection2;
	}

	//calculate intersection point and then normal at that point to do shading.
	float Sphere::diffuseShading(Ray ray, Light light, int color) {

		vec3 intersection3D = ray.rayOrigin + ray.rayDirection * this->intersection;
		vec3 normal = intersection3D - this->Center;
		vec3 vl = light.Location - intersection3D;
		
		vl.Normalize();
		normal.Normalize();

		float diffuseCoefficient = color;
		float specularCoefficient = color;
		
		
		vec3 h = (vec3(0,0,0) + vl) / ((vec3(0,0,0) + vl).Length());
		h.Normalize();

		float p = 1;

		float diffuseLight = 1 * (light.intensity * max(0.0, dotprod(normal, vl)));
		//cout << diffuseLight << endl;
		float specularLight = 	1 *  (light.intensity *    pow ( max( 0.0, dotprod(normal, h) ), p )     ); 
		 

		vec3 mirrorReflection = (normal - ray.rayDirection) * (dotprod(normal, vec3(0, 0, 0)) * 2);
		//cout << specularLight << endl;


		float Light;
		if(diffuseLight + specularLight > 255)
		{
			Light = 255;
		}
		else {
			Light = diffuseLight + specularLight;
		}
		 

		return Light;
	}

	
	
	


