
#pragma once

#include "stdafx.h"





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

