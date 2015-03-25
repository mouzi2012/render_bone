#include "RenderObjFactory.h"
#include "HeadCommon.h"

#include "StaticModel.h"

RenderObjFactory* RenderObjFactory::pRenderObjFactoryInstance = NULL;

RenderObjFactory::RenderObjFactory()
{
}
RenderObjFactory::~RenderObjFactory()
{
}
RenderObjFactory* RenderObjFactory::Instance()
{
	if(pRenderObjFactoryInstance == NULL)
	{
		pRenderObjFactoryInstance = new RenderObjFactory();
	}
	return pRenderObjFactoryInstance;
}
void RenderObjFactory::Destroy()
{
	delete pRenderObjFactoryInstance;
	pRenderObjFactoryInstance = NULL;
}
RenderObj* RenderObjFactory::CreateRenderObj(RenderObjType type)
{
	switch(type)
	{
	case eRenderStatic:
	{
		return new StaticModel(); 
	}
	case eRenderAniBone:
	{
		//return new StaticModel(); 
	}
	break;
	}
}

