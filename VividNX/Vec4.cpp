#pragma once

#include "stdafx.h"



 Vec4::Vec4() {

	X = Y = Z = W = 0;

}

 Vec4::Vec4(float x, float y, float z, float w)
{

	X = x; Y = y; Z = z; W = w;

}

 Vec4 Vec4::Zero() {

	return Vec4(0, 0, 0, 0);

}
 Vec4 Vec4::One() {

	return Vec4(1, 1, 1, 1);

}

 Vec4 Vec4::UnitX() {

	return Vec4(1, 0, 0, 0);

}

 Vec4 Vec4::UnitY() {

	return Vec4(0, 1, 0, 0);

}

 Vec4 Vec4::UnitZ() {

	return Vec4(0, 0, 1, 0);

}

 Vec4 Vec4::UnitW() {

	return Vec4(0, 0, 0, 1);

}

