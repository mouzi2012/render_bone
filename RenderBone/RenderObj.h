#ifndef RENDEROBJ_H
#define RENDEROBJ_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class RenderResource;
class RenderObj
{
public:
	RenderObj();
	~RenderObj();

	virtual void InitObj()=0;
	virtual void DrawObj()=0; 
	//this is for the contents
public:
	void setIndex(int index)
	{
		m_cIndex=index;
	}
	int getIndex()
	{
		return m_cIndex;
	}
	void SetResource(RenderResource* res)
	{
		m_renderRes=res;
	}
	RenderResource* GetResource()
	{
		return m_renderRes;
	}
	
private:
	//this is for container easy to find!!
	int m_cIndex;

	RenderResource* m_renderRes;
};
#endif
