#include "stdafx.h"
#include "MeshData.h"


MeshData::MeshData()
{
}

MeshData::MeshData(int tris) {

	Tris.resize(tris);

}

void MeshData::SetTri(Triangle * tri, int index) {

	Tris[index] = tri;

}

Triangle * MeshData::GetTri(int index) {

	return Tris[index];

}

vector<Triangle *> MeshData::GetTris() {

	return Tris;

}

MeshData::~MeshData()
{
}

void MeshData::SetMaterial(MaterialBase * mat) {

	this->Material = mat;

}

MaterialBase * MeshData::GetMaterial() {

	return Material;

}