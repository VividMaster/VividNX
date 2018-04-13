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
void CheckProgram(int program) {

	int res = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &res);
	if (res != GL_TRUE) {

		cout << "Program failed to link properly." << endl;

	}

	int infoL = 0;
	int charsW = 0;
	char * infoLog;

	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoL);
	if (infoL > 0) {

		cout << "errLen:" << infoL << endl;
		infoLog = (char *)malloc(infoL);
		glGetProgramInfoLog(program, infoL, &charsW, infoLog);
		printf(infoLog);
		free(infoLog);

	}

}
void CheckShader(int shader) {
	int cs = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &cs);

	if (cs != GL_TRUE) {

		cout << "Shader compile failed." << endl;

	}

	int infoL = 0;
	int charsW = 0;
	char * infoLog;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoL);
	if (infoL > 0) {
		cout << "ErrLen:" << infoL << endl;
		infoLog = (char *)malloc(infoL);
		glGetShaderInfoLog(shader, infoL, &charsW, infoLog);
		printf(infoLog);
		free(infoLog);

	}
	else {

		cout << "No Shader info log." << endl;

	}


}

void Effect::CheckStatus() {

	//cout << "Checking VertexShader." << endl;
	CheckShader(Vertex);
	//cout << "Checking FragmentShader." << endl;
	CheckShader(Frag);

}

void Effect::LoadVertex(string path) {

	TextLoad * t1 = new TextLoad(path);
	string code = t1->Text;
	//cout << "VertCode:" << endl << code << endl;
	const char * cs = code.c_str();
	Vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(Vertex, 1, StringHelper(code), nullptr);
	glCompileShader(Vertex);


	
}

void Effect::LoadFrag(string path) {

	TextLoad * t1 = new TextLoad(path);
	string code = t1->Text;

	const char * cs = code.c_str();
	Frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(Frag, 1, StringHelper(code), nullptr);
	glCompileShader(Frag);

}

void Effect::Final() {

	Program = glCreateProgram();
	if (Vertex != 0) {
		glAttachShader(Program, Vertex);
	}
	if (Frag != 0) {
		glAttachShader(Program, Frag);
	}
	
	glLinkProgram(Program);

	CheckProgram(Program);

}