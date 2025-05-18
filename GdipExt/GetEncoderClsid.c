typedef enum GpFormatIndex{
	Bmp,
	Jpeg,
	Gif,
	Emf,
	Wmf,
	Tiff,
	Png,
	Icon
}GpFormatIndex;
wchar_t *GpFormatWstr[]={
	L"image/bmp",
	L"image/jpeg",
	L"image/gif",
	L"image/x-emf",
	L"image/x-wmf",
	L"image/tiff",
	L"image/png",
	L"image/x-icon"
};
INT GdipGetEncoderClsid(const WCHAR *format, CLSID *pClsid)    
{    
	UINT  num = 0;          // number of image encoders      
	UINT  size = 0;         // size of the image encoder array in bytes      

	GdipGetImageEncodersSize(&num, &size);     
	if(size == 0)     
		return -1;  // Failure      

	GpImageCodecInfo* pImageCodecInfo = NULL;     
	pImageCodecInfo = (GpImageCodecInfo*)(malloc(size));     
	if(pImageCodecInfo == NULL)     
		return -1;  // Failure      

	GdipGetImageEncoders(num, size, pImageCodecInfo);     

	for(UINT j = 0; j < num; ++j)     
	{     
		if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )     
		{     
			*pClsid = pImageCodecInfo[j].Clsid;     
			free(pImageCodecInfo);     
			return j;  // Success      
		}         
	}     

	free(pImageCodecInfo);     
	return -1;  // Failure     
}    

/*INT GetEncoderClsid(const WCHAR *format, CLSID *pClsid)    
{    
	UINT  num = 0;          // number of image encoders      
	UINT  size = 0;         // size of the image encoder array in bytes      

	ImageCodecInfo* pImageCodecInfo = NULL;     

	GetImageEncodersSize(&num, &size);     
	if(size == 0)     
		return -1;  // Failure      

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));     
	if(pImageCodecInfo == NULL)     
		return -1;  // Failure      

	GetImageEncoders(num, size, pImageCodecInfo);     

	for(UINT j = 0; j < num; ++j)     
	{     
		if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )     
		{     
			*pClsid = pImageCodecInfo[j].Clsid;     
			free(pImageCodecInfo);     
			return j;  // Success      
		}         
	}     

	free(pImageCodecInfo);     
	return -1;  // Failure     
}    */
