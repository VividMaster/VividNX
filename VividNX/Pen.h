#pragma once
#include "stdafx.h"

using namespace std;


class Pen
{
public:
	Pen();
	~Pen();
	void Rect(int x, int y, int w, int h, glm::vec4 col);
	void SetProj();
};

