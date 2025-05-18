//~ #define WIN32_LEAN_AND_MEAN
#define _UNICODE 1
#define UNICODE 1
#include <stdio.h>
#include <Windows.h>
#include <shellapi.h>
#include <OleAuto.h>

#include "tccFix.h"
#include <objbase.h>
#pragma comment(lib,"gdiplus")

//#define GDIPVER 0x0110
#include "RawGdiplus.h"

//for setting language
#include <winnt.h>

#include "GdipExt/DrawImageUnscaled.c"

#include "GdipExt/GetEncoderClsid.c"
#include "GdipExt/SaveImage.c"
#include "GdipExt/CopyImage.c"
//~ #define POUT(p) printf(#p"=%p\n",p);
int wmain(int argc, wchar_t *argv[]){
	ULONG_PTR token;
	GdiplusStartupInput gsi = { 1, };
	GdiplusStartup(&token, &gsi, NULL);
	
	
	GpBitmap *bmp;{
		GpBitmap *pBmpFile;
		GdipCreateBitmapFromFile(L"tree.png", &pBmpFile);
		bmp=GdipCopyImage(pBmpFile);
		GdipDisposeImage(pBmpFile);
	}
	
	GpGraphics *g;
	GdipGetImageGraphicsContext(bmp,&g);
	
	GpFont *f;{
		GpFontFamily *ff;
		GdipCreateFontFamilyFromName(L"Microsoft YaHei UI",NULL,&ff);
		GdipCreateFont(ff, 24, GpFontStyleBold, GpUnitPixel, &f);
		GdipDeleteFontFamily(ff);
	}
	
	//~ GdipDrawString(GpGraphics*,GDIPCONST WCHAR*,INT,GDIPCONST GpFont*,GDIPCONST RectF*,GDIPCONST GpStringFormat*,GDIPCONST GpBrush*);
	GpRectF rect={100.0f,40.0f,0.0f,0.0f};
	GpStringFormat *sf = NULL;
		GdipCreateStringFormat(0, LANG_NEUTRAL, &sf);
		GdipSetStringFormatAlign(sf, GpStringAlignmentCenter);
	GpSolidFill *sb = NULL;
		GdipCreateSolidFill(0xFF000000, &sb);
	
	GdipDrawString(g,L"test text",-1,f,&rect,sf,sb);
	GdipDeleteBrush(sb);
	GdipDeleteFont(f);
	GdipDeleteStringFormat(sf);
	
	GdipSaveImage(bmp,L"test.png",Png);
	GdipDisposeImage(bmp);
	GdipDeleteGraphics(g);
	
	GdiplusShutdown(token);
	return 0;
}
