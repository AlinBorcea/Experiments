#ifndef table_utils
#define table_utils

#include <stdio.h>
#include <string.h>
#include "constants.h"

int findWordInTable(char table[][WORD_SIZE], int tableLen, char word[]) {
    for (int i = 0; i < tableLen; i++) {
        if (!strcmp(table[i], word))
            return i;
    }
    return -1;
}

void addWordToTable(char table[][WORD_SIZE], int *tableLen, char word[]) {
    strcpy(table[*tableLen], word);
    (*tableLen)++;
}

void printTable(char table[][WORD_SIZE], int tableLen) {
    printf("%d \n\n", tableLen);
    for (int i = 0; i < tableLen; i++) 
        printf("%s\n", table[i]);
    puts("\n");
}

int findWordInWordInTable(char table[][WORD_SIZE], int tableLen, char word[]) {
    for (int i = 0; i < tableLen; i++) {
        if (strstr(word, table[i]))
            return i;
    }
    return -1;
}

#endif