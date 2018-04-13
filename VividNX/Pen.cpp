#include "stdafx.h"
#include "Pen.h"


Pen::Pen()
{
}


Pen::~Pen()
{
}

void Pen::Rect(int x, int y, int w, int h, glm::vec4 col)
{
	SetProj();
	glColor4f(col.x, col.y, col.z, col.a);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glVertex2f(x, y);

	glVertex2f(x + w, y);

	glVertex2f(x + w, y + h);

	glVertex2f(x, y + h);

	glEnd();

	glFlush();

}

void Pen::SetProj() {

	int w = Global::W;
	int h = Global::H;

	

	glViewport(0, 0, w, h);

	glm::mat4 proj = glm::orthoRH(0.0f, (float)w, (float)h, 0.0f,-1.0f,1.0f);//;glm::orthoLH(0, w, h, 0, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLoadMatrixf(glm::value_ptr(proj));





}