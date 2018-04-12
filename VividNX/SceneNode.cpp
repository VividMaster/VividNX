#include "stdafx.h"
#include "SceneNode.h"


SceneNode::SceneNode()
{

	Rotation = glm::mat4(1);
	Position = glm::vec3();
	Scale = glm::vec3();

}


SceneNode::~SceneNode()
{


}

SceneNode* SceneNode::GetRoot() {

	return Root;

}

void SceneNode::SetRoot(SceneNode * node) {

	if (Root != nullptr) {

		Root->Remove(this);

	}
	Root = node;
	node->Add(this);
}

void SceneNode::Remove(SceneNode * node)
{

	Nodes.remove(node);

}

void SceneNode::Add(SceneNode * node)
{

	Nodes.push_back(node);
	
	if (node->GetRoot() != nullptr) {

		SceneNode * tn = node->GetRoot();
		tn->Remove(node);

	}
	
	node->SetRoot(this);


}

glm::mat4 SceneNode::GetWorldMat() override {

	glm::mat4 r = glm::mat4();

	if (Root != nullptr) {

		glm::mat4 nr = glm::mat4();

		r = r * nr;

	}

	glm::mat4 nm = glm::translate(r, Position);

	return nm;

}