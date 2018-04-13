#pragma once
#include "stdafx.h"

using namespace std;

class MeshData;

class Node3D : public SceneNode
{
public:
	Node3D();
	~Node3D();
	void AddMesh(MeshData * mesh);
	std::vector<MeshData *> GetMeshes();

private:
	std::vector<MeshData *> Meshes;

};

