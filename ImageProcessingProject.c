// ImageProcessingProject.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 
#include "BMPRead.h"
#include "Function.h"
#include "User.h"
int main(int argc, char *argv[])
{
	Image * readyImage = (Image*)malloc(sizeof(Image));
	if (argc >= 5 && strcmp(argv[1], "-i")==0 && strcmp(argv[3], "-o") == 0) {
		BMPtoImage(argv[2], readyImage);
		printf("Podaj liczbe: ");
		int number = 0; 
		getchar(&number);
		unsigned char changenumber = 0;
		printf("%d", &number);
		switch (number)
		{
		case 1:
			Convert_to_Black(readyImage);
			break;
		case 2:
			Convert_to_Sepia(readyImage);
			break;
		case 3:
			Inversion(readyImage, changenumber);
			break;
		case 4:
			printf_s("Wybierz jasnosc: ");
			scanf_s("%d", &changenumber);
			Brightness(readyImage, changenumber);
			break;
		case 5:
			printf_s("Wybierz kontrast: ");
			scanf_s("%d", &changenumber);
			Contrast(readyImage, changenumber);
			break;
		case 6:
			Smooth(readyImage);
			break;
		case 7:
			LaplaceEdge(readyImage);
			break;
		}
		WriteBMP(argv[4], readyImage);
		DeleteImage(readyImage);
		free(readyImage);
		_CrtDumpMemoryLeaks();
		return 0;

	}
	else
	{
		Help();
		return 0;
	}
}