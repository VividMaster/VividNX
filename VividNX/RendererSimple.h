#pragma once
#include "stdafx.h"

using namespace std;



class RendererSimple : public SceneRenderer
{
public:
	RendererSimple();
	~RendererSimple();
	void Sync() override;
	void RenderNode(SceneNode * node) override;
};

