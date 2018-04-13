#pragma once
#include "stdafx.h"

using namespace std;
class NodeCam : public SceneNode
{
public:
	NodeCam();
	~NodeCam();
	glm::mat4 GetWorldMat() override;

private:
};

