#include "stdafx.h"
#include "SceneGraph.h"


SceneGraph::SceneGraph()
{
	RootNode = new SceneNode();
}


SceneGraph::~SceneGraph()
{
}

void SceneGraph::SetRoot(SceneNode* root) {

	RootNode = root;

}

SceneNode * SceneGraph::GetRoot() {

	return RootNode;

}

void SceneGraph::AddCam(NodeCam * cam)
{

	Cams.push_back(cam);

}

std::vector<NodeCam *> SceneGraph::GetCams() {

	return Cams;

}

std::vector<NodeLight *> SceneGraph::GetLights() {

	return  Lights;

}

void SceneGraph::AddLight(NodeLight * light) {

	Lights.push_back(light);

}
