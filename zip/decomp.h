#ifndef decomp
#define decomp

#include <stdio.h>
#include <string.h>
#include "constants.h"
#include "table.h"

int decompress(char infileName[], char outfileName[]);
int findIndex(char word[]);

int decompress(char infileName[], char outfileName[]) {
    FILE *infile = fopen(infileName, "r");
    FILE *outfile = fopen(outfileName, "w");
    if (infile == 0 || outfile == 0)
        return ERROR_NO_FILE_FOUND;

    char table[WORD_COUNT][WORD_SIZE];
    char word[WORD_SIZE];
    char sep;
    int tableLen;
    int index;

    while (!feof(infile)) {
        fscanf(infile, "%s", word);
        fscanf(infile, "%c", &sep);
        if (word[0] == '`') {
            index = findIndex(word);
            fprintf(outfile, "%s ", table[index]);
        
        } else {
            index = findWordInTable(table, tableLen, word);
            if (index == -1) {
                addWordToTable(table, &tableLen, word);
                fprintf(outfile, "%s ", word);

            } else {
                fprintf(outfile, "%s ", table[index]);
            }
        }

        if (sep == '\n')
            fputs("\n", outfile);

    }
    fclose(infile);
    fclose(outfile);
    return 0;
}

int findIndex(char word[]) {
    int x = 0;
    for (int i = 1; word[i]; i++)
        x = x * 10 + ((int) word[i] - 48);
    return x;
}

#endif