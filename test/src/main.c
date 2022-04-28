#include "PngManager.h"
#include "JpegManager.h"

void    usage() {
    printf("Usage :\n");
    /*printf("-ConversionType [-j, -p] [MANDATORY]\n"); TODO*/
    printf("-SourcePathFile ['<your-path-to-source>.jpg'] [MANDATORY]\n");
    printf("-DestPathFile ['<your-path-to-dest>.png'] [MANDATORY]\n");
}

int main(int ac, char **argv) {
    if (ac != 3) {
        usage();
        exit(EXIT_FAILURE);
    } else {
        convertJpegToPng(argv[1], argv[2]);
    }
    return 0;
}