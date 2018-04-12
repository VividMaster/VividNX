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

inline Vec3::Vec3(float x, float y, float z)
{
	
	X = x; Y = y; Z = z;

}

inline Vec3 Vec3::Zero() {

	return Vec3(0, 0, 0);

}
inline Vec3 Vec3::One() {

	return Vec3(1, 1, 1);

}