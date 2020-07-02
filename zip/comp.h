#ifndef comp
#define comp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_NO_FILE_FOUND 1
#define MAX_WORD_SIZE 20
#define WORD_COUNT 2000

int compress(const char *inputFileName, const char *outputFileName);
int findWordInTable(char table[][MAX_WORD_SIZE], int tableLen, char *word);
int numberLen(int n);

void addWordToTable(char table[][MAX_WORD_SIZE], int *tableLen, char *word);
void printTable(char table[][MAX_WORD_SIZE], int tableLen);

int compress(const char *inputFileName, const char *outputFileName) {
    FILE *infile = fopen(inputFileName, "r");
    FILE *outfile = fopen(outputFileName, "w");
    if (infile == 0 || outfile == 0)
        return ERROR_NO_FILE_FOUND;

    char table[WORD_COUNT][MAX_WORD_SIZE] = {0};
    char word[MAX_WORD_SIZE];
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
        
        } else if (strlen(word) > numberLen(index) + 1) {
            fprintf(outfile, "`%d ", index);
        }

        if (sep == '\n')
            fputs("\n", outfile);

    }
    fclose(infile);
    fclose(outfile);
    return EXIT_SUCCESS;
}

int findWordInTable(char table[][MAX_WORD_SIZE], int tableLen, char *word) {
    for (int i = 0; i < tableLen; i++) {
        if (!strcmp(table[i], word))
            return i;
    }
    return -1;
}

void addWordToTable(char table[][MAX_WORD_SIZE], int *tableLen, char *word) {
    strcpy(table[*tableLen], word);
    (*tableLen)++;
}

void printTable(char table[][MAX_WORD_SIZE], int tableLen) {
    printf("%d \n\n", tableLen);
    for (int i = 0; i < tableLen; i++) 
        printf("%s\n", table[i]);
    puts("\n");
}

int numberLen(int n) {
    int c = 0;
    while (n) {
        c++;
        n /= 10;
    }
    return c;
}

#endif