#include <stdio.h>
#include <iostream>
#include "../../helpers/memView.h"

int main() {
    int var1 = 20;
    int *pX = &var1;
    int **three = &pX;

    mem::MemView(var1, 2, 4);

    printf("%d", *pX);

    return 0;
}