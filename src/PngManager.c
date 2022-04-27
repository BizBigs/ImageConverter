#include "PngManager.h"

int     initPngLib(png_structp *png_ptr, png_infop *info_ptr) {
     /* initialize stuff */
    *png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!*png_ptr) {
        printf("[write_png_file] png_create_write_struct failed");
        return 0;
    }

    *info_ptr = png_create_info_struct(*png_ptr);
    if (!*info_ptr) {
        printf("[write_png_file] png_create_info_struct failed");
        png_destroy_write_struct(png_ptr,  NULL);
        return 0;
    }

    if (setjmp(png_jmpbuf(*png_ptr))) {
        printf("[write_png_file] Error during init_io");
        png_destroy_write_struct(png_ptr, info_ptr);
        return 0;
    }
    return 1;
}

void    writePngFile(IMAGEDATA *imageData, char* file_name) {
    png_structp     png_ptr;
    png_infop       info_ptr;
    unsigned char   **rowPointers = (unsigned char **)malloc(imageData->height * sizeof(unsigned char*));
    /*png_bytep *rowPointers = (png_byte)malloc(imageData.height);
    unsigned int i = 0, j = 0;*/
    unsigned int i = 0;

    /* create file */
    FILE *fp = fopen(file_name, "wb");
    if (!fp)
        printf("[write_png_file] File %s could not be opened for writing", file_name);

    if (!initPngLib(&png_ptr, &info_ptr)) {
        exit(EXIT_FAILURE);
    }

    png_set_IHDR(png_ptr, info_ptr, imageData->width, imageData->height, 8,
        PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT);
    
    while (i < imageData->height) {
        rowPointers[i] = imageData->lpData + (i * imageData->width * 3);
        i++;
    }

    png_init_io(png_ptr, fp);
    png_set_rows(png_ptr, info_ptr, rowPointers);
    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);

    fclose(fp);
}

