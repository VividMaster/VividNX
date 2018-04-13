#pragma once
#include "stdafx.h"

using namespace std;

class MeshData;
class MaterialBase;

class Node3D : public SceneNode
{
public:
	Node3D();
	~Node3D();
	void AddMesh(MeshData * mesh);
	std::vector<MeshData *> GetMeshes();
	void SetMaterial(MaterialBase * mat);

private:
	std::vector<MeshData *> Meshes;

};

