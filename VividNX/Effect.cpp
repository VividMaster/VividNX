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

void Effect::Bind() {


}

void Effect::Release() {


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

int Effect::GetUniLoc(string name) {

	return (int)glGetUniformLocation(Program, name.c_str());


}

void Effect::SetMat(int loc, glm::mat4 v) {

	glUniformMatrix4fv(loc, 16, false, glm::value_ptr(v));
	
}

void Effect::SetInt(int loc, int v) {

	glUniform1i(loc, v);

}

void Effect::SetFloat(int loc, float v) {

	glUniform1f(loc, v);

}

void Effect::SetVec2(int loc, glm::vec2 v) {

	glUniform2f(loc,v.x,v.y);

}

void Effect::SetVec3(int loc, glm::vec3 v) {

	glUniform3f(loc, v.x, v.y, v.z);

}

void Effect::SetVec4(int loc, glm::vec4 v) {

	glUniform4f(loc, v.x, v.y, v.z, v.w);

}

void Effect::SetTex(int loc, int id) {

	glUniform1i(loc, id);

}

void Effect::SetBool(int loc, bool s) {

	int y = 0;
	if (s) y = 1;
	
	glUniform1i(loc, y);

}

