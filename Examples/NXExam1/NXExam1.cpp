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
		cout << "Importing mesh" << endl;
		Ent1 = Imp->ImportAssImp("c:\\Media\\dwarf2.b3d");
		Pen1 = new Pen();
		Ren1 = new RendererSimple();
		Ren1->SetGraph(Graph);
		Graph->SetRoot(Ent1);
		Graph->AddCam(Cam1);
		Cam1->SetPosition(0, 40, 60);
		Ent1->SetPosition(-20, 0, 0);
	
	}

	void Update() override {
	//	Pen1->Rect(20, 20, 200, 200, glm::vec4(1, 1, 1, 1));
 
		Ent1->SetRotate(0, a1, 0);
		a1 += 2;
		cout << a1 << endl;

	}

	void Render() override {

//		Pen1->Rect(20, 20, 200, 200, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

		Ren1->RenderScene();

	}
	float a1 = 0;
	Pen * Pen1;
	Import * Imp;
	SceneGraph * Graph;
	Node3D * Ent1;
	NodeCam * Cam1;
	RendererSimple * Ren1;

};

int main()
{

	App* app = new App(640, 480, "Example 1 - VividNX", false);
	Exam1* s1 = new Exam1;
	
	app->SetInitialState(s1);

	app->Run(30, 30);


    return 0;
}

