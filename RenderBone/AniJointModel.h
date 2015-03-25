#ifndef ANIJOINTMODEL_H
#define ANIJOINTMODEL_H
#include "RenderObj.h"
#include "ResourceCommon.h"
class AniJointModel:public RenderObj
{
public:
	AniJointModel();
	~AniJointModel();
	void LoadModel(const char* name,ResourceInputType inputType);
	virtual void InitObj();
	virtual void DrawObj();	

private:
	glm::mat4 m_modelMatrix;	
};
#endif
