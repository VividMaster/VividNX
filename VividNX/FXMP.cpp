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