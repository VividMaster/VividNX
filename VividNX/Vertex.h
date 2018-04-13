#pragma once
struct Vertex
{
public:
	Vertex();
	Vertex(float x, float y, float z, float u, float v);
	~Vertex();
	float X, Y, Z;
	float NX, NY, NZ;
	float BIX, BIY, BIZ;
	float TX, TY, TZ;
	float U, V, W;
	float R, G, B, A;
};

