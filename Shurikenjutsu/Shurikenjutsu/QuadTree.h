#ifndef QUADTREE_H_
#define QUADTREE_H_

#include "../CommonLibs/CommonStructures.h"
#include "DirectX.h"
#include "Frustum.h"

class QuadTree
{
private:
	struct NodeType
	{
		float positionX, positionY, width;
		int triangleCount;
		ID3D11Buffer *vertexBuffer, *indexBuffer;
		NodeType* nodes[4];
	};
public:
	QuadTree();
	QuadTree(const QuadTree&);
	~QuadTree();

	bool Initialize();
	void Shutdown();
	void Render();

	int GetDrawCount();

private:
	void CalculateMeshDimensions(int, float&, float&, float&);
	void CreateTreeNode(NodeType*, float, float, float, ID3D11Device*);
	int CountTrinagles(float, float, float);
	bool isTriangleContained(int, float, float, float);
	void ReleaseNode(NodeType*);
	void RenderNode(NodeType*, Frustum*, ID3D11DeviceContext*);

	int m_triangleCount, m_drawCount;
	Vertex* m_vertexList;
	NodeType* m_parentNode;

};
#endif // !QUADTREE_H_
