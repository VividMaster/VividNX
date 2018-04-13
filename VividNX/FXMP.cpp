#include "stdafx.h"
#include "FXMP.h"


FXMP::FXMP()
{
}


FXMP::~FXMP()
{
}

void FXMP::Init() {

	cout << "Loading shaders." << endl;
	LoadVertex("c:\\media\\shade\\MPVert.vertex");
	LoadFrag("c:\\media\\shade\\MPFrag.frag");
	CheckStatus();
	cout << "Loading complete, shaders ready to use." << endl;

}