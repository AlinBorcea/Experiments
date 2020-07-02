#include "header.h"

int main(int argc, char *argv[]) {
    // 4 args
    switch (argc) {
        case 4:
            if (!strcmp(argv[1], COMP_COMMAND)) {
            int resultCode = compress(argv[2], argv[3]);
            if (resultCode == ERROR_NO_FILE_FOUND) {
                printf("Error code %d: missing files\n", resultCode);
                return EXIT_FAILURE;
        
            } else if (resultCode == EXIT_SUCCESS) {
                printf("File compressed successfuly\n");
            }
        }
        break;

        case 3:
            if (!strcmp(argv[1], SIZE_COMMAND))
                printf("Size of %s is %ld bytes\n", argv[2], filesize(argv[2]));
        break;

        default:
            printf("Wrong arguments!\n");
            break;
    }

    return 0;
}