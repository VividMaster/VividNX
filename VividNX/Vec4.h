#pragma once

#include "stdafx.h"

using namespace std;


struct Vec4 {
public:

	float X = 0, Y = 0, Z = 0,W=0;

	Vec4();
	Vec4(float x, float y, float z,float w);
	static Vec4 Zero();
	static Vec4 One();
	static Vec4 UnitX();
	static Vec4 UnitY();
	static Vec4 UnitZ();
	static Vec4 UnitW();


};
