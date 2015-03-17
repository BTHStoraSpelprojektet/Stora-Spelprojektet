#ifndef COMPILEDSHADERREADER
#define COMPILEDSHADERREADER

#include "..\CommonLibs\CommonStructures.h"
#include <vector>

class CompiledShaderReader
{
public:
	CompiledShaderReader();
	~CompiledShaderReader();

	static std::vector<unsigned char> ReadShaderData(std::string p_fileName);

private:
};
#endif