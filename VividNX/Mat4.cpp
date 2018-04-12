#pragma once

#include "stdafx.h"



 Mat4::Mat4(Vec4 r0, Vec4 r1, Vec4 r2, Vec4 r3) {

	Row0 = r0; Row1 = r1; Row2 = r2; Row3 = r3;

}

 Mat4::Mat4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
{
	Row0 = Vec4(m00, m01, m02, m03);
	Row1 = Vec4(m10, m11, m12, m13);
	Row2 = Vec4(m20, m21, m22, m23);
	Row3 = Vec4(m30, m31, m32, m33);
}

 float Mat4::GetDeterminant() {

	float m11 = Row0.X, m12 = Row0.Y, m13 = Row0.Z, m14 = Row0.W,
		m21 = Row1.X, m22 = Row1.Y, m23 = Row1.Z, m24 = Row1.W,
		m31 = Row2.X, m32 = Row2.Y, m33 = Row2.Z, m34 = Row2.W,
		m41 = Row3.X, m42 = Row3.Y, m43 = Row3.Z, m44 = Row3.W;

	return
		m11 * m22 * m33 * m44 - m11 * m22 * m34 * m43 + m11 * m23 * m34 * m42 - m11 * m23 * m32 * m44
		+ m11 * m24 * m32 * m43 - m11 * m24 * m33 * m42 - m12 * m23 * m34 * m41 + m12 * m23 * m31 * m44
		- m12 * m24 * m31 * m43 + m12 * m24 * m33 * m41 - m12 * m21 * m33 * m44 + m12 * m21 * m34 * m43
		+ m13 * m24 * m31 * m42 - m13 * m24 * m32 * m41 + m13 * m21 * m32 * m44 - m13 * m21 * m34 * m42
		+ m13 * m22 * m34 * m41 - m13 * m22 * m31 * m44 - m14 * m21 * m32 * m43 + m14 * m21 * m33 * m42
		- m14 * m22 * m33 * m41 + m14 * m22 * m31 * m43 - m14 * m23 * m31 * m42 + m14 * m23 * m32 * m41;

}

 Vec4 Mat4::GetCol0() {

	return Vec4(Row0.X, Row1.X, Row1.X, Row2.X);

}

 Vec4 Mat4::GetCol1() {

	return Vec4(Row0.Y, Row1.Y, Row2.Y, Row3.Y);

}

 Vec4 Mat4::GetCol2() {

	return Vec4(Row0.Z, Row1.Z, Row2.Z, Row3.Z);

}

 Vec4 Mat4::GetCol3() {

	return Vec4(Row0.W, Row1.W, Row2.W, Row3.W);

}

 void Mat4::SetCol0(Vec4 c) {

	Row0.X = c.X;
	Row1.X = c.Y;
	Row2.X = c.Z;
	Row3.X = c.W;

}

 void Mat4::SetCol1(Vec4 c)
{

	Row0.Y = c.X;
	Row1.Y = c.Y;
	Row2.Y = c.Z;
	Row3.Y = c.W;

}

 void Mat4::SetCol2(Vec4 c)
{

	Row0.Z = c.X;
	Row1.Z = c.Y;
	Row2.Z = c.Z;
	Row3.Z = c.W;

}

 void Mat4::SetCol3(Vec4 c) {

	Row0.W = c.X;
	Row1.W = c.Y;
	Row2.W = c.Z;
	Row3.W = c.W;

}

 float Mat4::GetM11() {

	return Row0.X;

}

 float Mat4::GetM12() {

	return Row0.Y;

}

 float Mat4::GetM13() {

	return Row0.Z;

}

 float Mat4::GetM14() {

	return Row0.W;

}

 float Mat4::GetM21() {

	return Row1.X;

}

 float Mat4::GetM22() {

	return Row1.Y;

}

 float Mat4::GetM23() {

	return Row1.Z;

}

 float Mat4::GetM24() {

	return Row1.W;

}

 float Mat4::GetM31() {

	return Row2.X;

}

 float Mat4::GetM32() {

	return Row2.Y;

}

 float Mat4::GetM33() {

	return Row2.Z;

}

 float Mat4::GetM34() {

	return Row2.W;

}

 float Mat4::GetM41() {

	return Row3.X;

}

 float Mat4::GetM42() {

	return Row3.Y;

}

 float Mat4::GetM43() {

	return Row3.Z;

}

 float Mat4::GetM44() {

	return Row3.W;

}



 Mat4 Mat4::Identity() {

	return Mat4(Vec4::UnitX(), Vec4::UnitY(), Vec4::UnitZ(), Vec4::UnitW());

}

 Mat4 Mat4::Zero() {

	return Mat4(Vec4::Zero(), Vec4::Zero(), Vec4::Zero(), Vec4::Zero());

}