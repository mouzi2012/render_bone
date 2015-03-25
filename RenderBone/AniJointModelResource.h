#ifndef ANIJOINTMODELRESOURCE_H 
#define ANIJOINTMODELRESOURCE_H 

#include "RenderResource.h"
#include "FbxReader/AniBone.h"
#include "FbxReader/AniVertex.h"

struct AniJointBlock
{
	AniBone* m_bone;
	AniVertexInfo* m_vertexInfo;
};
class AniJointModelResource : public RenderResource
{
public:
	AniJointModelResource();	
	~AniJointModelResource();	
	virtual	void LoadResource();
private:
	AniJointBlock m_dataBlock;	
};
#endif
