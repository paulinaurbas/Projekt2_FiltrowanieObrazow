#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 
#include "User.h"
#include "Function.h"
#include "BMPRead.h"
void ErrorInfo()
{
	printf_s("Program zostal zle wywolany!\n");
}
int TerminalCheck(int argc, char * argv[], Image * readyImage)
{
	if (argc >= 5 && strcmp(argv[1], "-i") == 0 && strcmp(argv[3], "-o") == 0)
	{
		return 0;
}
	else
	{
		return 1; 
	}
}

int Filtr(char * argv[], Image * readyImage)
{
	int changenumber = 0;
	if (strcmp(argv[5], "-1") == 0)
	{
		Convert_to_Black(readyImage);
		return 0;
	}
	if (strcmp(argv[5], "-2") == 0)
	{
		Convert_to_Sepia(readyImage);
		return 0;
	}
	if (strcmp(argv[5], "-3") == 0)
	{
		printf_s("Wybierz poziom Inversji: ");
		scanf_s("%d", &changenumber);
		Inversion(readyImage, changenumber);
		return 0;
	}
	if (strcmp(argv[5], "-4") == 0)
	{
		printf_s("Wybierz jasnosc: ");
		scanf_s("%d", &changenumber);
		Brightness(readyImage, changenumber);
		return 0;
	}
	if (strcmp(argv[5], "-5") == 0)
	{
		printf_s("Wybierz kontrast: ");
		scanf_s("%d", &changenumber);
		Contrast(readyImage, changenumber);
		return 0;
	}
	if (strcmp(argv[5], "-6") == 0)
	{
		Smooth(readyImage);
		return 0;
	}
	if (strcmp(argv[5], "-7") == 0)
	{
		LaplaceEdge(readyImage);
		return 0;
	}
	else
	{
		return 1;
	}
}
void Help()
{
	printf_s("Pomoc!\n");
	printf_s("Aby podac nazwe pliku wejsciowego nalezy uzyc komendy -i, a nastepnie podac nazwe pliku wejsciowego \n");
	printf_s("Aby podac nazwe pliku wyjsciowego nalezy uzyc komendy -o, a nastepnie podac nazwe pliku wyjsciowego \n");
	printf_s("Aby podac filtru nalezy podac:\n");
	printf_s("1 - filtr dolnoprzepustowy \n");
	printf_s("2 - filtr gornoprzepustowy \n");
	printf_s("3 - filtr medianowy \n");
	printf_s("4 - filtr usredniajacy \n");
	printf_s("5 - filtr minimalny \n");
	printf_s("6 - filtr maksymalny \n");
}