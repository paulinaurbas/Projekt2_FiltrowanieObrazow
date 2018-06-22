#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H
#include "BMPRead.h"
/** Function converting picture to black-white photo
@author Paulina Urbas
@date 2.06.2018
@param Image * 
*/
void Convert_to_Black(Image * pImage);
/** Function converting picture to sepii picture
@author Paulina Urbas
@date 2.06.2018
@param pImage
*/
void Convert_to_Sepia(Image * pImage);
/** Function converting picture to red photo
@author Paulina Urbas
@date 2.06.2018
@param Image * 
*/
void Convert_to_Red(Image * pImage);
/** Function converting picture to Inversion 
@author Paulina Urbas
@date 2.06.2018
@param Image * 
*/
void Inversion(Image * pImage);
/** Function converting brightness of picture
@author Paulina Urbas
@date 2.06.2018
@param Image * 
*/
void Brightness(Image * pImage, char change);
/** Function converting contrast of picture
@author Paulina Urbas
@date 2.06.2018
@param Image *, char 
*/
void Contrast(Image * pImage, unsigned char contrast);
/** Function which suming neighboiur pixel 
@author Paulina Urbas
@date 16.06.2018
@param Image *
*/
void middle(Image * pImage);
/** Function smoothing the picture
@author Paulina Urbas
@date 16.06.2018
@param Image *
*/
void Smooth(Image * pImage);
/** Function s
@author Paulina Urbas
@date 16.06.2018
@param Image * 
@return int ** 
*/
int ** KernelLaplace();
/** Function appling kertel to image
@author Paulina Urbas
@date 16.06.2018
@param Image
*/
void ApplyKerneltoImage(Image * pImage);
/** Function detecting edge wi
@author Paulina Urbas
@date 16.06.2018
@param Image *
*/
void LaplaceEdge(Image * pImage);
#endif