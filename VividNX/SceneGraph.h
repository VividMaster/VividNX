#pragma once

#include "stdafx.h"

using namespace std;
class SceneNode;

class SceneGraph

{
public:
	SceneGraph();
	~SceneGraph();
	void SetRoot(SceneNode* node);
private:
	SceneNode* RootNode;
};

