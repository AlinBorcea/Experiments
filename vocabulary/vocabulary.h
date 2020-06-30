#ifndef VOCABULARY
#define VOCABULARY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char words[500][30];
    int len;
} Vocabulary;

Vocabulary *openVocabulary(const char *fileName, int size);

int findWord(Vocabulary *voc, const char *word, int id);
int getLetterId(char letter);

void addWord(Vocabulary **voc, const char *word, int id);
void printVocabulary(Vocabulary *voc, const char *outFile, int size);

Vocabulary *openVocabulary(const char *fileName, int size) {
    Vocabulary *voc = (Vocabulary*) malloc(sizeof(Vocabulary) * size);
    FILE *file = fopen64(fileName, "r");
    char word[30];
    int id;

    while (!feof(file)) {
        fscanf(file, "%s", word);
        id = getLetterId(word[0]);
        addWord(&voc, word, id);
    }
    fclose(file);
    return voc;
}

int getLetterId(char letter) {
    if (letter >= 'a' && letter <= 'z')
        return (int) letter - 97;
    return (int) letter - 65;
}

int findWord(Vocabulary *voc, const char *word, int id) {
    for (int i = 0; i < voc[id].len; i++)
        if (!strcmpi(voc[id].words[i], word))
            return 1;
    return 0;
}

void addWord(Vocabulary **voc, const char *word, int id) {
    if (!findWord(*voc, word, id)) {
        strcpy((*voc)[id].words[(*voc)[id].len], word);
        (*voc)[id].len++;
    }
}

void printVocabulary(Vocabulary *voc, const char *outFile, int size) {
    FILE *file = fopen64(outFile, "w");
    for (int i = 0; i < size; i++) {
        if (voc[i].len) {
            fprintf(file, "Letter %c:\n", (char) i + 97);
            for (int j = 0; j < voc[i].len; j++)
                fprintf(file, "%d. %s\n", j, voc[i].words[j]);
        }
    }
    puts("\n");
    fclose(file);
}

#endif