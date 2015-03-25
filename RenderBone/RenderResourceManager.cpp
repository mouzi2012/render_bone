#include "RenderResourceManager.h"
#include "HeadCommon.h"
#include "StaticModelResource.h"
#include "AniJointModelResource.h"
RenderResourceManager* RenderResourceManager::pRenderResourceManagerInstance=NULL;
RenderResourceManager::RenderResourceManager()
{
}
RenderResourceManager::~RenderResourceManager()
{
}

RenderResourceManager* RenderResourceManager::Instance()
{
	if(pRenderResourceManagerInstance == NULL)
	{
		pRenderResourceManagerInstance = new RenderResourceManager();
	}	
	return pRenderResourceManagerInstance;
}
void RenderResourceManager::Destroy()	
{
	delete pRenderResourceManagerInstance;
	pRenderResourceManagerInstance= NULL;
}


RenderResource* RenderResourceManager::CreateResource(ResourceType type,ResourceInputType inputType,const char* name)
{
	RenderResource* pRenderResource = NULL;
	// this function is too simple need fix!!
	switch(type)
	{
	case TypeStaticModel:
		{
			pRenderResource=new StaticModelResource();
		}	
		break;
	case TypeAniJoint:
		{
			pRenderResource=new AniJointModelResource();
		}	
		break;
	}
	pRenderResource->SetInitInfo(type,inputType,name);
	return pRenderResource;

}
RenderResource* RenderResourceManager::GetResource(ResourceType type,ResourceInputType inputType,const char* name)
{
	vector<RenderResource*> vec = m_resources[type];
	bool isFind = false;
	int index = -1;
	for(int i=0; i<(int)vec.size();++i)
	{
		if(vec[i]->GetInputType() == inputType)
		{
			const char* rName=vec[i]->GetName();
			if(strcmp(rName,name) == 0)
			{
				isFind =true;
				index =i;
				break;
			}	
		}	
	}
	if(isFind)
	{
		return vec[index];
	}
	else
	{
		RenderResource* pRenderResource = CreateResource(type,inputType,name);
		vec.push_back(pRenderResource);
		return pRenderResource;
	}
}
