#include "StaticModel.h"
#include "GLCommon.h"

#include "RenderResourceManager.h"
#include "RenderManager.h"
#include "StaticModelResource.h"
#include "Shader.h"

StaticModel::StaticModel()
{
}
StaticModel::~StaticModel()
{
}
void StaticModel::InitObj()
{
}
void StaticModel::DrawObj()
{
	RenderManager* manager=RenderManager::Instance();
	const glm::mat4& view=manager->GetView();
	const glm::mat4& proj=manager->GetProjection();
	StaticModelResource* resource=(StaticModelResource*)GetResource();
	resource->BindData();
	Shader* sh=resource->GetShader();
	sh->bind();	
	//need the unifor bind opertation
		
	int projectionMatrixLocation = glGetUniformLocation(sh->id(), "projectionMatrix"); // Get the location of our projection matrix in the shader
	int viewMatrixLocation = glGetUniformLocation(sh->id(), "viewMatrix"); // Get the location of our view matrix in the shader
	int modelMatrixLocation = glGetUniformLocation(sh->id(), "modelMatrix"); // Get the location of our model matrix in the shader

	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &proj[0][0]); // Send our projection matrix to the shader
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &view[0][0]); // Send our view matrix to the shader
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &m_modelMatrix[0][0]); // Send our model matrix to the shader

	glBindVertexArray(resource->GetVAOIndex());
	//glDrawElements(GL_TRIANGLES, resource->GetIndexSize()/sizeof(int), GL_UNSIGNED_INT, NULL);
	glDrawElements(GL_LINES, resource->GetIndexSize()/sizeof(int), GL_UNSIGNED_INT, NULL);
	sh->unbind();	

}
void StaticModel::LoadModel(const char* name,ResourceInputType inputType)
{
	SetResource(RenderResourceManager::Instance()->GetResource(TypeStaticModel,inputType,name));	
}
void StaticModel::MoveModel(float x,float y,float z)
{
	m_modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z)); 
}

