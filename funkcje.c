#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funkcje.h"
void Help()
{
	printf_s("Witaj w pomocy!\n");
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
void CheckTerminal(int argc, char *argv[], char * inputfile, char * outfile, int filtrnumber)
{
	int ok = 0; 
	if (argc <= 7)
	{
		for (int i = 0; i < argc; i++)
		{
			if (strcmp(argv[i], "-h") == 0)
			{
				return 1; //wywolanie pomocy 
			}
			if (strcmp(argv[i], "-i") == 0)
			{
				inputfile = argv[i + 1];
				ok++;
			}
			if (strcmp(argv[i], "-o") == 0)
			{
				outfile = argv[i + 1];
				ok++;
			}
			if (strcmp(argv[i], "-1") == 0)
			{
				filtrnumber= atoi(argv[i + 1]);
				ok++;
			}
			if (strcmp(argv[i], "-2") == 0)
			{
				filtrnumber = atoi(argv[i + 1]);
				ok++;
			}
			if (strcmp(argv[i], "-3") == 0)
			{
				filtrnumber = atoi(argv[i + 1]);
				ok++;
			}
			if (strcmp(argv[i], "-4") == 0)
			{
				filtrnumber = atoi(argv[i + 1]);
				ok++;
			}
			if (strcmp(argv[i], "-5") == 0)
			{
				filtrnumber = atoi(argv[i + 1]);
				ok++;
			}
			if (strcmp(argv[i], "-5") == 0)
			{
				filtrnumber = atoi(argv[i + 1]);
				ok++;
			}
		}
		if (ok == 3)
		{
			return 0;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 2;
	}
}