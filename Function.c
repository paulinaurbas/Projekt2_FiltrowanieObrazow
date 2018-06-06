#include "BMPRead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 
int normalize(int t)
{
	int temp = t;
	if (t > 255)
	{
		temp = temp - abs(temp - 255);
		return temp;
	}
	else
	{
		return t;
	}
}
void Convert_to_Sepia(INFOHEADER *pInfoHeader, PIXEL **pImage)
{
	for (int i = 0; i < pInfoHeader->Height; i++)
	{
		for (int j = 0; j < pInfoHeader->Width; j++)
		{
			unsigned char Blue = pImage[i][j].Blue;
			unsigned char Green = pImage[i][j].Green;
			unsigned char Red = pImage[i][j].Red;
			pImage[i][j].Red = normalize(Red*100/255+Green*196/255+Blue*48/255);
			pImage[i][j].Green = normalize(Red * 88 / 255 + Green * 174 / 255 + Blue * 42 / 255);
			pImage[i][j].Blue = normalize(Red * 69/ 255 + Green * 136 / 255 + Blue * 33 / 255);
		
		}
	}
}
void Convert_to_Black(INFOHEADER *pInfoHeader, PIXEL **pImage)
{
	for (int i = 0; i < pInfoHeader->Height; i++)
	{
		for (int j = 0; j < pInfoHeader->Width; j++)
		{
			unsigned char Red = pImage[i][j].Red;
			unsigned char Green = pImage[i][j].Green;
			unsigned char Blue = pImage[i][j].Blue;
			unsigned char convert = (Red + Blue + Green) / 3;
			pImage[i][j].Red = convert;
			pImage[i][j].Green = convert;
			pImage[i][j].Blue = convert;
			//pImage[i][j].junk = convert;
		}
	}
}
void Convert_to_Red(INFOHEADER *pInfoHeader, PIXEL **pImage)
{
	for (int i = 0; i < pInfoHeader->Height; i++)
	{
		for (int j = 0; j < pInfoHeader->Width; j++)
		{
			pImage[i][j].Green = 0;
			pImage[i][j].Blue = 0;
		}
	}
}
void Inversion(INFOHEADER *pInfoHeader, PIXEL **pImage)
{
	for (int i = 0; i < pInfoHeader->Height; i++)
	{
		for (int j = 0; j < pInfoHeader->Width; j++)
		{
			pImage[i][j].Green = 255 - pImage[i][j].Green;
			pImage[i][j].Blue = 255 - pImage[i][j].Blue;
			pImage[i][j].Red = 255 - pImage[i][j].Red;
		}
	}
}
void Brightness(INFOHEADER *pInfoHeader, PIXEL **pImage, char change )
{
	for (int i = 0; i < pInfoHeader->Height; i++)
	{
		for (int j = 0; j < pInfoHeader->Width; j++)
		{
			unsigned char Red = pImage[i][j].Red;
			unsigned char Green = pImage[i][j].Green;
			unsigned char Blue = pImage[i][j].Blue;
			Red =normalize(Red+change);
			Green = normalize(Green+ change);
			Blue = normalize (Blue+change);
			pImage[i][j].Red = normalize(Red);
			pImage[i][j].Green = normalize(Green);
			pImage[i][j].Blue = normalize(Blue);
		}
	}
}
void Contrast(INFOHEADER *pInfoHeader, PIXEL **pImage, unsigned char contrast)
{
	for (int i = 0; i < pInfoHeader->Height; i++)
	{
		for (int j = 0; j < pInfoHeader->Width; j++)
		{
			unsigned char Red = pImage[i][j].Red;
			unsigned char Green = pImage[i][j].Green;
			unsigned char Blue = pImage[i][j].Blue;
			unsigned char factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
			Red = normalize(factor * (Red - 128) + 128);
			Green = normalize(factor * (Green - 128) + 128);
			Blue = normalize(factor * (Blue - 128) + 128);
			pImage[i][j].Red = Red;
			pImage[i][j].Green = Green;
			pImage[i][j].Blue = Blue;
		}
	}
}
void corner1(INFOHEADER * pInforHeader, PIXEL ** pImage)
{
	pImage[0][0].Red = (pImage[0][0].Red + pImage[1][1].Red + pImage[0][1].Red + pImage[1][0].Red)/4;
	pImage[0][0].Blue =(pImage[0][0].Blue + pImage[1][1].Blue+ pImage[0][1].Blue + pImage[1][0].Blue)/4;
	pImage[0][0].Green = (pImage[0][0].Green + pImage[1][1].Green + pImage[0][1].Green + pImage[1][0].Green)/4;
}
void middle(INFOHEADER * pInforHeader, PIXEL ** pImage, PIXEL ** Copy)
{
	int m = pInforHeader->Height;
	int n = pInforHeader->Width;
	for (int i = 1; i < m-1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			Copy[i][j].Red = (pImage[i - 1][j - 1].Red + pImage[i - 1][j].Red + pImage[i - 1][j + 1].Red + pImage[i][j - 1].Red + pImage[i][j].Red + pImage[i][j + 1].Red + pImage[i + 1][j - 1].Red + pImage[i + 1][j].Red + pImage[i + 1][j + 1].Red) / 9;
			Copy[i][j].Blue = (pImage[i - 1][j - 1].Blue + pImage[i - 1][j].Blue + pImage[i - 1][j + 1].Blue + pImage[i][j - 1].Blue + pImage[i][j].Blue + pImage[i][j + 1].Blue + pImage[i + 1][j - 1].Blue + pImage[i + 1][j].Blue + pImage[i + 1][j + 1].Blue) / 9;
			Copy[i][j].Green = (pImage[i - 1][j - 1].Green + pImage[i - 1][j].Green + pImage[i - 1][j + 1].Green + pImage[i][j - 1].Green + pImage[i][j].Green + pImage[i][j + 1].Green + pImage[i + 1][j - 1].Green + pImage[i + 1][j].Green + pImage[i + 1][j + 1].Green) / 9;
		}
		}
}
void side1(INFOHEADER * pInforHeader, PIXEL ** pImage)
{
	int n = pInforHeader->Width;
	for (int i = 1; i < n - 1; i++)
	{
		pImage[0][i].Red = (pImage[0][i - 1].Red + pImage[0][i].Red + pImage[0][i + 1].Red + pImage[1][i - 1].Red + pImage[1][i].Red + pImage[1][i + 1].Red)/6;
		pImage[0][i].Blue = (pImage[0][i - 1].Blue+ pImage[0][i].Blue + pImage[0][i + 1].Blue + pImage[1][i - 1].Blue + pImage[1][i].Blue + pImage[1][i + 1].Blue) / 6;
		pImage[0][i].Green = (pImage[0][i - 1].Green + pImage[0][i].Green+ pImage[0][i + 1].Green + pImage[1][i - 1].Green + pImage[1][i].Green + pImage[1][i + 1].Green) / 6;
	}
	/*int m = pInforHeader->Height;
	int n = pInforHeader->Width;
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (i >= 1 && j <= 0)
			{
				pImage[i][j].Red = (pImage[i-1][j].Red + pImage[i + 1][j].Red + pImage[i][j + 1].Red) / 3;
				pImage[i][j].Blue = (pImage[i - 1][j].Blue + pImage[i + 1][j].Blue + pImage[i][j + 1].Blue) / 3;
				pImage[i][j].Green = (pImage[i - 1][j].Green + pImage[i + 1][j].Green + pImage[i][j + 1].Green) / 3;
			}
		}
	}*/
}
void corner2(INFOHEADER * pInforHeader, PIXEL ** pImage) {
	int m = pInforHeader->Height;
	pImage[0][m-1].Red = (pImage[0][m-1].Red + pImage[1][m-2].Red + pImage[0][m-1].Red + pImage[1][m-2].Red) / 4;
	pImage[0][m-1].Blue = (pImage[0][m-1].Blue + pImage[1][m-2].Blue + pImage[0][m-1].Blue + pImage[1][m-2].Blue) / 4;
	pImage[0][0].Green = (pImage[0][m-1].Green + pImage[1][m-2].Green + pImage[0][m-1].Green + pImage[1][m-2].Green) / 4;
}
void side3(INFOHEADER * pInforHeader, PIXEL ** pImage) {
	int m = pInforHeader->Height;
	for (int i = 1; i < m - 1; i++)
	{
		
			pImage[i][0].Red = (pImage[i-1][0].Red + pImage[i-1][1].Red + pImage[i][0].Red + pImage[i][1].Red + pImage[i+1][0].Red + pImage[i+1][1].Red) / 6;
			pImage[i][0].Blue = (pImage[i-1][0].Blue + pImage[i-1][1].Blue + pImage[i][0].Blue + pImage[i][1].Blue + pImage[i+1][1].Blue + pImage[i+1][1].Blue) / 6;
			pImage[i][0].Green = (pImage[i-1][0].Green + pImage[i-1][1].Green + pImage[1][0].Green + pImage[i][1].Green + pImage[i+1][1].Green + pImage[i+1][1].Green) / 6;
	}
}
void corner3(INFOHEADER * pInforHeader, PIXEL ** pImage) {
	int m = pInforHeader->Height;
	for (int i = 1; i < m - 1; i++)
	{

		pImage[0][m - 1].Red = (pImage[0][m - 2].Red + pImage[1][m - 2].Red + pImage[0][m - 1].Red + pImage[1][m - 1].Red) / 4;
		pImage[0][m - 1].Blue = (pImage[0][m-2].Blue + pImage[1][m-2].Blue + pImage[0][m-1].Blue + pImage[1][m-1].Blue ) / 4;
		pImage[0][m-1].Green = (pImage[0][m-2].Green + pImage[1][m-2].Green + pImage[0][m-1].Green + pImage[1][m-1].Green) / 4;
	}
}
void corner4(INFOHEADER * pInforHeader, PIXEL ** pImage) {
	int m = pInforHeader->Height;
	int n = pInforHeader->Width;
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			pImage[m-1][n-1].Red = (pImage[m-2][n - 2].Red + pImage[m-2][n-1].Red + pImage[m-1][n-2].Red + pImage[m-1][n-1].Red) / 4;
			pImage[m-1][n - 1].Blue = (pImage[m-2][n - 2].Blue + pImage[m-2][n- 2].Blue + pImage[m-1][n - 2].Blue + pImage[m-1][n - 1].Blue) / 4;
			pImage[m-1][n - 1].Green = (pImage[m-2][n - 2].Green + pImage[m-2][n - 2].Green + pImage[m-1][n-2].Green + pImage[m-1][n - 1].Green) / 4;
		}
	}
}
void side4(INFOHEADER * pInforHeader, PIXEL ** pImage)
{
	int n = pInforHeader->Width;
	int m = pInforHeader->Height;
	for (int i = 1; i < n - 1; i++)
	{
		pImage[m-1][i].Red = (pImage[m-1][i - 1].Red + pImage[m-1][i].Red + pImage[m-1][i + 1].Red + pImage[m-2][i - 1].Red + pImage[m-2][i].Red + pImage[m-2][i + 1].Red) / 6;
		pImage[m-1][i].Blue = (pImage[m-1][i - 1].Blue + pImage[m-1][i].Blue + pImage[m-1][i + 1].Blue + pImage[m-2][i - 1].Blue + pImage[m-2][i].Blue + pImage[m-2][i + 1].Blue) / 6;
		pImage[m-1][i].Green = (pImage[m-1][i - 1].Green + pImage[m-1][i].Green + pImage[m-1][i + 1].Green + pImage[m-2][i - 1].Green + pImage[m-2][i].Green + pImage[m-2][i + 1].Green) / 6;
	}
}
void side2(INFOHEADER * pInforHeader, PIXEL ** pImage)
{
	int n = pInforHeader->Width;
	int m = pInforHeader->Height;
	for (int i = 1; i < m - 1; i++)
	{

		pImage[i][m - 1].Red = (pImage[i-1][m - 2].Red + pImage[i-1][m - 1].Red + pImage[i][m - 2].Red + pImage[i][m - 1].Red + pImage[i+1][m -2].Red+ pImage[i+1][m - 1].Red) / 6;
		pImage[i][m - 1].Blue = (pImage[i-1][m - 2].Blue + pImage[i-1][m - 1].Blue + pImage[i][m - 2].Blue + pImage[i][m - 1].Blue+ pImage[i+1][m -2].Blue+ pImage[i+1][m - 1].Blue) / 6;
		pImage[i][m - 1].Green = (pImage[i-1][m - 2].Green + pImage[i-1][m - 1].Green + pImage[i][m - 2].Green + pImage[i][m - 1].Green+ pImage[i+1][m - 2].Green + pImage[i+1][m - 1].Green) / 6;
	}
}
void CopyPixel(INFOHEADER *pInfoHeader, PIXEL **pImage, PIXEL ** copy)
{
	for (int i = 0; i < pInfoHeader->Height; i++)
	{
		for (int j = 0; j < pInfoHeader->Width; j++)
		{
			copy[i][j].Red = pImage[i][j].Red;
			copy[i][j].Green= pImage[i][j].Green;
			copy[i][j].Blue = pImage[i][j].Blue;
		}
	}
}
void Smooth(INFOHEADER *pInfoHeader, PIXEL **pImage, PIXEL ** Copy)
{
	/*corner1(pInfoHeader, pImage);
	corner2(pInfoHeader, pImage);
	corner3(pInfoHeader, pImage);
	corner4(pInfoHeader, pImage);
	side1(pInfoHeader, pImage);
	side2(pInfoHeader, pImage);
	side3(pInfoHeader, pImage);
	side4(pInfoHeader, pImage);
	*/
	middle(pInfoHeader, pImage, Copy);
}
void LaplaceEdge(INFOHEADER *pInfoHeader, PIXEL **pImage, PIXEL ** copy)
{
	int m = pInfoHeader->Height;
	int n = pInfoHeader->Width;
	for (int i = 1; i < m - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			copy[i][j].Red = normalize((pImage[i - 1][j - 1].Red*0+ pImage[i - 1][j].Red*(-1) + pImage[i - 1][j + 1].Red*0 + pImage[i][j - 1].Red*(-1) + pImage[i][j].Red*(4) + (-1)*pImage[i][j + 1].Red + 0*pImage[i + 1][j - 1].Red + (-1)*pImage[i + 1][j].Red + 0*pImage[i + 1][j + 1].Red)/9) ;
			copy[i][j].Blue = normalize((pImage[i - 1][j - 1].Blue*0 + pImage[i - 1][j].Blue*(-1) + pImage[i - 1][j + 1].Blue*(0) + pImage[i][j - 1].Blue*(-1) + pImage[i][j].Blue*4 + pImage[i][j + 1].Blue*(-1) + pImage[i + 1][j - 1].Blue*(0) + pImage[i + 1][j].Blue*(-1) + pImage[i + 1][j + 1].Blue*(0))/9) ;
			copy[i][j].Green = normalize((pImage[i - 1][j - 1].Green*(0) + pImage[i - 1][j].Green*(-1) + pImage[i - 1][j + 1].Green*(0) + pImage[i][j - 1].Green*(-1) + pImage[i][j].Green*(4) + pImage[i][j + 1].Green*(-1) + pImage[i + 1][j - 1].Green*(0) + pImage[i + 1][j].Green*(-1) + pImage[i + 1][j + 1].Green*(0))/9) ;
		}
	}
}