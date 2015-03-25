#ifndef RENDEROBJFACTORY_H
#define RENDEROBJFACTORY_H

enum RenderObjType{eRenderStatic=0,eRenderAniBone};
class RenderObj;
class RenderObjFactory
{
private:
	RenderObjFactory();
	~RenderObjFactory();
	static RenderObjFactory* pRenderObjFactoryInstance;
public:
	static RenderObjFactory* Instance();
	static void Destroy();
public:
	RenderObj* CreateRenderObj(RenderObjType type);
};
#endif
