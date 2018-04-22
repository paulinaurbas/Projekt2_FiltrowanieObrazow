#ifndef funkcje_h
#define funckje_h
#include <stdint.h>
typedef struct BMPHeader {
	uint16_t type;
	uint32_t size;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t offset;
	uint32_t DIB_header_size;
	int32_t width;
	int32_t height; 

}BMPHeader;
/** Funkcja sprawdzenie wywolania".
@author Paulina Urbas
@date   2018-04-21
@param argc
@param argv[]
@param inputfile 
@param outputfile
@param filtrnumber
*/
void CheckTerminal(int argc, char * argv[], char * inputfile, char * outfile, int filtrnumber);
/** Funkcja wyswietlajaca pomoc".
@author Paulina Urbas
@date   2018-04-21
*/
void Help();
/** Funkcja wczytujaca obraz z pliku".
@author Paulina Urbas
@date   2018-04-21
*/
void ReadFromFile();
#endif
