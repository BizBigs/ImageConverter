#ifndef __IMAGE_MANAGER_H__
#define __IMAGE_MANAGER_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define JPEG_EXTENSION ".jpg"
#define PNG_EXTENSION ".png"

typedef struct {
	unsigned int    numComponents;
    unsigned char   *lpData;
    unsigned long   width;
    unsigned long   height;
} IMAGEDATA;

void    convertJpegToPng(char *, char *);
int     checkFormat(char *, char *);

#endif /* __IMAGE_MANAGER_H__ */