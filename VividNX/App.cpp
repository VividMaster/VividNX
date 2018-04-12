
#pragma once

#include "stdafx.h"


 void error_callback(int error, const char* description)
{
	cout << description << endl;
}


App::App()
{



}

 App::App(int width, int height, string title, bool full) {

	AppW = width;
	AppH = height;
	AppTitle = title;
	Fullscreen = full;

	InitWindow();

}

 App::~App()
{
	glfwDestroyWindow(Win);
	glfwTerminate();

}

 void App::InitWindow() {

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
		Win = glfwCreateWindow(AppW, AppH, AppTitle.c_str(), nullptr, nullptr);
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
 void App::Run(int ups, int fps)
{

	glClearColor(0, 0, 0, 0);

	if (InitialState != nullptr) {
		SetState(InitialState);
	}

	while (!glfwWindowShouldClose(Win)) {

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

 void App::SetInitialState(State* state)
{

	InitialState = state;

}


 void App::SetState(State* state)
{

	if (CurState != nullptr) {

		CurState->Release();

	}
	CurState = state;


}
