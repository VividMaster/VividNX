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
