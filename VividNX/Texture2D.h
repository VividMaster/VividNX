#pragma once
#include "stdafx.h"


using namespace std;
class Texture2D :
	public TextureBase
{
public:
	Texture2D();
	~Texture2D();
	Texture2D(string path);
	void Bind(int unit) ;
	void Release(int unit) ;
};

