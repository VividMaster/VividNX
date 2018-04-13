#include "stdafx.h"
#include "FXMP.h"


FXMP::FXMP()
{
	Init();
}


FXMP::~FXMP()
{
}

void FXMP::Init() {

	cout << "Loading shaders." << endl;
	LoadVertex("c:\\media\\shade\\MPVert.glsl");
	LoadFrag("c:\\media\\shade\\MPFrag.glsl");

	CheckStatus();
	cout << "Loading complete, shaders ready to use." << endl;

	


}

void FXMP::Bind() {

	glm::mat4 pm = glm::perspectiveFov(Cam->GetFOV(), (float)Cam->GetW(), (float)Cam->GetH(), Cam->GetNearZ(), Cam->GetFarZ());

	SetMat(lCam,Cam->GetWorldMat());
	SetMat(lModel, Node->GetWorldMat());
	SetMat(lProj, pm);
	SetVec3(lCamP, Node->GetPosition());
	SetVec3(lLP, Light->GetPosition());
	SetVec3(lLC, Light->Diffuse);
	SetFloat(lAtten, Light->Atten);
	SetFloat(lAmb, 0.3f);
	SetFloat(lMatS, Light->Shine);
	SetVec3(lMatSpec, Light->Specular);
	SetFloat(lEnvS, 0.3f);

	SetTex(lDT, 0);
	SetTex(lNT, 1);
	SetTex(lET, 2);

	SetBool(dB, Mat->HasDiffuse());
	SetBool(nB, Mat->HasNormal());
	SetBool(eB, Mat->HasSpec());


}

void FXMP::Release() {


}

void SetUp(FXMP *f) {

	f->lCam = f->GetUniLoc("cam");
	f->lModel = f->GetUniLoc("model");
	f->lProj = f->GetUniLoc("proj");
	f->lDT = f->GetUniLoc("tC");
	f->lNT = f->GetUniLoc("tN");
	f->lET = f->GetUniLoc("tE");
	f->dB = f->GetUniLoc("eC");
	f->nB = f->GetUniLoc("eN");
	f->eB = f->GetUniLoc("eE");
	f->lLP = f->GetUniLoc("lP");
	f->lLC = f->GetUniLoc("lC");
	f->lAtten = f->GetUniLoc("atten");
	f->lAmb = f->GetUniLoc("ambCE");
	f->lMatS = f->GetUniLoc("matS");
	f->lMatSpec = f->GetUniLoc("matSpec");
	f->lEnvS = f->GetUniLoc("envS");
	f->lCam = f->GetUniLoc("camP");

}