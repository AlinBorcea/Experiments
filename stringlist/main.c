#include "string_list.h"

int main() {
    strlist *first = 0, *last = 0;
    char fileName[] = "file.txt";
    makeStrlistFromFile(&first, &last, fileName);
    printStringList(first);

    return 0;
}