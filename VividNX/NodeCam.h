#pragma once
#include "stdafx.h"

using namespace std;
class NodeCam : public SceneNode
{
public:
	NodeCam();
	~NodeCam();
	glm::mat4 GetWorldMat() override;
	int GetX();
	int GetY();
	int GetW();
	int GetH();
	float GetNearZ();
	float GetFarZ();
	float GetFOV();

	void SetView(int x, int y, int w, int h);
	void SetDepth(float nz, float fz);
	void SetFOV(float fov);

private:
	int X, Y, W, H;
	float NearZ=0.1f, FarZ=1000.f;
	float FOV = 45.0f;
};

