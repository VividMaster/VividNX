// NXExam1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Exam1 : public State {
public: 
	Exam1() {


	}
	void Init() override {

		Imp = new Import();
		Graph = new SceneGraph();
		Cam1 = new NodeCam();
		Ent1 = Imp->ImportAssImp("dat/ent1.3ds");

	}

	void Update() override {

		cout << "updating" << endl;
 
	}

	void Render() override {


	}
	Import * Imp;
	SceneGraph * Graph;
	Node3D * Ent1;
	NodeCam * Cam1;

};

int main()
{

	App* app = new App(640, 480, "Example 1 - VividNX", false);
	Exam1* s1 = new Exam1;
	
	app->SetInitialState(s1);

	app->Run(30, 30);


    return 0;
}

