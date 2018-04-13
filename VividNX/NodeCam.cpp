#include "stdafx.h"
#include "NodeCam.h"


NodeCam::NodeCam()
{
	X = Y = 0;
	W = Global::W;
	H = Global::H;
	NearZ = 0.1f;
	FarZ = 1000.0f;
	FOV = 45.0f;

}


NodeCam::~NodeCam()
{
}

glm::mat4 NodeCam::GetWorldMat() {

	glm::mat4 w = SceneNode::GetWorldMat();

	w = glm::inverse(w);

	return w;

}

int NodeCam::GetX() {

	return X;

}

int NodeCam::GetY() {

	return Y;

}

int NodeCam::GetW() {

	return W;

}

int NodeCam::GetH() {

	return H;

}

float NodeCam::GetNearZ() {

	return NearZ;
}

float NodeCam::GetFarZ() {

	return FarZ;

}

float NodeCam::GetFOV() {

	return FOV;

}

void NodeCam::SetView(int x, int y, int w, int h)
{

	X = x; Y = y; W = w; H = h;

}

void NodeCam::SetDepth(float nz, float fz) {

	NearZ = nz;
	FarZ = fz;

}

void NodeCam::SetFOV(float fov) {

	FOV = fov;

}