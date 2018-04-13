// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers




#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#include <cstdio>
#include <iostream>>
#include <string>
#include <list>
#include <vector>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/matrix.hpp>
#include <assimp/cimport.h>

#include <assimp/scene.h>
#include <assimp/postprocess.h>
using namespace std;

#include "State.h"
#include "App.h"
#include "Log.h"
#include "SceneNode.h"
#include "SceneGraph.h"
#include "Node3D.h"
#include "NodeCam.h"
#include "Vertex.h"
#include "Triangle.h"
#include "MeshData.h"
