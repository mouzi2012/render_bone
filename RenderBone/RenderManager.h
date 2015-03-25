#ifndef RENDERMANGER_H
#define RENDERMANGER_H

#include<vector>
using std::vector;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class RenderCamera;
class RenderObj;
class RenderManager
{
private:
	RenderManager();
	~RenderManager();
	static RenderManager* pRenderManagerInstance;
public:
	static RenderManager* Instance();
	static void Destroy();
public:
	void Init();
	void DrawALL();	
	void AddRenderObj(RenderObj* obj);
	void RemoveRenderObj(RenderObj* obj);
	void AddOneCamera(glm::vec3& position,glm::vec3& target,glm::vec3& up);
	void SetCurCamera(int i);
protected:
	void AddRenderCamera(RenderCamera* camera);
public:
	enum RenderEnum{MaxRenderNum=512};
private:
	vector<RenderObj*> m_renderObjs;
	int m_renderSize;
	vector<RenderCamera*> m_cameras;
	RenderCamera* m_curCamera;
public:
	const glm::mat4& GetView();
	const glm::mat4& GetProjection();

};
#endif
