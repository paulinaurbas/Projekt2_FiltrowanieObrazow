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
	{
		if (TerminalCheck(argc, argv, readyImage) == 0) //check terminal
		{
			if (BMPtoImage(argv[2], readyImage) == 0) //wczytanie obrazu źle
			{
				ErrorInfo();
				Help();
				free(readyImage);
				/*_CrtDumpMemoryLeaks();
				return 0;*/
			}
			else
			{
				if (Filtr(argv, readyImage) == 1) //wczytywanie flitra z bledem
				{
					Help();
					DeleteImage(readyImage);
					free(readyImage);
					/*_CrtDumpMemoryLeaks();
					return 0;*/
				}
				else //poprawne
				{
					WriteBMP(argv[4], readyImage);
					DeleteImage(readyImage);
					free(readyImage);
					/*_CrtDumpMemoryLeaks();
					return 0;*/
				}
			}
		}
			else
			{
				Help();
				free(readyImage);
				/*_CrtDumpMemoryLeaks();
				return 0;*/
			}
		}
	_CrtDumpMemoryLeaks();
	return 0;
	}
