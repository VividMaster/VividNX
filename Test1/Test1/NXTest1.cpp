// NTest1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Test1 : public State
{
public:

	Test1() {

	}
	~Test1() {

	}

	void Init() override {

	//cout << "Yep!" << endl;

	}

	void Update() override {

		cout << "updating" << endl;

	}

	void Render() override {


	}

};

int main()
{

	Test1 * t1 = new Test1();

	
	
	App *app = new App(640, 480, "VividN - Test 1.", false);
	app->SetInitialState(t1);
	cout << "Starting Test 1" << endl;
	app->Run(30, 30);

    return 0;
}

