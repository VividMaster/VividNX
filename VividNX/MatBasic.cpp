#include "stdafx.h"
#include "MatBasic.h"


MatBasic::MatBasic()
{
	Diffuse = nullptr;
	Normal = nullptr;
	Spec = nullptr;
	Color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	SetFX(new FXMP());

}


MatBasic::~MatBasic()
{
}

void MatBasic::Init() {

}

void MatBasic::Bind() {

}

void MatBasic::Release() {


}

bool MatBasic::HasDiffuse() {

	if (Diffuse != nullptr) return true;
	return false;

}

bool MatBasic::HasNormal() {

	if (Normal != nullptr) return true;
	return false;

}

bool MatBasic::HasSpec() {

	if (Spec != nullptr) return true;
	return false;

}


void MatBasic::SetDiffuse(Texture2D * tex)
{

	Diffuse = tex;

}

void MatBasic::SetNormal(Texture2D * tex) {

	Normal = tex;

}

void MatBasic::SetSpec(Texture2D * tex) {

	Spec = tex;

}
