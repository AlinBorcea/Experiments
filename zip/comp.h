#ifndef comp
#define comp

#include <stdio.h>
#include <string.h>
#include "table.h"
#include "constants.h"

int compress(char infileName[], char outfileName[]);
int wordFoundCase(char word1[], char word2[]);
int numberlen(int n);

int compress(char infileName[], char outfileName[]) {
    FILE *infile = fopen(infileName, "r");
    FILE *outfile = fopen(outfileName, "w");
    if (infile == 0 || outfile == 0)
        return ERROR_NO_FILE_FOUND;

    char table[WORD_COUNT][WORD_SIZE] = {0};
    int tableLen = 0;

    char word[WORD_SIZE];
    char sep;
    
    char str[WORD_SIZE];
    char *cp;

    int index;
    int dif;

    while (!feof(infile)) {
        fscanf(infile, "%s", word);
        fscanf(infile, "%c", &sep);
        index = findWordInWordInTable(table, tableLen, word);

        if (index == -1) {
            addWordToTable(table, &tableLen, word);
            fprintf(outfile, "%s", word);

        } else {
            cp = strstr(word, table[index]);
            dif = (int) cp - (int) word;

            switch (wordFoundCase(word, table[index])) {
            case 1:
                if (strlen(word) > numberlen(index) + 1)
                    fprintf(outfile, "`%d", index);
            break;

            case 2:
                if (strlen(word) > numberlen(index) + 1) {
                    strncpy(str, word, dif);
                    str[dif] = '\0';
                    fprintf(outfile, "%s`%d", str, index);
                }
            break;

            case 3:
                if (strlen(word) > numberlen(index) + 2)
                    fprintf(outfile, "`%d`%s", index, word + strlen(table[index]));
            break;

            case 4:
                if (strlen(word) > numberlen(index) + 2) {
                    strncpy(str, word, dif);
                    str[dif] = '\0';
                    fprintf(outfile, "%s`%d`%s", str, index, word + dif + strlen(table[index]));
                }
            break;
            }
        }
        
        fprintf(outfile, "%c", sep);
    }
    fclose(infile);
    fclose(outfile);
    return SUCCESS;
}

int wordFoundCase(char str1[], char str2[]) {
    if (!strcmp(str1, str2))
        return 1;
    
    char *cp = strstr(str1, str2);
    int dif = (int) cp - (int) str1;
    
    if (!strcmp(str2, cp) && dif)
        return 2;

    if (strcmp(str2, cp) && !dif)
        return 3;

    if (strcmp(str2, cp) && dif)
        return 4;

    return -1;
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