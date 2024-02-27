#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include "bmp.h"

void print_help() {
    printf("-h: print help infomation\n");
    printf("-w: mendatory, width of the resulting ascii img(>0)\n");
    printf("-p: mendatory, picture path/name to be processed\n");
    printf("-i: optional, reverse the mapping pattern, no argument to be taken\n");
    printf("ex:\n    image2ascii -p mypic.bmp -w 30 -i\n");
}

int main(int argc, char *argv[]) {
    int padWidth = -1;
    int inverse = 1;
    char *picName = NULL;
    int opt;
    while ((opt = getopt(argc, argv, "hp:w:i")) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                return 0;
            case 'p':
                picName = calloc(sizeof(char), strlen(optarg)+1);
                strncpy(picName, optarg, strlen(optarg));
                break;
            case 'w':
                padWidth = strtol(optarg, 0, 10);
                break;
            case 'i':
                inverse = 0;
                break;
            default:
                printf("arg error!\n");
                return 0;
        }
    }
    if (padWidth <= 0 || picName == NULL) {
        if(picName != NULL) { free(picName); }
        printf("arg error!\n");
        return 0;
    }

    const char *charMap = "N@#W$9876543210?!abc;:+=-,._                    ";
    int charMapLen = strlen(charMap); 
    
    FILE *inputFile = NULL;
    if( ( inputFile = fopen(picName, "rb" ) ) == NULL ) {
        free(picName);
        printf("pic not found\n");
        return 0;
    }

    sBmpHeader bmpHeader;
    fread(&bmpHeader, sizeof(sBmpHeader), 1, inputFile);

    if(bmpHeader.width < padWidth) {
        printf("error: smaller than padWidth\n");
        free(picName);
        fclose(inputFile);
        return 0;
    }
    // print_bmp_header(&bmpHeader);

    uint32_t padding = bmpHeader.width%4;  // need to deal with bpp
    uint32_t bytepp = bmpHeader.bpp/8;
    uint32_t byteSize = bmpHeader.height*(bmpHeader.width+padding)*bytepp;
    uint8_t *byteArray = calloc(byteSize, sizeof(uint8_t));
    fread(byteArray, byteSize, 1, inputFile);
    fclose(inputFile);

    int32_t interval = bmpHeader.width/padWidth;
    for(int i=0; i<bmpHeader.height; i+=interval) {
        for(int j=0; j<bmpHeader.width; j+=interval) {
            uint32_t count = 0;
            uint32_t sum = 0;
            uint32_t avg = 0;
            for(int k=i; k<i+interval; k++) {
                if(k >= bmpHeader.height) { break; }
                for(int l=j; l<j+interval; l++) {
                    if(l >= bmpHeader.width) { break; }
                    count ++;
                    sum += byteArray[((bmpHeader.height-k)*bmpHeader.width+l)*bytepp + 0];
                    sum += byteArray[((bmpHeader.height-k)*bmpHeader.width+l)*bytepp + 1];
                    sum += byteArray[((bmpHeader.height-k)*bmpHeader.width+l)*bytepp + 2];
                }
            }
            avg = sum/count;
            avg/=3;
            uint32_t inx;
            if (inverse == 1) {
                inx = (avg * charMapLen/256);
            }
            else {
                inx = charMapLen - 1 - (avg * charMapLen/256);
            }
            printf("%c ", charMap[inx]);
        }
        printf("\n");
    }

    free(picName);
    free(byteArray);
    return 0;
}
