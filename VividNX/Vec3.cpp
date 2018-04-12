#pragma once

#include "stdafx.h"



 Vec3::Vec3(float x, float y, float z)
{

	X = x; Y = y; Z = z;

}

 Vec3 Vec3::Zero() {

	return Vec3(0, 0, 0);

}
 Vec3 Vec3::One() {

	return Vec3(1, 1, 1);

}