#include "header.h"

int main(int argc, char *argv[]) {
    int result = 0;
    if (argc == 4) {
        if (!strcmp(argv[1], COMP_COMMAND))
            result = compress(argv[2], argv[3]);

        else if (!strcmp(argv[1], DECOMP_COMMAND))
            result = decompress(argv[2], argv[3]);

    } else if (argc == 3) {
        if (!strcmp(argv[1], SIZE_COMMAND)) {
            result = filesize(argv[2]);
            if (result != ERROR_NO_FILE_FOUND)
                printf("File %s has %ld bytes\n", argv[2], result);
        }
    
    } else result = ERROR_UNKNOWN_COMMAND;

    throwErrorIfThereIs(result, argc, argv);
    return 0;
}