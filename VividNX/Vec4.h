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

inline Vec4::Vec4() {

	X = Y = Z = W = 0;

}

inline Vec4::Vec4(float x, float y, float z,float w)
{

	X = x; Y = y; Z = z; W = w;

}

inline Vec4 Vec4::Zero() {

	return Vec4(0, 0, 0,0);

}
inline Vec4 Vec4::One() {

	return Vec4(1, 1, 1,1);

}

inline Vec4 Vec4::UnitX() {

	return Vec4(1, 0, 0, 0);

}

inline Vec4 Vec4::UnitY() {

	return Vec4(0, 1, 0, 0);

}

inline Vec4 Vec4::UnitZ() {

	return Vec4(0, 0, 1, 0);

}

inline Vec4 Vec4::UnitW() {

	return Vec4(0, 0, 0, 1);

}

