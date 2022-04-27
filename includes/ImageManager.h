#ifndef __IMAGE_MANAGER_H__
#define __IMAGE_MANAGER_H__

typedef struct {
	unsigned int    numComponents;
    unsigned char   *lpData;
    unsigned long   width;
    unsigned long   height;
} IMAGEDATA;

#endif /* __IMAGE_MANAGER_H__ */