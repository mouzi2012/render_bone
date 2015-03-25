#include "RenderManager.h"
#include "RenderObj.h"
#include "RenderCamera.h"
#include "HeadCommon.h"

RenderManager* RenderManager::pRenderManagerInstance = NULL;
RenderManager::RenderManager()
{
	m_renderSize = 0;
	m_curCamera = NULL;

}
RenderManager::~RenderManager()
{
}

RenderManager* RenderManager::Instance()
{
	if(pRenderManagerInstance == NULL)
	{
		pRenderManagerInstance = new RenderManager();
	}	
	return pRenderManagerInstance;
}
void RenderManager::Destroy()
{
	delete pRenderManagerInstance;
	pRenderManagerInstance = NULL;

}

void RenderManager::Init()
{
	m_renderObjs.reserve(MaxRenderNum);
}
void RenderManager::DrawALL()
{
	for(int i=0;i<m_renderObjs.size();++i)
	{
		m_renderObjs[i]->DrawObj();
	}
}
void RenderManager::AddRenderObj(RenderObj* obj)
{
	m_renderObjs.push_back(obj);		
	obj->setIndex(m_renderSize++);

}
void RenderManager::RemoveRenderObj(RenderObj* obj)
{
	int index=obj->getIndex();
	int indexLast=m_renderObjs.size()-1;

	//do the release first!!
	//m_renderObjs[index].release()
	//this has not yet do!!
	
	m_renderObjs[index]=m_renderObjs[indexLast];
	m_renderObjs[index]->setIndex(index);
	m_renderObjs.resize(--m_renderSize);

}
void RenderManager::AddRenderCamera(RenderCamera* camera)
{
	m_cameras.push_back(camera);
}
const glm::mat4& RenderManager::GetProjection()
{
	return m_curCamera->GetProjectionMatrix();
}
const glm::mat4& RenderManager::GetView()
{
	return m_curCamera->GetViewMatrix(); 
}

void RenderManager::SetCurCamera(int i)
{
	m_curCamera = m_cameras[i];
}
void RenderManager::AddOneCamera(glm::vec3& position,glm::vec3& target,glm::vec3& up)
{
	RenderCamera* camera=new RenderCamera;
	camera->SetUpCamera(position,target,up);
	AddRenderCamera(camera);
}
