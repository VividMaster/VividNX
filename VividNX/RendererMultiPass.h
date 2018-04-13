#pragma once


#include "stdafx.h"

using namespace std;


class RendererMultiPass :
	public SceneRenderer
{
public:
	RendererMultiPass();
	~RendererMultiPass();
	void Sync() override;
	void Bind() override;
	void Release() override;
	void BindNode(SceneNode * node) override;
	void RenderNode(SceneNode * node) override;
	void ReleaseNode(SceneNode * node) override;
};

