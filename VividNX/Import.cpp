#include "stdafx.h"
#include "Import.h"


Import::Import()
{
}


Import::~Import()
{
}

Node3D * Import::ImportAssImp(string path) {

	Node3D * root = new Node3D();

	Assimp::Importer imp;

	const aiScene* ai =imp.ReadFile(path, aiProcessPreset_TargetRealtime_MaxQuality | aiProcess_CalcTangentSpace | aiProcess_GenSmoothNormals | aiProcess_OptimizeGraph | aiProcess_OptimizeMeshes | aiProcess_Triangulate);
	if (!ai) {

		cout << "could not load model:" << path << endl;
		while (true) {

		}

	}

	//const struct aiScene	* ai = aiImportFile(path.c_str(), aiProcessPreset_TargetRealtime_MaxQuality);

	struct aiNode * ar = ai->mRootNode;

	std::vector<MeshData *> meshes;

	meshes.resize(ai->mNumMeshes);

	for (int i = 0; i < ai->mNumMeshes; i++) {

		aiMesh * msh = ai->mMeshes[i];
		MeshData * dat = new MeshData(msh->mNumFaces);
		meshes[i] = dat;

		std::vector<Vertex> verts;

		verts.resize(msh->mNumVertices);

		for (int k = 0; k < msh->mNumVertices; k++)
		{
			aiVector3D v = msh->mVertices[k];

			Vertex nv;
			nv.X = v.x;
			nv.Y = v.y;
			nv.Z = v.z;


			if (msh->HasNormals()) {
			
				aiVector3D n = msh->mNormals[k];

				nv.NX = n.x;
				nv.NY = n.y;
				nv.NZ = n.z;

			}


			if (msh->HasTextureCoords(0)) {

				aiVector3D u = msh->mTextureCoords[0][k];

				nv.U = u.x;
				nv.V = u.y;
				nv.W = u.z;


			}

			verts[k] = nv;

		}

		for (int i = 0; i < msh->mNumFaces; i++) {



			Triangle * tri = new Triangle();

			aiFace f = msh->mFaces[i];

			tri->V0 = verts[(int)f.mIndices[0]];
			tri->V1 = verts[(int)f.mIndices[1]];
			tri->V2 = verts[(int)f.mIndices[2]];
				
			dat->SetTri(tri, i);

		}

	}

	ParseNode(ar, root,meshes);


	return root;

}

void Import::ParseNode(struct aiNode * an, Node3D * vn,std::vector<MeshData *> meshes)
{

	int mc = an->mNumMeshes;
	vn->SetName(an->mName.C_Str());
	cout << "Node:" << an->mName.C_Str() << " Has " << an->mNumChildren << " Children " << endl;
	cout << "Meshes:" << an->mNumMeshes << endl;
	for (int i = 0; i < mc; i++) {

		MeshData * md = meshes[(int)an->mMeshes[i]];
		vn->AddMesh(md);

	}

	for (int i = 0; i < an->mNumChildren; i++) {

		Node3D * nn = new Node3D();
		vn->Add(nn);
		ParseNode(an->mChildren[i], nn, meshes);

	}



}
