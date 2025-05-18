GpStatus GdipDrawImageUnscaledI(GpGraphics *g,GpImage *img,INT x,INT y){
	UINT uWidth, uHeight;
	GdipGetImageWidth(img, &uWidth);
	GdipGetImageHeight(img, &uHeight);
	return GdipDrawImageRectI(g,img,x,y,uWidth, uHeight);
}