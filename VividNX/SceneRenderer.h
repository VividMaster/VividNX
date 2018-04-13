#pragma once

#include "stdafx.h"

using namespace std;



class SceneRenderer
{
public:
	SceneRenderer();
	~SceneRenderer();
	void SetGraph(SceneGraph * graph);
	SceneGraph * GetGraph();
	virtual void Sync();
	virtual void RenderNode(SceneNode * node);
	virtual void RenderScene();
private:
	SceneGraph * Graph;

};

