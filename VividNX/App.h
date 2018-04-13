#pragma once


#include "stdafx.h"


using namespace std;
class State;

enum KeyID{W=GLFW_KEY_W,A=GLFW_KEY_A,S=GLFW_KEY_S,D=GLFW_KEY_D};

class App
{
public:
	App();
	App(int width, int height, string title, bool fullscreen);
	virtual ~App();
	int AppW = 0;
	int AppH = 0;
	string AppTitle = "";
	bool Fullscreen = false;
	void Run(int ups, int fps);
	void SetInitialState(State* state);
	void SetState(State * state);

private:
	void InitWindow();
	GLFWwindow * Win=nullptr;
	State* InitialState = nullptr;
	State* CurState = nullptr;

};
