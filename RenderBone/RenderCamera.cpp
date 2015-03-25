#include "RenderCamera.h"
RenderCamera::RenderCamera()
{
}
const glm::mat4& RenderCamera::GetViewMatrix()
{
	return m_viewMatrix;
}
const glm::mat4& RenderCamera::GetProjectionMatrix()
{
	return m_projectionMatrix;
}
void RenderCamera::SetUpCamera(glm::vec3& position,glm::vec3& target,glm::vec3& up)
{
	m_position = position;
	m_target = target;
	m_up = up;
	CalCameraMatrix();
}
void RenderCamera::CalCameraMatrix()
{
	m_viewMatrix = glm::lookAt(m_position,m_target,m_up);
	m_projectionMatrix = glm::perspective(3.1415f/5, 512.f / 512.f, 01.f, 100.f);
}
