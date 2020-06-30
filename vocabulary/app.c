#include "header.h"

int main() {
    Vocabulary *voc = openVocabulary("test.txt", 26);
    int n = 26;

    printVocabulary(voc, "output.txt", n);
    return 0;
}