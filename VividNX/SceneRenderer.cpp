#include "stdafx.h"
#include "SceneRenderer.h"


SceneRenderer::SceneRenderer()
{
}


SceneRenderer::~SceneRenderer()
{
}

void SceneRenderer::SetGraph(SceneGraph * graph) {

	Graph = graph;

}

SceneGraph * SceneRenderer::GetGraph() {

	return Graph;

}

void SceneRenderer::Sync()
{

}

void SceneRenderer::RenderScene() {

	RenderNode(Graph->GetRoot());

}

void SceneRenderer::RenderNode(SceneNode * node) {


}