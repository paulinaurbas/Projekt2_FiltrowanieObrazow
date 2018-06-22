#include "BMPRead.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 
int normalizeSepia(int t)
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
void Convert_to_Sepia(Image * pImage)
{
	for (int i = 0; i < pImage->Info->Height; i++)
	{
		for (int j = 0; j < pImage->Info->Width; j++)
		{
			unsigned char Blue = pImage->pPixel[i][j].Blue;
			unsigned char Green = pImage->pPixel[i][j].Green;
			unsigned char Red = pImage->pPixel[i][j].Red;
			pImage->pCopy[i][j].Red = normalizeSepia(Red*100/255+Green*196/255+Blue*48/255);
			pImage->pCopy[i][j].Green = normalizeSepia(Red * 88 / 255 + Green * 174 / 255 + Blue * 42 / 255);
			pImage->pCopy[i][j].Blue = normalizeSepia(Red * 69/ 255 + Green * 136 / 255 + Blue * 33 / 255);
		
		}
	}
}
void Convert_to_Black(Image * pImage)
{
	for (int i = 0; i < pImage->Info->Height; i++)
	{
		for (int j = 0; j < pImage->Info->Width; j++)
		{
			unsigned char Red = pImage->pPixel[i][j].Red;
			unsigned char Green = pImage->pPixel[i][j].Green;
			unsigned char Blue = pImage->pPixel[i][j].Blue;
			unsigned char convert = (Red + Blue + Green) / 3;
			pImage->pCopy[i][j].Red = convert;
			pImage->pCopy[i][j].Green = convert;
			pImage->pCopy[i][j].Blue = convert;
		}
	}
}
void Convert_to_Red(Image * pImage)
{
	for (int i = 0; i < pImage->Info->Height; i++)
	{
		for (int j = 0; j < pImage->Info->Width; j++)
		{
			pImage->pCopy[i][j].Green = 0;
			pImage->pCopy[i][j].Blue = 0;
		}
	}
}
void Inversion(Image * pImage)
{
	for (int i = 0; i < pImage->Info->Height; i++)
	{
		for (int j = 0; j <pImage->Info->Width; j++)
		{
			pImage->pCopy[i][j].Green = 255 - pImage->pPixel[i][j].Green;
			pImage->pCopy[i][j].Blue = 255 - pImage->pPixel[i][j].Blue;
			pImage->pCopy[i][j].Red = 255 - pImage->pPixel[i][j].Red;
		}
	}
}
void Brightness(Image * pImage, char change )
{
	for (int i = 0; i < pImage->Info->Height; i++)
	{
		for (int j = 0; j <pImage->Info->Width; j++)
		{
			unsigned char Red = pImage->pPixel[i][j].Red;
			unsigned char Green = pImage->pPixel[i][j].Green;
			unsigned char Blue = pImage->pPixel[i][j].Blue;
			Red =normalizeSepia(Red+change);
			Green = normalizeSepia(Green+ change);
			Blue = normalizeSepia(Blue+change);
			pImage->pCopy[i][j].Red = normalizeSepia(Red);
			pImage->pCopy[i][j].Green = normalizeSepia(Green);
			pImage->pCopy[i][j].Blue = normalizeSepia(Blue);
		}
	}
}
void Contrast(Image * pImage, unsigned char contrast)
{
	for (int i = 0; i < pImage->Info->Height; i++)
	{
		for (int j = 0; j < pImage->Info->Width; j++)
		{
			unsigned char Red = pImage->pPixel[i][j].Red;
			unsigned char Green = pImage->pPixel[i][j].Green;
			unsigned char Blue = pImage->pPixel[i][j].Blue;
			unsigned char factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
			Red = normalizeSepia(factor * (Red - 128) + 128);
			Green = normalizeSepia(factor * (Green - 128) + 128);
			Blue = normalizeSepia(factor * (Blue - 128) + 128);
			pImage->pCopy[i][j].Red = Red;
			pImage->pCopy[i][j].Green = Green;
			pImage->pCopy[i][j].Blue = Blue;
		}
	}
}
void middle(Image * pImage)
{
	int m = pImage->Info->Height;
	int n = pImage->Info->Width;
	char r, g, b;
	float rtotal, gtotal, btotal;
	for (int x = 1; x < m - 1; x++)
	{
		for (int y = 1; y < n - 1; y++)
		{
			rtotal = 0.0;
			gtotal = 0.0;
			btotal = 0.0;
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					r = pImage->pPixel[i + x][j + y].Red;
					g = pImage->pPixel[i + x][j + y].Green;
					b = pImage->pPixel[i + x][j + y].Blue;
					rtotal += r;
					gtotal += g;
					btotal += b;
				}
			}
			pImage->pCopy[x][y].Red = rtotal/9;
			pImage->pCopy[x][y].Green = gtotal/9;
			pImage->pCopy[x][y].Blue = btotal/9;
		}
		}
}
void Smooth(Image * pImage)
{
	middle(pImage);
}
int ** KernelLaplace()
{
	int Laplace[3][3] = { { 0,-1,0 },{ -1,4,-1 },{ 0,-1,0 } };
	return Laplace;
}
void ApplyKerneltoImage(Image * pImage)
{
	char r, g, b;
	float rtotal, gtotal, btotal;
	int Kernel[3][3] = { { 0,-1,0 },{ -1,4,-1 },{ 0,-1,0 } };
	int m = pImage->Info->Height;
	int n = pImage->Info->Width;
	for (int x = 1; x < m - 1; x++)
	{
		for (int y = 1; y < n - 1; y++)
		{
			rtotal = 0.0;
			gtotal = 0.0;
			btotal = 0.0;
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					r = pImage->pPixel[i + x][j + y].Red;
					g = pImage->pPixel[i + x][j + y].Green;
					b = pImage->pPixel[i + x][j + y].Blue;
					rtotal += r*Kernel[i + 1][j + 1];
					gtotal += r*Kernel[i + 1][j + 1];
					btotal += r*Kernel[i + 1][j + 1];
				}
			}
			pImage->pCopy[x][y].Red = rtotal;
			pImage->pCopy[x][y].Green = gtotal;
			pImage->pCopy[x][y].Blue = btotal;
		}
	}
}
void LaplaceEdge(Image * pImage)
{
	ApplyKerneltoImage(pImage);
}