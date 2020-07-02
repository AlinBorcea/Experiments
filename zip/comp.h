#ifndef comp
#define comp

#include <stdio.h>
#include <string.h>
#include "table.h"
#include "constants.h"

int compress(char infileName[], char outfileName[]);
int numberlen(int n);

int compress(char infileName[], char outfileName[]) {
    FILE *infile = fopen(infileName, "r");
    FILE *outfile = fopen(outfileName, "w");
    if (infile == 0 || outfile == 0)
        return ERROR_NO_FILE_FOUND;

    char table[WORD_COUNT][WORD_SIZE] = {0};
    char word[WORD_SIZE];
    char sep;
    int tableLen = 0;
    int index;

    while (!feof(infile)) {
        fscanf(infile, "%s", word);
        fscanf(infile, "%c", &sep);
        index = findWordInTable(table, tableLen, word);
        if (index == -1) {
            addWordToTable(table, &tableLen, word);
            fprintf(outfile, "%s ", word);
        
        } else if (strlen(word) > numberlen(index) + 1) {
            fprintf(outfile, "`%d ", index);
        }

        if (sep == '\n')
            fputs("\n", outfile);

    }
    fclose(infile);
    fclose(outfile);
    return SUCCESS;
}

int numberlen(int n) {
    int c = 0;
    while (n) {
        c++;
        n /= 10;
    }
    return c;
}

#endif