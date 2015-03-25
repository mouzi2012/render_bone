#ifndef STATICMODEL_H
#define STATICMODEL_H
#include "ResourceCommon.h"
#include "RenderObj.h"

class StaticModel : public RenderObj
{
public:
	StaticModel();
	~StaticModel();
	
	void LoadModel(const char* name,ResourceInputType inputType=TInputTypeHeHe);
	virtual void InitObj();
	virtual void DrawObj();	

	void MoveModel(float x,float y,float z);
private:
	glm::mat4 m_modelMatrix;	
	
};
#endif
