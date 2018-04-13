#include "stdafx.h"
#include "RendererMultiPass.h"


RendererMultiPass::RendererMultiPass()
{
}


RendererMultiPass::~RendererMultiPass()
{
}

void SyncMesh(MeshData * mesh, Node3D * node) {


	GLuint va;

	glGenVertexArrays(1, &va);

	mesh->SetGL(0, va);

	glBindVertexArray(va);

	GLuint vbo;

	glGenBuffers(1, &vbo);

	mesh->SetGL(1, vbo);

	float * verts = mesh->GetVertices();

	int vc = mesh->GetVertexCount();

//	float *data = new float[mesh->]

	int s = 0;

	GLvoid * os = &s;

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, vc * 3 * 3 * 3 * 3 * 3 * 4, verts, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * 3 * 3 * 3 * 3 * 4, os);

	glEnableVertexAttribArray(1);

	s = 3 * 4;

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * 3 * 3 * 3 * 3 * 4, os);

	glEnableVertexAttribArray(2);

	s = 6 * 4;

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * 3 * 3 * 3 * 3 * 4, os);

	glEnableVertexAttribArray(3);

	s = 9 * 4;

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 3 * 3 * 3 * 3 * 3 * 4, os);

	glEnableVertexAttribArray(4);

	s = 12 * 4;

	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 3 * 3 * 3 * 3 * 3 * 4, os);

	glBindVertexArray(0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(3);
	glDisableVertexAttribArray(4);

	GLuint eb;

	glGenBuffers(1, &eb);

	mesh->SetGL(2, eb);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb);

	int * in = mesh->GetIndices();

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->GetIndexCount() * 4, in, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	cout << "Synced:" << endl << " va:" << va << endl;


}

void RendererMultiPass::Bind() {

	//cout << "Binding" << endl;//
	

}

void RendererMultiPass::Release() {

//	cout << "Releasing" << endl;

}

void SyncNode(SceneNode * node) {


	if (dynamic_cast<Node3D *>(node) != nullptr) {
		Node3D* re = (Node3D *)node;

		if (re != nullptr) {

			vector<MeshData *> meshes = re->GetMeshes();

			for (int m = 0; m < meshes.size(); m++) {

				MeshData * md = meshes[m];

				//vector<NodeCam *> cams = this->GetGraph()->GetCams();

			
					SyncMesh(md, re);
				
			}


		}
	}
	vector<SceneNode*> nodes = node->GetNodes();
	for (int i = 0; i < nodes.size(); i++) {

		SyncNode(nodes[i]);

	}
}

void RendererMultiPass::Sync() {

	SyncNode(this->GetGraph()->GetRoot());

}

void RenderNode2(Node3D * node,NodeCam * cam) {

	Node3D * n3 = (Node3D*)node;

	vector<MeshData *> meshes = n3->GetMeshes();

	for (int i = 0; i < meshes.size(); i++)
	{

		MeshData * m = meshes[i];

		GLuint va = m->GetGL(0);
		GLuint eb = m->GetGL(2);

		glBindVertexArray(va);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glEnableVertexAttribArray(3);
		glEnableVertexAttribArray(4);


		glm::mat4 mvp = cam->GetWorldMat();

		glm::mat4 mm = node->GetWorldMat();

		mm = mvp * mm;

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(glm::value_ptr(mm));
		glMatrixMode(GL_PROJECTION);

		glm::mat4 pm = glm::perspectiveFov(cam->GetFOV(), (float)cam->GetW(), (float)cam->GetH(), cam->GetNearZ(), cam->GetFarZ());

		glLoadMatrixf(glm::value_ptr(pm));

		glDrawElements(GL_TRIANGLES, m->GetIndexCount(), GL_INT, nullptr);
		

		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	vector<SceneNode *> nodes = n3->GetNodes();
	
	for (int i = 0; i < nodes.size(); i++) {

	

		RenderNode2((Node3D*)nodes[i],cam);

	}

}

void RendererMultiPass::RenderNode(SceneNode * node) {

	NodeCam * c1 = GetGraph()->GetCams()[0];

	RenderNode2((Node3D*)node,c1);
	
}

void RendererMultiPass::BindNode(SceneNode * node) {

}

void RendererMultiPass::ReleaseNode(SceneNode * node) {


}