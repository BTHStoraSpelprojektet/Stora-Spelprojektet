#include <D3D11.h>
#include "FW1FontWrapper.h"

#pragma comment (lib, "D3D11.lib")
#pragma comment (lib, "FW1FontWrapper.lib")

#include <string>

// Font enumerator wrapper for a single font
class CFontEnum : public IDWriteFontFileEnumerator {
public:
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject) {
		if (ppvObject == NULL)
			return E_INVALIDARG;

		if (IsEqualIID(riid, __uuidof(IUnknown))) {
			*ppvObject = static_cast<IUnknown*>(this);
			AddRef();
			return S_OK;
		}
		else if (IsEqualIID(riid, __uuidof(IDWriteFontFileEnumerator))) {
			*ppvObject = static_cast<IDWriteFontFileEnumerator*>(this);
			AddRef();
			return S_OK;
		}

		*ppvObject = NULL;
		return E_NOINTERFACE;
	}

	virtual ULONG STDMETHODCALLTYPE AddRef() {
		return static_cast<ULONG>(InterlockedIncrement(reinterpret_cast<LONG*>(&m_cRefCount)));
	}

	virtual ULONG STDMETHODCALLTYPE Release() {
		ULONG newCount = static_cast<ULONG>(InterlockedDecrement(reinterpret_cast<LONG*>(&m_cRefCount)));

		if (newCount == 0)
			delete this;

		return newCount;
	}

	virtual HRESULT STDMETHODCALLTYPE GetCurrentFontFile(IDWriteFontFile **ppFontFile) {
		if (ppFontFile == NULL)
			return E_INVALIDARG;

		if (m_pFontFile == NULL)
			return E_FAIL;

		m_pFontFile->AddRef();
		*ppFontFile = m_pFontFile;

		return S_OK;
	}

	virtual HRESULT STDMETHODCALLTYPE MoveNext(BOOL *pHasCurrentFile) {
		if (pHasCurrentFile == NULL)
			return E_INVALIDARG;

		if (m_count > 0)
			*pHasCurrentFile = FALSE;
		else
			*pHasCurrentFile = TRUE;

		++m_count;

		return S_OK;
	}

public:
	CFontEnum(IDWriteFontFile *pFontFile) :
		m_cRefCount(1),
		m_pFontFile(pFontFile),
		m_count(0)
	{
		if (m_pFontFile)
			m_pFontFile->AddRef();
	}

private:
	~CFontEnum() {
		if (m_pFontFile)
			m_pFontFile->Release();
	}

private:
	ULONG                       m_cRefCount;
	IDWriteFontFile             *m_pFontFile;
	UINT                        m_count;

private:
	CFontEnum(const CFontEnum&);
	CFontEnum& operator=(const CFontEnum&);
};

// Font collection loader for a single font
class CCollectionLoader : public IDWriteFontCollectionLoader {
public:
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject) {
		if (ppvObject == NULL)
			return E_INVALIDARG;

		if (IsEqualIID(riid, __uuidof(IUnknown))) {
			*ppvObject = static_cast<IUnknown*>(this);
			AddRef();
			return S_OK;
		}
		else if (IsEqualIID(riid, __uuidof(IDWriteFontCollectionLoader))) {
			*ppvObject = static_cast<IDWriteFontCollectionLoader*>(this);
			AddRef();
			return S_OK;
		}

		*ppvObject = NULL;
		return E_NOINTERFACE;
	}

	virtual ULONG STDMETHODCALLTYPE AddRef() {
		return static_cast<ULONG>(InterlockedIncrement(reinterpret_cast<LONG*>(&m_cRefCount)));
	}

	virtual ULONG STDMETHODCALLTYPE Release() {
		ULONG newCount = static_cast<ULONG>(InterlockedDecrement(reinterpret_cast<LONG*>(&m_cRefCount)));

		if (newCount == 0)
			delete this;

		return newCount;
	}

	virtual HRESULT STDMETHODCALLTYPE CreateEnumeratorFromKey(
		IDWriteFactory *pFactory,
		const void *collectionKey,
		UINT32 collectionKeySize,
		IDWriteFontFileEnumerator **ppFontFileEnumerator
		) {
		collectionKey;
		collectionKeySize;

		if (pFactory == NULL || ppFontFileEnumerator == NULL)
			return E_INVALIDARG;

		IDWriteFontFile *pFontFile;
		HRESULT hResult = pFactory->CreateFontFileReference(m_filepath.c_str(), NULL, &pFontFile);
		if (FAILED(hResult))
			return hResult;

		CFontEnum *pEnum = new CFontEnum(pFontFile);
		*ppFontFileEnumerator = pEnum;

		pFontFile->Release();

		return S_OK;
	}

public:
	CCollectionLoader(const WCHAR *szFontfilePath) :
		m_cRefCount(1),
		m_filepath(szFontfilePath)
	{
	}

private:
	~CCollectionLoader() {
	}

private:
	ULONG                       m_cRefCount;
	std::wstring                m_filepath;

private:
	CCollectionLoader(const CCollectionLoader&);
	CCollectionLoader& operator=(const CCollectionLoader&);
};
