#include "TextureLibrary.h"
#include <iostream>
#include "GraphicsEngine.h"
#include "WICTextureLoader.h"
#include "ConsoleFunctions.h"

TextureLibrary* TextureLibrary::m_instance;

TextureLibrary::TextureLibrary(){}
TextureLibrary::~TextureLibrary(){}

void TextureLibrary::Initialize()
{
	// Load every texture.
	LoadTextureDirectory();
}

void TextureLibrary::Shutdown()
{
	// Shutdown texture using iterator to loop through the map
	for (auto it = m_textures.begin(); it != m_textures.end(); it++)
	{
		if (it->second != nullptr)
		{
			it->second->Release();
			it->second = nullptr;
		}
	}

	if (m_instance)
	{
		delete m_instance;
		m_instance = nullptr;
	}
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
	m_textures[p_path] = GraphicsEngine::GetInstance()->Create2DTexture(p_path);
	
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
		// Avoid loading the windows folder thumb file.
		if ((std::string)ffd.cFileName != "Thumbs.db")
		{
			AddTexture("../Shurikenjutsu/2DTextures/" + (std::string)ffd.cFileName);
		}
	}

	FindClose(hFind);
}