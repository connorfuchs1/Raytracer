
#include "Camera.h"
#include <iostream>
using namespace std;


Camera::Camera(vec3 e_vec, vec3 u_vec, vec3 v_vec, vec3 w_vec) {
	
	this->e_vec = e_vec;
	this->u_vec = u_vec;
	this->v_vec = v_vec;
	this->w_vec = w_vec;

}

Ray Camera::getOrthoRay(float i, float j, float width, float height) {
	//point at position u,v
	double u = (i + .5) / width;
	double v = (j + .5) / height;

	
	
	vec3 point = e_vec - w_vec + u_vec * (u - .5) * width + v_vec * (v - .5) * height;
	Ray ray = Ray(point, LookAt);
	return ray;
	
 
}

Ray Camera::getPerspectiveRay(float i, float j, float width, float height, int d ) {
	double u = (i + .5) / width;
	double v = (j + .5) / height;

	
	vec3 rayDirection = (w_vec * -d) + u_vec * (u - .5) * width   + v_vec * (v - .5) * height ;

	Ray ray = Ray(e_vec, rayDirection);
	return ray;
}