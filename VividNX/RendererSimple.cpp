#include "stdafx.h"
#include "RendererSimple.h"

void RenderMesh(MeshData * mesh, Node3D * node, NodeCam * cam);

RendererSimple::RendererSimple()
{
}


RendererSimple::~RendererSimple()
{
}

void RendererSimple::Sync() {

}

void RendererSimple::RenderNode(SceneNode * node) {


	if (dynamic_cast<Node3D *>(node) != nullptr) {
		Node3D* re = (Node3D *)node;

		if (re != nullptr) {

			vector<MeshData *> meshes = re->GetMeshes();
			
			for (int m = 0; m < meshes.size(); m++) {

				MeshData * md = meshes[m];

				vector<NodeCam *> cams = this->GetGraph()->GetCams();
				
				for (int c = 0; c < cams.size(); c++) {

					NodeCam * cam = cams[c];

					RenderMesh(md, re, cam);
				}

			}

			
		}
	}
	vector<SceneNode*> nodes = node->GetNodes();
	for (int i = 0; i < nodes.size(); i++) {

		RenderNode(nodes[i]);

	}
	
}

void RenderVert(Vertex  v);

void RenderMesh(MeshData * mesh, Node3D * node, NodeCam * cam) {

	vector<Triangle *> tris = mesh->GetTris();


	glm::mat4 mvp = cam->GetWorldMat();

	glm::mat4 mm = node->GetWorldMat();

	mm = mvp * mm;

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(glm::value_ptr(mm));
	glMatrixMode(GL_PROJECTION);

	glm::mat4 pm = glm::perspectiveFov(cam->GetFOV(), (float)cam->GetW(), (float)cam->GetH(), cam->GetNearZ(), cam->GetFarZ());

	glLoadMatrixf(glm::value_ptr(pm));

	MaterialBase * mat = mesh->GetMaterial();

	if (mat != nullptr) {

		mat->Bind();

	}

	glBegin(GL_TRIANGLES);

	for (int t = 0; t < tris.size(); t++) {

		Triangle * tri = tris[t];

		RenderVert(tri->V0);
		RenderVert(tri->V1);
		RenderVert(tri->V2);



	}

	glEnd();

	
	if (mat != nullptr) {

		mat->Release();

	}

}

void RenderVert(Vertex  v) {

	glTexCoord3f(v.U, v.V, v.W);
///	glNormal3f(v.NX, v.NY.v.NZ);
	glNormal3f(v.NX, v.NY, v.NZ);
	glVertex3f(v.X, v.Y, v.Z);

}