#include "JpegManager.h"
#include "PngManager.h"

int    checkFormat(char *file, char *format)
{
    int lenOfStr = strlen(file);
    int lenOfSubstr = strlen(format);
    int i = 0;

    if (lenOfSubstr <= lenOfStr) {
        while (i < lenOfSubstr) {
            if (file[i + lenOfStr - lenOfSubstr] != format[i]) {
                return 0;
            }
            i++;
        }
    } else {
        return 0;
    }
    return 1;
}

void    convertJpegToPng(char *fileSourcePath, char *fileDestPath) {
    IMAGEDATA *imageData;

    if (fileSourcePath && checkFormat(fileSourcePath, JPEG_EXTENSION) && checkFormat(fileDestPath, PNG_EXTENSION)) {
        imageData = readJpegFile(fileSourcePath);
        writePngFile(imageData, fileDestPath);
    } else {
        printf("Source or destination file is not in correct format. Failed to process conversion.\n");
        exit(EXIT_FAILURE);
    }
}