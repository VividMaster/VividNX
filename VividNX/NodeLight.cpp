#include "stdafx.h"
#include "NodeLight.h"


NodeLight::NodeLight()
{

	Diffuse = glm::vec3(0.7f, 0.2f, 0.2f);
	Specular = glm::vec3(0.7f, 0.2f, 0.2f);

}


NodeLight::~NodeLight()
{
}
