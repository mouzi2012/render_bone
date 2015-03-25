#ifndef GLCONTEXMANAGER_H
#define GLCONTEXMANAGER_H
#include "RenderBone/HeadCommon.h"
#include "RenderBone/GLCommon.h"
#include "RenderBone/RenderNeed.h"
class GLFWwindow;
class GLContexManager
{
public:
	static GLFWwindow* InitGLFWContex(int f,int s);
};
#endif

