
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

	Global::W = width;
	Global::H = height;
	Global::Full = full;
	Global::Title = title;

	InitWindow();

	GLenum err = glewInit();

	if (GLEW_OK != err) {

		cout << "failed to initialize opengl-exstentions." << endl;
		while (true) {

		}

	}

	ilInit();

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

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

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

	glfwSetInputMode(Win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


	glEnable(GL_CULL_FACE);
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);
	glDisable(GL_SCISSOR_TEST);
	glViewport(0, 0, AppW, AppH);
	glCullFace(GL_BACK);
	glClearDepth(1.0f);
	glDepthFunc(GL_LESS);
}

 void key_callback(GLFWwindow * win, int key, int scan, int act, int mods) {

	

	 if (act == GLFW_PRESS) {
		 if (key < 0 || key>255) return;
		 Global::Key[key] = true;
	 }
	 else if (act == GLFW_RELEASE) {
		 if (key < 0 || key>255) return;
		 Global::Key[key] = false;
	 }

 }

 void App::Run(int ups, int fps)
{

	glClearColor(0, 0, 0, 0);

	if (InitialState != nullptr) {
		SetState(InitialState);
	}
	double ax, ay;
	glfwGetCursorPos(Win, &ax, &ay);
	Global::MX = ax;
	Global::MY = ay;
	glfwSetKeyCallback(Win, key_callback);


	while (!glfwWindowShouldClose(Win)) {

		glfwMakeContextCurrent(Win);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		double cx = 0, cy = 0;

		glfwGetCursorPos(Win, &cx, &cy);


		Global::MXD = (float)cx - Global::MX;
		Global::MYD = (float)cy - Global::MY;
		Global::MX = (float)cx;
		Global::MY = (float)cy;

	

		//cout << "CX:" << cx << " CY:" << cy << endl;

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
	CurState->Init();

}
