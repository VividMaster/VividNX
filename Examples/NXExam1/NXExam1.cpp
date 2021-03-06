// NXExam1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Exam1 : public State {
public:
	Exam1() {


	}
	void Init()  {

		Imp = new Import();
		Graph = new SceneGraph();
		Cam1 = new NodeCam();
		cout << "Importing mesh" << endl;
		Ent1 = Imp->ImportAssImp("c:\\Media\\dwarf2.b3d");
		Pen1 = new Pen();
		Ren1 = new RendererMultiPass();
		Ren1->SetGraph(Graph);
		Graph->SetRoot(Ent1);
		Graph->AddCam(Cam1);
		Cam1->SetPosition(0, 40, 60);
		Ent1->SetPosition(-20, 0, 0);
		MatBasic * Mat1 = new MatBasic();
		Mat1->SetDiffuse(new Texture2D("c:\\media\\dwarf2.jpg"));
		Ent1->SetMaterial(Mat1);
		Ren1->Sync();

	}

	void Update()  {
		//	Pen1->Rect(20, 20, 200, 200, glm::vec4(1, 1, 1, 1));

			//Ent1->SetRotate(0, a1, 0);

		cy += Global::MXD;
		cx += Global::MYD;
		Cam1->SetRotate(-cx, -cy, 0);
		
		if (Global::Key[KeyID::W]) {

			Cam1->Move(0, 0, -1);

		}
		if (Global::Key[KeyID::A]) {

			Cam1->Move(-1, 0, 0);

		}

		if (Global::Key[KeyID::D]) {

			Cam1->Move(1, 0, 0);

		}

		if (Global::Key[KeyID::S]) {

			Cam1->Move(0, 0, 1);

		}

	}

	void Render()  {

//		Pen1->Rect(20, 20, 200, 200, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

		Ren1->RenderScene();

	}
	float cx=0, cy=0, cz=0;
	float a1 = 0;
	Pen * Pen1;
	Import * Imp;
	SceneGraph * Graph;
	Node3D * Ent1;
	NodeCam * Cam1;
	RendererMultiPass * Ren1;

};

int main()
{
	
	App* app = new App(640, 480, "Example 1 - VividNX", false);
	Exam1* s1 = new Exam1;
	
	app->SetInitialState(s1);

	app->Run(30, 30);


    return 0;
}

