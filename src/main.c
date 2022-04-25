#include "JpegManager.h"

int main() {
    struct ImageData imageData;

    imageData = read_JPEG_file("./Images/test.jpg");
    printf("Map = %s\n", imageData.pixels);
    return 0;
}