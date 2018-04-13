#pragma once


#include "stdafx.h"

using namespace std;


class RendererMultiPass :
	public SceneRenderer
{
public:
	RendererMultiPass();
	~RendererMultiPass();
	void Sync() ;
	void Bind() ;
	void Release() ;
	void BindNode(SceneNode * node) ;
	void RenderNode(SceneNode * node) ;
	void ReleaseNode(SceneNode * node) ;
};

