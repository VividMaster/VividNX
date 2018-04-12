#pragma once

#include "stdafx.h"

using namespace std;

#include "Vec4.h"

struct Mat4 {
public:

	Vec4 Row0, Row1, Row2, Row3;

	Mat4() {

	}
	Mat4(Vec4 r0, Vec4 r1, Vec4 r2, Vec4 r3);
	Mat4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33);
	
	float GetDeterminant();

	Vec4 GetCol0();
	Vec4 GetCol1();
	Vec4 GetCol2();
	Vec4 GetCol3();
	void SetCol0(Vec4 c);
	void SetCol1(Vec4 c);
	void SetCol2(Vec4 c);
	void SetCol3(Vec4 c);
	float GetM11();
	float GetM12();
	float GetM13();
	float GetM14();
	float GetM21();
	float GetM22();
	float GetM23();
	float GetM24();
	float GetM31();
	float GetM32();
	float GetM33();
	float GetM34();
	float GetM41();
	float GetM42();
	float GetM43();
	float GetM44();

	static Mat4 Identity();
	static Mat4 Zero();



};

