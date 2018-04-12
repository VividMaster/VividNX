#pragma once


#include "stdafx.h"


using namespace std;
class State;
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
