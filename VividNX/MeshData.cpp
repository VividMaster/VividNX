#include "stdafx.h"
#include "MeshData.h"


MeshData::MeshData()
{


}

MeshData::MeshData(int indices,int verts) {

	//Tris.resize(tris);

	//Vertices = new float[verts * 3 * 3 * 3 * 3 * 3];
	NumIndices = indices;

	NumVertices = verts;

}

int MeshData::GetVertexCount() {

	return NumVertices;

}

int MeshData::GetIndexCount() {

	return NumIndices;

}

void MeshData::SetVertices(float * vertices) {

	this->Vertices = vertices;

}

void MeshData::SetIndices(int * indices) {

	Indices = indices;

}

float * MeshData::GetVertices() {

	return Vertices;

}

int * MeshData::GetIndices() {

	return Indices;

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

void MeshData::SetGL(int index, GLuint id) {

	GL[index] = id;
	GLC++;

}

GLuint MeshData::GetGL(int index) {

	return GL[index];

}
