#include "AniJointModel.h"
#include "GLCommon.h"
#include "RenderResourceManager.h"
#include "RenderManager.h"
#include "StaticModelResource.h"
#include "Shader.h"

AniJointModel::AniJointModel()
{
}
AniJointModel::~AniJointModel()
{
}
void AniJointModel::LoadModel(const char* name,ResourceInputType inputType)
{
	SetResource(RenderResourceManager::Instance()->GetResource(TypeAniJoint,inputType,name));	
}
void AniJointModel::InitObj()
{
}
void AniJointModel::DrawObj()	
{
}
