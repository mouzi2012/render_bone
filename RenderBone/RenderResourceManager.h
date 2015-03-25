#ifndef RENDERRESOURCEMANAGER_H
#define RENDERRESOURCEMANAGER_H

#include <vector>
using std::vector;

#include "ResourceCommon.h"

class RenderResource;
class RenderResourceManager
{
private:
	RenderResourceManager();
	~RenderResourceManager();
	static RenderResourceManager* pRenderResourceManagerInstance;	
private:
	//the value mustchange!!!
	vector<RenderResource*> m_resources[TypeSize];
public:
	static RenderResourceManager* Instance();
	static void Destroy();	
private:
	RenderResource* CreateResource(ResourceType type,ResourceInputType inputType,const char* name);
public:
	RenderResource* GetResource(ResourceType type,ResourceInputType inputType,const char* name);
};
#endif
