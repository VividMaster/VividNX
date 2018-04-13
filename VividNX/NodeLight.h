#pragma once
#include "stdafx.h"


using namespace std;

class NodeLight :
	public SceneNode
{
public:
	NodeLight();
	~NodeLight();
	 glm::vec3 Diffuse;
	 glm::vec3 Specular;
	 float Shine = 0.3f;
	 float Atten = 0.2f;
};

