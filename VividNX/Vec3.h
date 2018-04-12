#pragma once

#include "stdafx.h"

using namespace std;


struct Vec3 {
public:

	float X=0, Y=0, Z=0;

	Vec3(float x, float y, float z);
	static Vec3 Zero();
	static Vec3 One();


};
