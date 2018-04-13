#include "stdafx.h"
#include "TextureBase.h"


TextureBase::TextureBase()
{
}


TextureBase::~TextureBase()
{
}

int TextureBase::GetID() {

	return GLID;

}

void TextureBase::SetID(GLuint id) {

	GLID = id;

}

void TextureBase::Bind(int unit) {

}

void TextureBase::Release(int unit) {


}

void TextureBase::SetSize(int w, int h)
{

	W = w;
	H = h;

}

int TextureBase::GetW() {

	return W;

}

int TextureBase::GetH() {

	return H;

}