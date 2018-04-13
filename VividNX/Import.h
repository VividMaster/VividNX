#pragma once
#include "stdafx.h"

using namespace std;
class Import
{
public:
	Import();
	~Import();
	Node3D* ImportAssImp(string path);
	void ParseNode(struct aiNode * node, Node3D * n3,std::vector<MeshData *> meshes);
};

