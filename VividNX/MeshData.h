#pragma once

#include "stdafx.h"

using namespace std;

class MeshData
{
public:
	MeshData();
	MeshData(int tris);
	void SetTri(Triangle * tri, int index);
	~MeshData();
	Triangle * GetTri(int index);
	vector<Triangle *> GetTris();

private:

	std::vector<Triangle *> Tris;

};

