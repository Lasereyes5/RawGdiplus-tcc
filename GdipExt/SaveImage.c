GpStatus GdipSaveImage(GpImage *img,LPWSTR savePath,GpFormatIndex index){
	CLSID imgClsid;
	GdipGetEncoderClsid(GpFormatWstr[index],&imgClsid);
	return GdipSaveImageToFile(img, savePath, &imgClsid, NULL);
}