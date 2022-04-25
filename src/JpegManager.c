#include "JpegManager.h"


/*
 * Here's the routine that will replace the standard error_exit method:
 */

void my_error_exit (j_common_ptr cinfo)
{
  /* cinfo->err really points to a my_error_mgr struct, so coerce pointer */
  my_error_ptr myerr = (my_error_ptr) cinfo->err;

  /* Always display the message. */
  /* We could postpone this until after returning, if we chose. */
  (*cinfo->err->output_message) (cinfo);

  /* Return control to the setjmp point */
  longjmp(myerr->setjmp_buffer, 1);
}

struct ImageData read_JPEG_file(char *filename)
{
    struct jpeg_decompress_struct cinfo;
    struct my_error_mgr jerr;
    struct ImageData imageData = {NULL, 0, 0};
    /* More stuff */
    FILE * infile;		/* source file */
    /*JSAMPARRAY buffer;*/		/* Output row buffer */
    JSAMPROW output_data;
    unsigned int scanline_len;
    unsigned int scanline_count = 0;

    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "can't open %s\n", filename);
        return imageData;
    }

    cinfo.err = jpeg_std_error(&jerr.pub);
    jerr.pub.error_exit = my_error_exit;
    if (setjmp(jerr.setjmp_buffer)) {
        fclose(infile);
        return imageData;
    }
    jpeg_create_decompress(&cinfo);

    jpeg_stdio_src(&cinfo, infile);

    (void) jpeg_read_header(&cinfo, TRUE);

    (void) jpeg_start_decompress(&cinfo);
    /*buffer = (*cinfo.mem->alloc_sarray) ((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);*/

    imageData.width = cinfo.output_width;
    imageData.height = cinfo.output_height;
    imageData.pixels = (unsigned char *)malloc(cinfo.output_width * cinfo.output_height * cinfo.output_components);

    scanline_len = cinfo.output_width * cinfo.output_components;
    while (cinfo.output_scanline < cinfo.output_height) {
        output_data = (imageData.pixels + (scanline_count * scanline_len));
        jpeg_read_scanlines(&cinfo, &output_data, 1);
        scanline_count++;
    }

    (void) jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);
    return imageData;
}