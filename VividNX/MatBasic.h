#pragma once

#include "stdafx.h"


using namespace std;

class MatBasic : public MaterialBase
{
public:
	MatBasic();
	~MatBasic();
	void Init() ;
	void Bind() ;
	void Release() ;
	void SetDiffuse(Texture2D * tex);
	void SetNormal(Texture2D * tex);
	void SetSpec(Texture2D * tex);
	bool HasDiffuse();
	bool HasNormal();
	bool HasSpec();
private:
	Texture2D * Diffuse;
	Texture2D * Normal;
	Texture2D * Spec;
	glm::vec4 Color;

};

