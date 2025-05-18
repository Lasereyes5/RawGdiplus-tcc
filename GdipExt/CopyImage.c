GpBitmap *GdipCopyImage(GpImage *img){
	UINT uWidth,uHeight;
	GdipGetImageWidth(img, &uWidth);
	GdipGetImageHeight(img, &uHeight);
	
	GpGraphics *resultGraphics;
	GpBitmap *resultBitmap = NULL;
	
	GdipCreateBitmapFromScan0(uWidth, uHeight, 0, GpPixelFormat32bppARGB, NULL, &resultBitmap);
	GdipGetImageGraphicsContext(resultBitmap,&resultGraphics);
	
	/*GdipDrawImageRectRectI(
		resultGraphics,
		img,
		0,0,uWidth, uHeight,
		0,0,uWidth, uHeight,
		GpUnitPixel,
		NULL,NULL,NULL
	);*/
	GdipDrawImageRectI(resultGraphics,img,0,0,uWidth, uHeight);
	
	GdipDeleteGraphics(resultGraphics);
	return resultBitmap;
}