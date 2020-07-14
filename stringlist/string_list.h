#ifndef string_list
#define string_list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stringList {
    char *str;
    struct stringList *next;
}strlist;

void add(strlist **first, strlist **last, strlist *elem);
void addAscending(strlist **first, strlist **last, strlist *elem);
void makeStrlistFromFile(strlist **first, strlist **last, char *fileName);

strlist *newElement(char *str);

void printStringList(strlist *first);

void add(strlist **first, strlist **last, strlist *elem) {
    if (!(*first)) {
        *first = elem;
        *last = elem;
        return;
    }

    (*last)->next = elem;
    *last = elem;
}

void makeStrlistFromFile(strlist **first, strlist **last, char *fileName) {
    FILE *file = fopen(fileName, "r");
    char str[30];

    fscanf(file, "%s", str);
    addAscending(first, last, newElement(str));    
    while (!feof(file)) {
        fscanf(file, "%s", str);
        addAscending(first, last, newElement(str));
    }
    fclose(file);
}

void addAscending(strlist **first, strlist **last, strlist *elem) {
    if (*first == 0) {
        *first = elem;
        *last = elem;
    
    } else if (strcmp(elem->str, (*first)->str) < 0) {
        elem->next = *first;
        (*first) = elem;
        
    } else if (strcmp(elem->str, (*last)->str) > 0) {
        (*last)->next = elem;
        *last = elem;
    
    } else {
        strlist *it = *first;
        while (it && it->next && strcmp(elem->str, it->next->str) > 0)
            it = it->next;

        elem->next = it->next;
        it->next = elem;
    }
}

strlist *newElement(char *str) {
    strlist *elem = (strlist*) malloc(sizeof(strlist));
    elem->str = (char*) malloc(sizeof(char) * strlen(str));
    strcpy(elem->str, str);
    elem->next = 0;
    return elem;
}

void printStringList(strlist *first) {
    int c = 0;
    while (first) {
        printf("%s ", first->str);
        first = first->next;
        c++;
    }
    printf("\n%d\n", c);
}

#endif