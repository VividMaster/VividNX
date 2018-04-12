#pragma once


#include "stdaf.h"

using namespace std;

class Log
{
public:
	Log();
	virtual ~Log();
	static void LogMsg(string msg);
};



Log::Log()
{
}


Log::~Log()
{
}

void Log::LogMsg(string msg) {

	cout << "Log:" << msg << endl;

}