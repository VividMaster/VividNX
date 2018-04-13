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
	void SetName(string name);
	string GetName();
	virtual glm::mat4 GetWorldMat();
	std::vector<SceneNode *> GetNodes();
	void SetPosition(glm::vec3 pos);
	void SetPosition(float x, float y, float z);
	void SetRotate(float x, float y, float z);


private:
	std::vector<SceneNode *> Nodes;
	SceneNode * Root = nullptr;
	string Name;
	glm::mat4 Rotation;
	glm::vec3 Position;
	glm::vec3 Scale;
};

