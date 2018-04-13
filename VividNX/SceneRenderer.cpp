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

	Bind();
	RenderNode(Graph->GetRoot());
	Release();

}

void SceneRenderer::RenderNode(SceneNode * node) {


}

void SceneRenderer::Bind() {

}
void SceneRenderer::Release() {


}

void SceneRenderer::BindNode(SceneNode * node) {

}

void SceneRenderer::ReleaseNode(SceneNode * node) {

}