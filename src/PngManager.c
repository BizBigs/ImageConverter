#include "PngManager.h"

int     initPngLib(PNGSTRUCT *pngStruct) {
     /* initialize stuff */
    (*pngStruct).png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!(*pngStruct).png_ptr) {
        printf("[write_png_file] png_create_write_struct failed");
        return 0;
    }

    (*pngStruct).info_ptr = png_create_info_struct((*pngStruct).png_ptr);
    if (!(*pngStruct).info_ptr) {
        printf("[write_png_file] png_create_info_struct failed");
        png_destroy_write_struct(&(*pngStruct).png_ptr,  NULL);
        return 0;
    }

    if (setjmp(png_jmpbuf((*pngStruct).png_ptr))) {
        printf("[write_png_file] Error during init_io");
        png_destroy_write_struct(&(*pngStruct).png_ptr, &(*pngStruct).info_ptr);
        return 0;
    }
    return 1;
}

void    buildPngImage(PNGSTRUCT *pngStruct, IMAGEDATA *imageData, unsigned char  ***rowPointers) {
    unsigned int i = 0;
    
    *rowPointers = (unsigned char **)malloc(imageData->height * sizeof(unsigned char*));

    png_set_IHDR((*pngStruct).png_ptr, (*pngStruct).info_ptr, imageData->width, imageData->height, 8,
        PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT);
    
    while (i < imageData->height) {
        (*rowPointers)[i] = imageData->lpData + (i * imageData->width * 3);
        i++;
    }
}

void    writePngFile(IMAGEDATA *imageData, char* file_name) {
    PNGSTRUCT       pngStruct;
    unsigned char   **rowPointers;

    /* create file */
    FILE *fp = fopen(file_name, "wb");
    if (!fp) {
        printf("[write_png_file] File %s could not be opened for writing", file_name);
        exit(EXIT_FAILURE);
    }
        
    /* Init PNG Library */
    if (!initPngLib(&pngStruct)) {
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    /* Build PNG Image from raw data */
    buildPngImage(&pngStruct, imageData, &rowPointers);

    png_init_io(pngStruct.png_ptr, fp);
    png_set_rows(pngStruct.png_ptr, pngStruct.info_ptr, rowPointers);
    png_write_png(pngStruct.png_ptr, pngStruct.info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
    png_destroy_write_struct(&pngStruct.png_ptr, &pngStruct.info_ptr);
    free(rowPointers);
    fclose(fp);
}

