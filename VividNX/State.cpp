
#pragma once

#include "stdafx.h"





 State::State()
{
}


 State::~State()
{
	if (!released)
	{
		Release();
	}
}

