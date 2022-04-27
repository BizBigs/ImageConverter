#include "PngManager.h"
#include "JpegManager.h"

int main() {
    IMAGEDATA *imageData;

    imageData = readJpegFile("../Images/test2.jpg");
    /*printf("Data:%s", imageData->lpData);*/
    writePngFile(imageData, "../Images/test2.png");
    return 0;
}