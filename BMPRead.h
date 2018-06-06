#pragma once
#ifndef BMPRead_H
#define BMPRead_H
#include <stdint.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//24 bity, mo¿e byæ sepia i negatyw 
typedef struct
{
	short Signature;
	long Reserved1;
	long Reserved2;
	long DataOffSet;
} HEADER;
typedef struct
{
	long Size;
	long Width;
	long Height;
	short Planes;
	short BitsPerPixel;
	long Compression;
	long SizeImage;
	long XPixelsPreMeter;
	long YPixelsPreMeter;
	long ColorsUsed;
	long ColorsImportant;
} INFOHEADER;
typedef struct
{
	unsigned char Red, Green, Blue;

} PIXEL;
/** Function reading in binary from file to structure Header
@author Paulina Urbas
@date 2.05.2018
@param inFile, pHeader
@return Header *
*/
HEADER * Read_BMP_Header(FILE * inFile, HEADER *pHeader);
/** Function reading in binary file to structure Infoheader
@author Paulina Urbas
@date 2.05.2018
@param inFile, pInfoHeader
@return INFOHEADER *
*/
INFOHEADER * Read_BMP_Info(FILE * inFile, INFOHEADER * pInfoHeader);
/** Function reading PIXELS from file to structure PIXEL **
@author Paulina Urbas
@date 2.05.2018
@param inFile, *pHeader, *pInfoHeader, *pPixel, **pImage
@return Header *
*/
PIXEL ** Read_BMP_Pixel(FILE * inFile, HEADER *pHeader, INFOHEADER *pInfoHeader, PIXEL *pPixel, PIXEL **pImage);
/**  Function writing structure Header to file
@author Paulina Urbas
@date 6.06.2018
@param outFile, *pHeader
*/
void Write_BMP_Header(FILE * outFile, HEADER *pHeader);
/**  Function writing structure InfoHeader o file
@author Paulina Urbas
@date 6.06.2018
@param outFile *pInfoHeader
*/
void Write_BMP_Info(FILE * outFile, INFOHEADER * pInfoHeader);
/**  Function writing structure PIXEL to file
@author Paulina Urbas
@date 6.06.2018
@param outFile, *pHeader, *pInfoHeader, *pPixel, **pImage
*/
void Write_BMP_Pixel(FILE * outFile, HEADER *pHeader, INFOHEADER *pInfoHeader, PIXEL *pPixel, PIXEL **pImage);
/**  Function writing structures Header, InfoHeader, PIXEL to file
@author Paulina Urbas
@date 2.05.2018
@param outFile, *pHeader, *pInfoHeader, *pPixel, **pImage
@return PIXEL **
*/
void WriteBMP(FILE * outFile, HEADER *pHeader, INFOHEADER *pInfoHeader, PIXEL *pPixel, PIXEL **pImage);

#endif