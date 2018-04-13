#include "stdafx.h"
#include "Node3D.h"


Node3D::Node3D()
{
}


Node3D::~Node3D()
{
}

void Node3D::AddMesh(MeshData * mesh) {

	Meshes.push_back(mesh);

}

std::vector<MeshData *> Node3D::GetMeshes() {

	return Meshes;

}

void SetMat(Node3D * node, MaterialBase * mat);

void Node3D::SetMaterial(MaterialBase * mat) {

	SetMat(this, mat);

}

void SetMat(Node3D * node, MaterialBase * mat) {

	vector<MeshData *> meshes = node->GetMeshes();

	for (int i = 0; i < meshes.size(); i++) {

		meshes[i]->SetMaterial(mat);

	}

	vector<SceneNode *> nodes = node->GetNodes();

	for (int i = 0; i < nodes.size(); i++) {

		Node3D * nn = (Node3D *)nodes[i];
		SetMat(nn, mat);

	}

}