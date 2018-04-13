#pragma once


#include "stdafx.h"


using namespace std;

class Effect
{
public:
	Effect();
	~Effect();
	virtual void Init();
	void LoadVertex(string vert);
	void LoadFrag(string frag);
	void LoadGeo(string geo);
	void CheckStatus();
private:
	int Vertex, Frag, Geo;
};

