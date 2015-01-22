#include "TextureLibrary.h"
#include <iostream>
#include "GraphicsEngine.h"
#include "WICTextureLoader.h"

TextureLibrary* TextureLibrary::m_instance;

TextureLibrary::TextureLibrary(){}
TextureLibrary::~TextureLibrary(){}

void TextureLibrary::Initialize()
{
	// Load every model!
	LoadTextureDirectory();
}

void TextureLibrary::Shutdown()
{
	// Shutdown Models using iterator to loop through the map
	/*for (auto it = m_textures.begin(); it != m_textures.end(); it++)
	{
		it->second.Shutdown();
	}*/

	delete m_instance;
	m_instance = nullptr;
}

TextureLibrary* TextureLibrary::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new TextureLibrary();
	}

	return m_instance;
}

ID3D11ShaderResourceView* TextureLibrary::GetTexture(std::string p_path)
{
	return m_textures[p_path];
}

void TextureLibrary::AddTexture(std::string p_path)
{
	m_textures[p_path] = GraphicsEngine::Create2DTexture(p_path);;
}

void TextureLibrary::LoadTextureDirectory()
{

	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;

	// Find the first file in the directory.
	hFind = FindFirstFile("../Shurikenjutsu/2DTextures/*", &ffd);

	// Skip the ".." file
	FindNextFile(hFind, &ffd);

	// Relevant files
	while (FindNextFile(hFind, &ffd) != 0)
	{
		AddTexture("../Shurikenjutsu/2DTextures/" + (std::string)ffd.cFileName);
		std::cout << "Loading texture: " + (std::string)ffd.cFileName << std::endl;
	}

	FindClose(hFind);
}