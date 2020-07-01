#ifndef VOCABULARY
#define VOCABULARY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char words[500][30];
    unsigned int freq[100];
    int len;
} Vocabulary;

Vocabulary *openVocabulary(const char *fileName, int size);

int findWord(Vocabulary *voc, const unsigned char *word, int id);
int getLetterId(unsigned char letter);

void addWord(Vocabulary **voc, unsigned char *word, int id);
void printVocabulary(Vocabulary *voc, const char *outFile, int size);
void printWordsStartingWith(Vocabulary *voc, const char *format, unsigned char letter);

Vocabulary *openVocabulary(const char *fileName, int size) {
    Vocabulary *voc = (Vocabulary*) malloc(sizeof(Vocabulary) * size);
    FILE *file = fopen64(fileName, "r");
    unsigned char word[30];
    int id;

    while (!feof(file)) {
        fscanf(file, "%s", word);
        id = getLetterId(word[0]);
        addWord(&voc, word, id);
    }
    fclose(file);
    return voc;
}

int getLetterId(unsigned char letter) {
    if (letter >= 'a' && letter <= 'z')
        return (int) letter - 97;
    return (int) letter - 65;
}

int findWord(Vocabulary *voc, const unsigned char *word, int id) {
    for (int i = 0; i < voc[id].len; i++)
        if (!strcmpi(voc[id].words[i], word))
            return i;
    return -1;
}

void addWord(Vocabulary **voc, unsigned char *word, int id) {
    int wordIndex = findWord(*voc, word, id);
    if (wordIndex == -1) {

        if (word[0] >= 'A' && word[0] <= 'Z')
            word[0] = word[0] + 32;

        strcpy((*voc)[id].words[(*voc)[id].len], word);
        (*voc)[id].freq[(*voc)[id].len] = 1;
        (*voc)[id].len++;
    
    } else {
        (*voc)[id].freq[wordIndex]++;
    }
}

void printVocabulary(Vocabulary *voc, const char *outFile, int size) {
    FILE *file = fopen64(outFile, "w");
    for (int i = 0; i < size; i++) {
        if (voc[i].len) {
            fprintf(file, "Letter %c:\n", (unsigned char) i + 97);
            for (int j = 0; j < voc[i].len; j++)
                fprintf(file, "%d. %s\n", j, voc[i].words[j]);
        }
    }
    puts("\n");
    fclose(file);
}

void printWordsStartingWith(Vocabulary *voc, const char *format, unsigned char letter) {
    int id = getLetterId(letter);
    for (int i = 0; i < voc[id].len; i++)
        printf(format, voc[id].words[i]);
}

#endif