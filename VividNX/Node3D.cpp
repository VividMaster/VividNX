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