#ifndef _JPEG_MANAGER_H
#define _JPEG_MANAGER_H

#include <sys/types.h>
#include <stdio.h>
#include <setjmp.h>
#include <jpeglib.h>
#include <stdlib.h>


typedef struct {
    unsigned char *pixels;
    long  width;
    long height;
} IMAGEDATA;


struct my_error_mgr {
    struct jpeg_error_mgr pub;	/* "public" fields */

    jmp_buf setjmp_buffer;	/* for return to caller */
};
typedef struct my_error_mgr *my_error_ptr;

IMAGEDATA read_JPEG_file (char *);

#endif /* _JPEG_MANAGER_H */
