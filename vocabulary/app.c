#include "header.h"

int main(int argc, char *argv[]) {
    if (argc > 1) {
        Vocabulary *voc = openVocabulary(inputfile, 26);
        int n = 26;
        
        if (!strcmp(argv[1], "pv"));
            printVocabulary(voc, outputfile, n);

    }
    return 0;
}