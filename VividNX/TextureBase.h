#pragma once

#include "stdafx.h"


using namespace std;

class TextureBase
{
public:
	TextureBase();
	~TextureBase();

	int GetID();
	void SetID(GLuint id);
	void SetSize(int w, int h);
	int GetW();
	int GetH();
	virtual void Bind(int unit);
	virtual void Release(int unit);

private:

	int W, H;
	string Path;
	GLuint GLID;

};

