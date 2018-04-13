#pragma once

#include "stdafx.h"


using namespace std;

class NodeCam;
class SceneNode;
class MatBasic;

void SetUp(FXMP *f);

class FXMP :
	public Effect
{
public:
	FXMP();
	~FXMP();
	void Init() ;
	void Bind();
	void Release();
	NodeCam * Cam;
	SceneNode *Node;
	MatBasic * Mat;
	NodeLight * Light;
	int lCam, lModel, lProj;
	int lDT, lNT, lET;
	int dB, nB, eB;
	int lLP, lLC;
	int lAtten;
	int lAmb;
	int lMatS;
	int lMatSpec;
	int lEnvS;
	int lCamP;
};


