#pragma once
#include "stdafx.h"

using namespace std;



class RendererSimple : public SceneRenderer
{
public:
	RendererSimple();
	~RendererSimple();
	void Sync() ;
	void RenderNode(SceneNode * node) ;
	void BindNode(SceneNode * node) ;
	void ReleaseNode(SceneNode * node) ;
};

