#ifndef __PNG_MANAGER_H__
#define __PNG_MANAGER_H__

#include <setjmp.h>
#include "ImageManager.h"
#include <png.h>

typedef struct {
    png_structp     png_ptr;
    png_infop       info_ptr;
} PNGSTRUCT;

void            writePngFile(IMAGEDATA *, char*);
int             initPngLib(PNGSTRUCT *);
void            buildPngImage(PNGSTRUCT *, IMAGEDATA *, unsigned char  ***);

#endif /* __PNG_MANAGER_H__*/
