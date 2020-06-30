#include <stdio.h>
#include <string.h>

int wasFound(char voc[][30], char *s, int c) {
    for (int i = 0; i < c; i++)
        if (!strcmp(s, voc[i]))
            return 1;
    return 0;
}

void addWord(char voc[][30], char *s, int *c) {
    strcpy(voc[*c], s);
    (*c)++;
}

void printVoc(char voc[][30], int c) {
    for (int i = 0; i < c; i++)
        puts(voc[i]);
    puts("\n");
}

int main() {
    FILE *file = fopen64("testFile.txt", "r");
    char vocabulary[5000][30] = {0};
    char s[3000];
    int c = 0;

    while (!feof(file)) {
        fscanf(file, "%s", s);
        if (!wasFound(vocabulary, s, c))
            addWord(vocabulary, s, &c);
    }

    fclose(file);
    printVoc(vocabulary, c);
    return 0;
}