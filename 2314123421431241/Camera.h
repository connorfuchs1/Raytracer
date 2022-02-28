#pragma once
#include "Ray.h"
#include "vec3.h"

class Camera{
public:
	vec3 e_vec, u_vec, v_vec, w_vec;
	
	vec3 eyePos;
	vec3 LookAt = vec3(0, 0, -1);
	vec3 upVect;
	float left = -1, right = 1, top = 1, bottom = -1, near, far;

	Camera(vec3 e_vec, vec3 u_vec, vec3 v_vec, vec3 w_vec);

	Ray getOrthoRay(float i, float j, float width, float height);
	Ray getPerspectiveRay(float i, float j, float width, float height, int d);

};