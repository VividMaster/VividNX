#pragma once


#include "stdafx.h"

using namespace std;

class State
{
public:
	State();
	virtual ~State();
	virtual void Init() {
		cout << "One" << endl;
	}
	virtual void Update() {

	}
	virtual void Render() {

	}
	virtual void Pause() {

	}
	virtual void Resume() {

	}
	virtual void Release() {

	}
private:
	bool released = false;
};



inline State::State()
{
}


inline State::~State()
{
	if (!released)
	{
		Release();
	}
}

