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
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/matrix.hpp>
#include <assimp/cimport.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <IL/il.h>;


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
#include "Global.h"
#include "Pen.h"
#include "SceneRenderer.h"
#include "RendererSimple.h"
#include "TextureBase.h"
#include "Texture2D.h"
#include "MaterialBase.h"
#include "MatBasic.h"
#include "RendererMultiPass.h"
#include "Effect.h"
#include "TextLoad.h"
#include "FXMP.h"
#include "NodeLight.h"


