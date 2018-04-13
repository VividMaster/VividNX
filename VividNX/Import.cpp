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
		MeshData * dat = new MeshData(msh->mNumFaces*3,msh->mNumVertices);
		meshes[i] = dat;

		std::vector<Vertex> verts;

		verts.resize(msh->mNumVertices);

		float * va = new float[msh->mNumVertices * 3 * 3 * 3 * 3 * 3];
		int vc = 0;
		for (int k = 0; k < msh->mNumVertices; k++)
		{
			aiVector3D v = msh->mVertices[k];

			Vertex nv;
			nv.X = v.x;
			nv.Y = v.y;
			nv.Z = v.z;
			va[vc++] = nv.X;
			va[vc++] = nv.Y;
			va[vc++] = nv.Z;

			if (msh->HasNormals()) {
			
				aiVector3D n = msh->mNormals[k];

				nv.NX = n.x;
				nv.NY = n.y;
				nv.NZ = n.z;
				va[vc++] = n.x;
				va[vc++] = n.y;
				va[vc++] = n.z;

			}
			else {

				va[vc++] = 0;
				va[vc++] = 0;
				va[vc++] = 0;

			}


			if (msh->HasTextureCoords(0)) {

				aiVector3D u = msh->mTextureCoords[0][k];

				nv.U = u.x;
				nv.V = 1.0f-u.y;
				nv.W = u.z;
				va[vc++] = u.x;
				va[vc++] = u.y;
				va[vc++] = u.z;
 
			}
			else {

				va[vc++] = 0;
				va[vc++] = 0;
				va[vc++] = 0;

			}

			if (msh->HasTangentsAndBitangents()) {

				aiVector3D t = msh->mTangents[k];

				va[vc++] = t.x;
				va[vc++] = t.y;
				va[vc++] = t.z;

				aiVector3D b = msh->mBitangents[k];

				va[vc++] = b.x;
				va[vc++] = b.y;
				va[vc++] = b.z;

			}
			else {

				va[vc++] = 0; va[vc++] = 0; va[vc++] = 0;
				va[vc++] = 0; va[vc++] = 0; va[vc++] = 0;

			}

			verts[k] = nv;

		}
		dat->SetVertices(va);
		int * in = new int[msh->mNumFaces * 3];
		int ic = 0;
		for (int i = 0; i < msh->mNumFaces; i++) {

			

			
			aiFace f = msh->mFaces[i];

			in[ic++] = f.mIndices[0];
			in[ic++] = f.mIndices[1];
			in[ic++] = f.mIndices[2];

		

		}
		dat->SetIndices(in);

	}

	ParseNode(ar, root,meshes);


	return root;

}

void Import::ParseNode(struct aiNode * an, Node3D * vn,std::vector<MeshData *> meshes)
{

	int mc = an->mNumMeshes;
	vn->SetName(an->mName.C_Str());
	
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
