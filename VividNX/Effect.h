#pragma once


#include "stdafx.h"


using namespace std;

class Effect
{
public:
	Effect();
	~Effect();
	virtual void Init();
	virtual void Bind();
	virtual void Release();
	void LoadVertex(string vert);
	void LoadFrag(string frag);
	void LoadGeo(string geo);
	void Final();
	void CheckStatus();

	int GetUniLoc(string name);
	void SetMat(int loc, glm::mat4 v);
	void SetInt(int loc, int v);
	void SetFloat(int loc, float v);
	void SetVec2(int loc, glm::vec2 v);
	void SetVec3(int loc, glm::vec3 v);
	void SetVec4(int loc, glm::vec4 v);
	void SetTex(int loc, int v);
	void SetBool(int loc, bool v);


private:
	int Vertex, Frag, Geo;
	int Program;
};

struct StringHelper {
	const char *p;
	StringHelper(const std::string& s) : p(s.c_str()) {}
	operator const char**() { return &p; }
};
