#include "stdafx.h"
#include "Texture2D.h"


Texture2D::Texture2D()
{
}


Texture2D::~Texture2D()
{
}

Texture2D::Texture2D(string path) {

	ILuint id = 0;
	ilGenImages(1, &id);
	ilBindImage(id);
	ilLoadImage((const wchar_t *)path.c_str());

	int w = ilGetInteger(IL_IMAGE_WIDTH);
	int h = ilGetInteger(IL_IMAGE_HEIGHT);
	GLubyte *pix = new GLubyte[w*h * 3];
	ilCopyPixels(0, 0, 0, w, h, 1, IL_RGB, IL_UNSIGNED_BYTE, pix);
	ilBindImage(0);
	ilDeleteImage(id);

	cout << "TexLoaded. W:" << w << " H:" << h << endl;

	GLuint texid = 0;

	glGenTextures(1, &texid);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texid);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, pix);

	SetID(texid);
	SetSize(w, h);

}

void Texture2D::Bind(int unit) {

	glActiveTexture(GL_TEXTURE0 + unit);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->GetID());

}

void Texture2D::Release(int unit) {

	glActiveTexture(GL_TEXTURE0 + unit);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}