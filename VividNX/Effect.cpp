#include "stdafx.h"
#include "Effect.h"


Effect::Effect()
{
	Vertex = Frag = Geo = 0;
	Init();
}


Effect::~Effect()
{
}

void Effect::Init() {

}

void Effect::CheckStatus() {

	GLchar * log = new GLchar[50000];
	int logl = 0;
	
	glGetShaderInfoLog(Vertex, 5000, &logl, log);
	log[logl] = 0;
	string nt = string(log);
	cout << "GLSL Status:" << nt;
}

void Effect::LoadVertex(string path) {

	TextLoad * t1 = new TextLoad(path);
	string code = t1->Text;
	const char * cs = code.c_str();
	Vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(Vertex, 1, &cs, nullptr);
	glCompileShader(Vertex);


	
}

void Effect::LoadFrag(string path) {

	TextLoad * t1 = new TextLoad(path);
	string code = t1->Text;
	const char * cs = code.c_str();
	Vertex = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(Vertex, 1, &cs, nullptr);
	glCompileShader(Frag);

}