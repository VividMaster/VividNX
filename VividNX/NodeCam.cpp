#include "stdafx.h"
#include "NodeCam.h"


NodeCam::NodeCam()
{
}


NodeCam::~NodeCam()
{
}

glm::mat4 NodeCam::GetWorldMat() {

	glm::mat4 w = SceneNode::GetWorldMat();

	w = glm::inverse(w);

	return w;

}
