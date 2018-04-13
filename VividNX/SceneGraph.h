#pragma once

#include "stdafx.h"

using namespace std;
class SceneNode;
class NodeCam;
class NodeLight;

class SceneGraph

{
public:
	SceneGraph();
	~SceneGraph();
	void SetRoot(SceneNode* node);
	SceneNode * GetRoot();
	void AddCam(NodeCam* cam);
	void AddLight(NodeLight * light);
	std::vector<NodeCam *> GetCams();
	std::vector<NodeLight *> GetLights();
private:
	std::vector<NodeCam *> Cams;
	std::vector<NodeLight *> Lights;
	SceneNode* RootNode;
};

