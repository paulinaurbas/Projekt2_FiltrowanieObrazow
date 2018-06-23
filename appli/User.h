#ifndef USER_H
#define USER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 
#include "User.h"
#include "Function.h"
#include "BMPRead.h"
/** Function printing help
@author Paulina Urbas
@date 20.05.2018
*/
void Help();
/** Function checking terminal
@author Paulina Urbas
@date 20.05.2018
@param int, char *, Image *
@return int
*/
int TerminalCheck(int argc, char * argv[], Image * readyImage);
/** Function checking number of filtr and coverting
@author Paulina Urbas
@date 2.05.2018
@param char *, Image * 
@return int
*/
int Filtr(char * argv[], Image * readyImage);
/** Function printing errorinfo
@author Paulina Urbas
@date 20.05.2018
*/
void ErrorInfo();
#endif
