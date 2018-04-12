#include "stdafx.h"
#include "SceneNode.h"


SceneNode::SceneNode()
{

	

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
