#ifndef BUFFER
#define BUFFER

#include <d3d11.h>
#include <vector>
#include "Structures.h"
#include "Enumerations.h"
#include "ConsoleFunctions.h"

class Buffer
{
public:
	static ID3D11Buffer* CreateBuffer(BUFFERTYPE p_type, ID3D11Device* p_device, std::vector<Vertex> p_mesh, std::vector<VertexAnimated> p_meshAnimated);
};
#endif;