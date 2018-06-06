// ImageProcessingProject.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 
#include "BMPRead.h"
#include "Function.h"
int main(int argc, char *argv[])
{
	
	FILE *inFile, *outFile;
	HEADER *pHeader;
	INFOHEADER *pInfoHeader;
	PIXEL *pPixel, **pImage;
	PIXEL ** pCopy;
	pHeader = (HEADER *)malloc(sizeof(HEADER));
	pInfoHeader = (INFOHEADER *)malloc(sizeof(INFOHEADER));
	pPixel = (PIXEL *)malloc(sizeof(PIXEL));
	inFile = fopen("SwietoTygrysow.bmp", "rb");
	if (inFile == NULL)
	{
		printf("Can't open input file for reading.\n");
		return 1;
	}
	pHeader = Read_BMP_Header(inFile, pHeader);
	pInfoHeader = Read_BMP_Info(inFile, pInfoHeader);
	pImage = (PIXEL **)malloc(sizeof(PIXEL *) * pInfoHeader->Height);
	pImage = Read_BMP_Pixel(inFile, pHeader, pInfoHeader, pPixel, pImage);
	pCopy = (PIXEL **)malloc(sizeof(PIXEL *) * pInfoHeader->Height);
	pCopy = Read_BMP_Pixel(inFile, pHeader, pInfoHeader, pPixel, pCopy);
	outFile = fopen("Wyjscie1.bmp", "wb");
	//Convert_to_Black(pInfoHeader, pImage);
	//Convert_to_Sepia(pInfoHeader, pImage);
	//Inversion(pInfoHeader, pImage);
	unsigned char contrast = 100;
	//Brightness(pInfoHeader, pImage, change);
	//Contrast(pInfoHeader, pImage, contrast);
	Smooth(pInfoHeader, pImage, pCopy);
	//LaplaceEdge(pInfoHeader, pImage, pCopy);
	if (outFile == NULL)
	{
		printf("Can't open output file for writing.\n");
		return 1;
	}
	WriteBMP(outFile, pHeader, pInfoHeader,pPixel, pCopy);
	fclose(inFile);
	fclose(outFile);

	for (int i = 0; i < pInfoHeader->Height; i++)
	{
		free(pImage[i]);
	}
	for (int i = 0; i < pInfoHeader->Height; i++)
	{
		free(pCopy[i]);
	}
	free(pCopy);
	free(pImage);
	free(pHeader);
	free(pInfoHeader);
	free(pPixel);
	_CrtDumpMemoryLeaks(); //biblioteka VS do sprawdzania wyciekow
	return 0;
}


