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
	void Final();
	void CheckStatus();
private:
	int Vertex, Frag, Geo;
	int Program;
};

struct StringHelper {
	const char *p;
	StringHelper(const std::string& s) : p(s.c_str()) {}
	operator const char**() { return &p; }
};
