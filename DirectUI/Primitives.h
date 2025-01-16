#pragma once

namespace DirectUI
{
	
	struct Fill
	{
		unsigned char dType;
		struct
		{
			COLORREF cr;
			COLORREF cr2;
			COLORREF cr3;
		} ref;
		struct
		{
			UINT uType;
			UINT uState;
		} fillDFC;
		struct
		{
			wchar_t* pszClassName;
			int iPartId;
			int iStateId;
		} fillDTB;
	};

	struct Cursor
	{
		HICON hCursor;
	};

	struct Graphic
	{
		void* hImage;
		void* hAltImage;
		unsigned short cx;
		unsigned short cy;
		struct
		{
			unsigned char dImgType:3;
			unsigned char dMode:4;
			bool bFlip:1;
			bool bRTLGraphic:1;
			bool bFreehImage:1;
			bool bSharedResource:1;
			unsigned char dAlpha;
			struct
			{
				unsigned char r:8;
				unsigned char g:8;
				unsigned char b:8;
			} rgbTrans;
		} BlendMode;
		HINSTANCE hResLoad;
		wchar_t* lpszName;
		ScaledSIZE scaledSize;
		float fScaleFactor;
	};


	struct EnumMap
	{
		wchar_t* pszEnum;
		int nEnum;
	};

	struct PropertyInfo
	{
		wchar_t* name;
		UINT64 unk1;
		struct PropCapability {
			ValueType type : 6;
			UINT other : 26;
			UINT unk;
		} *cap;
		struct { UCString str_value; int int_value; } *enum_value_map;
		Value *(*get_default_value)();
		UINT64 *unk2;
	};

	struct UILIB_API NavReference
	{
	public:
		NavReference() = delete;
		NavReference(const NavReference&) = delete;
		~NavReference() = delete;

		void Init(Element *, RECT *);
		NavReference& operator=(NavReference const &);
	};
}