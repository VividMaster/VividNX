#include "stdafx.h"
#include "SceneNode.h"

#define degreesToRadians(x) x*(3.141592f/180.0f)
SceneNode::SceneNode()
{

	Rotation = glm::mat4(1);
	Position = glm::vec3();
	Scale = glm::vec3();
	Name = "";

}


SceneNode::~SceneNode()
{


}

void SceneNode::SetName(string name) {

	Name = name;

}

string SceneNode::GetName() {

	return Name;

}

SceneNode* SceneNode::GetRoot() {

	return Root;

}

void SceneNode::SetRoot(SceneNode * node) {

	Root = node;

}

void SceneNode::Remove(SceneNode * node)
{

	for (int i = 0; i < Nodes.size(); i++) {

		if (Nodes[i] == node) {

			Nodes.erase(Nodes.begin() + i);
			return;

		}

	}

}

void SceneNode::Add(SceneNode * node)
{

	

	node->SetRoot(this);
	Nodes.push_back(node);
	

}

glm::mat4 SceneNode::GetWorldMat() {

	glm::mat4 r = glm::mat4();

	if (Root != nullptr) {

		glm::mat4 nr = glm::mat4();

		r = r * nr;

	}

	glm::mat4 nm = glm::translate(r, Position);

	nm = nm * Rotation;

	return nm;

}

vector<SceneNode *> SceneNode::GetNodes() {

	return Nodes;

}

void SceneNode::SetPosition(glm::vec3 pos) {

	Position = pos;

}

void SceneNode::SetPosition(float x, float y, float z)
{

	Position = glm::vec3(x, y, z);

}

glm::vec3 SceneNode::GetPosition() {

	return Position;

}

void SceneNode::SetRotate(float x, float y, float z)
{

	Rotation = glm::eulerAngleYXZ(degreesToRadians(y), degreesToRadians(x), degreesToRadians(z));
	//glm::rot


}

void SceneNode::Move(float x, float y, float z) {

	glm::vec3 v = glm::vec3(x, y, z);

	glm::mat4 mr = glm::translate(Rotation, v);
	
	glm::mat4 rm;
	glm::vec3 rs;
	glm::quat rr;
	glm::vec3 trans;
	glm::vec3 skew;
	glm::vec4 perp;

	glm::decompose(mr, rs, rr, trans, skew, perp);
//	cout << "VX:" << trans.x << " VY:" << trans.y << " Z:" << trans.z << endl;
	Position.x = Position.x + trans.x;
	Position.y = Position.y + trans.y;
	Position.z = Position.z + trans.z;


}