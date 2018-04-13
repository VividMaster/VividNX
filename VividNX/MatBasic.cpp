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
