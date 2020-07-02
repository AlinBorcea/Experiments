#ifndef utils
#define utils

#include <stdio.h>
#include "constants.h"

long int filesize(char filename[]) {
    FILE *file = fopen(filename, "r");
    if (file == 0)
        return ERROR_NO_FILE_FOUND;
    
    fseek(file, 0L, SEEK_END);
    long res = ftell(file);
    fclose(file);
    return res;
}

void throwErrorIfThereIs(int code, int argc, char *argv[]) {
    switch (code) {
        
        case SUCCESS:
        printf("Success\n");
        break;

        case ERROR_UNKNOWN_COMMAND:
        if (argc > 1)
            printf("Error: unknown command %s\n", argv[1]);
        else
            printf("Error: not enough arguments given\n");
        break;

        case ERROR_NO_FILE_FOUND:
        if (argc == 3)
            printf("Error: file %s could not be found or opened\n", argv[2]);
        
        else if (argc == 4)
            printf("Error: files were not found or opened\n%s %s", argv[2], argv[3]); 
        break;

        default: break;

    }
}

#endif