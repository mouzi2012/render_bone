#ifndef RENDERRESOURCE_H
#define RENDERRESOURCE_H

#include "ResourceCommon.h"
class Shader;
class RenderResource
{
public:
	RenderResource();
	~RenderResource();
public:
	virtual	void LoadResource()=0;

	void SetInitInfo(ResourceType type,ResourceInputType inputType,const char* name);
	ResourceType GetType();
	ResourceInputType GetInputType();
	const char* GetName();
public:
	void SetShader(Shader* sh);
	Shader* GetShader();
protected:
	int GetLoadFlag();
	void SetLoadFlag(int load);
private:
	ResourceType m_type;
	ResourceInputType m_inputType;
	char m_name[NAMEBUFFERC];
	int m_isLoad;
	int m_index;
	Shader* m_shader;

};
#endif
