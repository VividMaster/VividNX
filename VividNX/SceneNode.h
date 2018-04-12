#pragma once

#include "stdafx.h"

using namespace std;

class SceneNode
{
public:
	SceneNode();
	~SceneNode();
	void Add(SceneNode * node);
	SceneNode * GetRoot();
	void SetRoot(SceneNode * root);
	void Remove(SceneNode * node);
private:
	std::list<SceneNode *> Nodes;
	SceneNode * Root = nullptr;
};

