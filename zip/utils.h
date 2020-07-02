#ifndef utils
#define utils

#include <stdio.h>

long int filesize(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == 0)
        return -1;
    
    fseek(file, 0L, SEEK_END);
    long res = ftell(file);
    fclose(file);
    return res;
}

#endif