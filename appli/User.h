#ifndef USER_H
#define USER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 
#include "User.h"
#include "Function.h"
#include "BMPRead.h"
void Help();
int TerminalCheck(int argc, char * argv[], Image * readyImage);
int Filtr(char * argv[], Image * readyImage);
void ErrorInfo();
#endif
