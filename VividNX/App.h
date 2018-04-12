#pragma once


#include "stdafx.h"

using namespace std;

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


inline void error_callback(int error, const char* description)
{
	cout << description << endl;
}


App::App()
{



}

inline App::App(int width, int height, string title, bool full) {

	AppW = width;
	AppH = height;
	AppTitle = title;
	Fullscreen = full;

	InitWindow();

}

inline App::~App()
{
	glfwDestroyWindow(Win);
	glfwTerminate();

}

inline void App::InitWindow() {

	if (!glfwInit())
	{

		cout << "Error initilizing glfw" << endl;


	}

	glfwSetErrorCallback(error_callback);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	if (Fullscreen) {
		Win = glfwCreateWindow(AppW, AppH, AppTitle.c_str(), glfwGetPrimaryMonitor(), nullptr);
	}
	else {
		Win = glfwCreateWindow(AppW, AppH, AppTitle.c_str(), nullptr,nullptr);
	}
	if (!Win)
	{
		cout << "Error creating window" << endl;
		// Window or OpenGL contet creation failed
		exit(0);
	}
	else {

		cout << "Created window" << endl;

	}

	glfwMakeContextCurrent(Win);
	glfwSwapInterval(1);

}
inline void App::Run(int ups, int fps)
{

	glClearColor(0, 0, 0, 0);

	if (InitialState != nullptr) {
		SetState(InitialState);
	}

	while (!glfwWindowShouldClose(Win)){

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (CurState != nullptr) {

			CurState->Update();
			CurState->Render();

		}

		glfwSwapBuffers(Win);
		glfwPollEvents();

	}

	if (CurState != nullptr) {

		CurState->Release();

	}

}

inline void App::SetInitialState(State* state)
{

	InitialState = state;

}


inline void App::SetState(State* state)
{

	if (CurState != nullptr) {

		CurState->Release();

	}
	CurState = state;
	

}
