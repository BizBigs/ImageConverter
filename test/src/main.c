#include "PngManager.h"

int main() {
    IMAGEDATA *imageData;

    imageData = readJpegFile("../Images/test.jpg");
    /*printf("Data:%s", imageData->lpData);*/
    writePngFile(imageData, "../Images/test.png");
    return 0;
}