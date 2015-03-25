#include "RenderResource.h"
#include "HeadCommon.h"

#include "Shader.h"

RenderResource::RenderResource()
{
	m_index=0;
	m_shader=NULL;
}
RenderResource::~RenderResource()
{
}

ResourceType RenderResource::GetType()
{
	return m_type;
}
ResourceInputType RenderResource::GetInputType()
{
	return m_inputType;
}
const char* RenderResource::GetName()
{
	return m_name;
}
void RenderResource::SetInitInfo(ResourceType type,ResourceInputType inputType,const char* name)
{
	m_type=type;
	m_inputType=inputType;
	strcpy(m_name,name);
}
void RenderResource::SetShader(Shader* sh)
{
	m_shader = sh;
}
Shader* RenderResource::GetShader()
{
	return m_shader;
}
int RenderResource::GetLoadFlag()
{
	return m_isLoad;
}
void RenderResource::SetLoadFlag(int load)
{
	m_isLoad = load;
}

