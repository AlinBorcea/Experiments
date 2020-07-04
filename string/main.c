#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "beforetherefore";
    char str2[] = "the";
    char *cp = strstr(str1, str2);
    char str3[10];
    int dif = (int) cp - (int) str1;

    printf("dif = %d\n", dif);
    printf("cp = %s\n", cp);

    // equal
    if (!strcmp(str1, str2)) {
        puts("1: ");
        puts(str1);
    }

    // only before
    if (dif && !strcmp(str2, cp)) {
        puts("2: ");
        strncpy(str3, str1, dif);
        str3[dif] = '\0';
        printf("%s\n", str3);
        printf("%s", cp);
    }

    // only after
    if (strcmp(str2, cp) && !dif) {
        puts("3: ");
        puts(str2);
        printf("\n%s", str1 + strlen(str2));
    }

    // both
    if (dif && strcmp(str2, cp)) {
        puts("4: ");
        strncpy(str3, str1, dif);
        str3[dif] = '\0';
        puts(str3);
        puts(str2);
        puts(str1 + strlen(str2) + dif);
    }

    puts("\n");
    return 0;
}