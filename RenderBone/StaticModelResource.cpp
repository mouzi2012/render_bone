#include "StaticModelResource.h"
#include "GLCommon.h"
#include "Shader.h"
StaticModelResource::StaticModelResource()
{
	m_isCached = false;	
}
StaticModelResource::~StaticModelResource()
{
}
bool StaticModelResource::IsCached()
{
	return m_isCached;
}
int StaticModelResource::GetIndexSize()
{
	return m_size1;
}
unsigned int StaticModelResource::GetVAOIndex()
{
	return m_vaoID[0];
}

void StaticModelResource::BindData()
{
	if(!m_isCached)
	{
		CacheData();
	}
}
void StaticModelResource::LoadResource()
{
	ResourceInputType inputType= GetInputType();
	switch(inputType)
	{
		case TInputTypeHeHe:
			{
				loadResourceFromMemory();	
			}
			break;
	}
		
	
}
void StaticModelResource::CacheData()
{
	ResourceInputType inputType= GetInputType();
	switch(inputType)
	{
		case TInputTypeHeHe:
			{
				CacheMemoryData();	
			}
			break;
	}

}

void StaticModelResource::loadResourceFromMemory()
{
	float* vertices = new float[18];	// Vertices for our square

	vertices[0] = 0.0; vertices[1] = 0.0; vertices[2] = 0.0; // Bottom left corner
	vertices[3] = 0.5; vertices[4] = 0.0; vertices[5] = 0.0; // Top left corner
	vertices[6] = 0.0; vertices[7] = 1.5; vertices[8] = 0.0; // Top Right corner

	vertices[9] = 0.5; vertices[10] = -0.5; vertices[11] = 0.0; // Bottom right corner
	vertices[12] = -0.5; vertices[13] = -0.5; vertices[14] = 0.0; // Bottom left corner
	vertices[15] = 0.5; vertices[16] = 0.5; vertices[17] = 0.0; // Top Right corner
	
	m_buffers0 =vertices;
	m_size0 =sizeof(float)*18;

	int* indexs = new int [6];
	indexs[0] = 0;
	indexs[1] = 1;
	indexs[2] = 1;
	indexs[3] = 2;
	indexs[4] = 2;
	indexs[5] = 0;

	m_buffers1= indexs;
	m_size1 =sizeof(int)*6;


}
void StaticModelResource::CacheMemoryData()
{
	//load resource here
	LoadResource();
	//load the shaders
	SetShader(new Shader("shaders/shader.vert","shaders/shader.frag"));	
	//bind to server
	glGenVertexArrays(1, &m_vaoID[0]);  
	glBindVertexArray(m_vaoID[0]);  

	glGenBuffers(2, m_vboID);
	
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID[0]);  
	glBufferData(GL_ARRAY_BUFFER, m_size0, m_buffers0, GL_STATIC_DRAW);  
  
	glEnableVertexAttribArray(0);  
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
  
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vboID[1]);  
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_size1, m_buffers1, GL_STATIC_DRAW);  
  
	glBindVertexArray(0);  
  
	glBindBuffer(GL_ARRAY_BUFFER, 0);  
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);  

	m_isCached = true;

}
