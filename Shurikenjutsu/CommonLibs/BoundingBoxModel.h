#ifndef BOUNDINGBOXMODEL_H_
#define BOUNDINGBOXMODEL_H_

#include "CommonStructures.h"
#include <vector>
#include "ModelImporter.h"

class BoundingBoxModel
{
public:
	BoundingBoxModel();
	~BoundingBoxModel();
	virtual bool LoadModel(const char* p_filepath);
	virtual void Shutdown();

	std::vector<Box> GetBoundingBoxes();
protected:
	std::vector<Box> m_boundingBoxes;
};

#endif