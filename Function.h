#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H
#include "BMPRead.h"
/** Function converting picture to black-white photo
@author Paulina Urbas
@date 2.06.2018
@param Infoheader, Pixel
*/
void Convert_to_Sepia(INFOHEADER *pInfoHeader, PIXEL **pImage);
/** Function converting picture to sepii picture 
@author Paulina Urbas
@date 2.06.2018
@param Infoheader, Pixel
*/
void Convert_to_Black (INFOHEADER *pInfoHeader, PIXEL **pImage);
/** Function converting picture to red photo
@author Paulina Urbas
@date 2.06.2018
@param Infoeader, Pixel
*/
void Convert_to_Red(INFOHEADER *pInfoHeader, PIXEL **pImage);
/** Function converting picture to Inversion 
@author Paulina Urbas
@date 2.06.2018
@param Infoeader, Pixel
*/
void Inversion(INFOHEADER *pInfoHeader, PIXEL **pImage);
/** Function converting brightness of picture
@author Paulina Urbas
@date 2.06.2018
@param Infoeader, Pixel, char
*/
void Brightness(INFOHEADER *pInfoHeader, PIXEL **pImage, char change);
/** Function converting contrast of picture
@author Paulina Urbas
@date 2.06.2018
@param Infoeader, Pixel, char
*/
void Contrast(INFOHEADER *pInfoHeader, PIXEL **pImage, unsigned char contrast);
/** Function converting contrast of picture
@author Paulina Urbas
@date 5.06.2018
@param Infoeader, Pixel, char
*/
void Smooth(INFOHEADER *pInfoHeader, PIXEL **pImage, PIXEL ** pCopy);
void corner1(INFOHEADER * pInforHeader, PIXEL ** pImage);
void middle(INFOHEADER * pInforHeader, PIXEL ** pImage);
void side1(INFOHEADER * pInforHeader, PIXEL ** pImage);
void corner2(INFOHEADER * pInforHeader, PIXEL ** pImage);
void side3(INFOHEADER * pInforHeader, PIXEL ** pImage);
void side2(INFOHEADER * pInforHeader, PIXEL ** pImage);
void corner3(INFOHEADER * pInforHeader, PIXEL ** pImage);
void corner4(INFOHEADER * pInforHeader, PIXEL ** pImage);
void side4(INFOHEADER * pInforHeader, PIXEL ** pImage);
void LaplaceEdge(INFOHEADER *pInfoHeader, PIXEL **pImage, PIXEL ** copy);
#endif