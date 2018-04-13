#include "stdafx.h"
#include "TextLoad.h"


TextLoad::TextLoad()
{
}


TextLoad::~TextLoad()
{
}

TextLoad::TextLoad(string path) {
	
	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();
	Text = buffer.str();

	
	
}