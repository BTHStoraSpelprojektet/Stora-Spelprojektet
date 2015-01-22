#ifndef TEXTURELIBRARY_H_
#define TEXTURELIBRARY_H_

#include <windows.h>
#include <unordered_map>
#include <string>
#include "DirectX.h"

class TextureLibrary
{
public:
	TextureLibrary(const TextureLibrary&) = delete;
	TextureLibrary& operator=(const TextureLibrary&) = delete;

	void Initialize();
	void Shutdown();

	static TextureLibrary* GetInstance();

	ID3D11ShaderResourceView* TextureLibrary::GetTexture(std::string p_path);


private:
	void AddTexture(std::string p_path);
	void LoadTextureDirectory();

	static TextureLibrary* m_instance;

	TextureLibrary();
	~TextureLibrary();

	std::unordered_map<std::string, ID3D11ShaderResourceView*> m_textures;
};

#endif // !TEXTURELIBRARY_H_