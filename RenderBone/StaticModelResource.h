#ifndef STATICMODELRESOURCE_H
#define STATICMODELRESOURCE_H
#include "RenderResource.h"
class StaticModelResource:public RenderResource
{
public:
	StaticModelResource();
	~StaticModelResource();
public:
	virtual void LoadResource();
public:
	bool IsCached();
	int GetIndexSize();
	unsigned int GetVAOIndex();
public:
	void BindData();
	void CacheData();
protected:
	void loadResourceFromMemory();
	void CacheMemoryData();
private:
	// the flowing asume if the data comes from the memery
	const float* m_buffers0;
	const int* m_buffers1;
	int m_size0;
	int m_size1;

	bool m_isCached;

	unsigned int m_vaoID[1];
	unsigned int m_vboID[2];
	// memory end
	
};
#endif
