#ifndef TEXTURELIBRARY_H_
#define TEXTURELIBRARY_H_

#include "BaseModel.h"
#include <windows.h>
#include <unordered_map>
#include <string>
#include "DirectX.h"

class TextureLibrary
{
public:
	TextureLibrary(const TextureLibrary&) = delete;
	TextureLibrary& operator=(const TextureLibrary&) = delete;

	void Initialize(ID3D11ShaderResourceView *p_modelTypes);
	void Shutdown();

	static TextureLibrary* GetInstance();

	ID3D11ShaderResourceView* TextureLibrary::GetModel(std::string p_path);


private:
	void AddModel(std::string p_path, ID3D11ShaderResourceView *p_textures);
	void LoadTextureDirectory(ID3D11ShaderResourceView *p_textures);

	static TextureLibrary* m_instance;

	TextureLibrary();
	~TextureLibrary();

	std::unordered_map<std::string, ID3D11ShaderResourceView> m_textures;
};

#endif // !TEXTURELIBRARY_H_