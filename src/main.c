#include "JpegManager.h"

int main() {
    IMAGEDATA imageData;

    imageData = read_JPEG_file("./Images/test.jpg");
    printf("Map = %s\n", imageData.pixels);
    return 0;
}