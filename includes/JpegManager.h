#ifndef _JPEG_MANAGER_H
#define _JPEG_MANAGER_H

#include <sys/types.h>
#include <stdio.h>
#include <setjmp.h>
#include <jpeglib.h>
#include "ImageManager.h"
#include <stdlib.h>

IMAGEDATA *readJpegFile(char *);

#endif /* _JPEG_MANAGER_H */
