#include "stdafx.h"
#include "CompiledShaderReader.h"
#include "..\CommonLibs\ConsoleFunctions.h"
#include <fstream>

CompiledShaderReader::CompiledShaderReader()
{

}

CompiledShaderReader::~CompiledShaderReader()
{

}

std::vector<unsigned char> CompiledShaderReader::ReadShaderData(std::string p_fileName)
{
	std::vector<unsigned char> fileData;

	// open the file
	std::ifstream vertexFile(p_fileName, std::ios::in | std::ios::binary | std::ios::ate);

	// if open was successful
	if (vertexFile.is_open())
	{
		// find the length of the file
		int Length = (int)vertexFile.tellg();

		// collect the file data
		fileData.resize(Length);
		vertexFile.seekg(0, std::ios::beg);
		vertexFile.read(reinterpret_cast<char*>(&fileData[0]), Length);
		vertexFile.close();
	}

	return fileData;
}
