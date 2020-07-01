#include <stdio.h>
#include <stdlib.h>

int main() {
    char a = 'a';
    unsigned char b = 127;

    scanf("%d", &b);
    printf("%d\n%c\n", sizeof(b), b);

    return 0;
}