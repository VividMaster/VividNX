#pragma once

#include "stdafx.h"

using namespace std;

class MaterialBase;


class MeshData
{
public:
	MeshData();
	MeshData(int tris);
	void SetTri(Triangle * tri, int index);
	~MeshData();
	Triangle * GetTri(int index);
	vector<Triangle *> GetTris();
	void SetMaterial(MaterialBase * mat);
	MaterialBase * GetMaterial();
private:

	std::vector<Triangle *> Tris;
	MaterialBase * Material;

};

