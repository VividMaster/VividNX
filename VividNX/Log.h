#pragma once


#include "stdafx.h"

using namespace std;

class Log
{
public:
	Log();
	virtual ~Log();
	static void LogMsg(string msg);
};

