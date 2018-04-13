#pragma once

#include "stdafx.h"

using namespace std;
class SceneNode;
class NodeCam;
class SceneGraph

{
public:
	SceneGraph();
	~SceneGraph();
	void SetRoot(SceneNode* node);
	SceneNode * GetRoot();
	void AddCam(NodeCam* cam);
	std::vector<NodeCam *> GetCams();
private:
	std::vector<NodeCam *> Cams;
	SceneNode* RootNode;
};

