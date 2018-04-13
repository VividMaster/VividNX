#include "stdafx.h"
#include "MaterialBase.h"


MaterialBase::MaterialBase()
{
}


MaterialBase::~MaterialBase()
{
}

void MaterialBase::Init() {


}

void MaterialBase::Bind() {

}

void MaterialBase::Release() {


}

void MaterialBase::SetFX(Effect * fx) {

	FX = fx;

}

Effect * MaterialBase::GetFX() {

	return FX;

}