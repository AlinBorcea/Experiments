#include <stdio.h>
#include "header.h"

int main() {
    int a = 2;
    int b = 4;

    int c = subtract(a, b);
    int d = add(a, b);

    printf("%d %d\n", c, d);
    return 0;
}