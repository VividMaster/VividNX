#pragma once

#include "stdafx.h"

using namespace std;

class MaterialBase;


class MeshData
{
public:
	MeshData();
	MeshData(int indices,int verts);
	void SetTri(Triangle * tri, int index);
	void SetVertices(float * vertices);
	void SetIndices(int * indices);
	float * GetVertices();
	int * GetIndices();
	~MeshData();
	Triangle * GetTri(int index);
	vector<Triangle *> GetTris();
	void SetMaterial(MaterialBase * mat);
	MaterialBase * GetMaterial();
	void SetGL(int index, GLuint id);
	GLuint GetGL(int index);
	int GetVertexCount();
	int GetIndexCount();
private:

	std::vector<Triangle *> Tris;
	float * Vertices;
	int * Indices;
	int NumIndices = 0;
	int NumVertices = 0;
	MaterialBase * Material;
	GLuint GL[64];
	int GLC = 0;
};

