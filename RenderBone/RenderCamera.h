#ifndef RENDERCAMERA_H
#define RENDERCAMERA_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
class RenderCamera
{
public:
	RenderCamera();
	enum eProjectionType{eOrtho,ePerspective};
public:
	void SetUpCamera(glm::vec3& position,glm::vec3& target,glm::vec3& up);
	void CalCameraMatrix();
	const glm::mat4& GetViewMatrix();
	const glm::mat4& GetProjectionMatrix();
private:
	glm::vec3 m_position;
	glm::vec3 m_target;
	glm::vec3 m_up;
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;
	eProjectionType m_projectionType;
};
#endif
