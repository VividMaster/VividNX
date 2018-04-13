#include "stdafx.h"
#include "Vertex.h"


Vertex::Vertex()
{
	X = Y = Z = 0;
	U = V = W = 0;
	R = G = B = A = 1;
}

Vertex::Vertex(float x, float y, float z, float u, float v) {

	X = x; Y = y; Z = z;
	U = u; V = v; W = 0;
	R = G = B = A = 1;
	NX = NY = NZ = 0;
	BIX = BIY = BIZ = 0;
	TX = TY = TZ = 0;


}


Vertex::~Vertex()
{
}
