#pragma once

#include "stdafx.h"


using namespace std;

class Effect;
class FXMP;

class MaterialBase
{
public:
	MaterialBase();
	~MaterialBase();
	virtual void Init();
	virtual void Bind();
	virtual void Release();
	Effect * GetFX();
	void SetFX(Effect * fx);
private:
	Effect * FX;

};

