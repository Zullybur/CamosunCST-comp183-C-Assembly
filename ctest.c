#include <stdio.h>
#include "comp183.h"

int main () {
    printf("LL: %u\n", 8* sizeof(long long));
    printf("Long: %u\n", 8* sizeof(long));
    printf("Int: %u\n", 8* sizeof(int));
    printf("US: %u\n", 8* sizeof(unsigned));
    long test;
    unsigned add = getUnsigned();
    unsigned max = getUnsigned();

    printf("Working...\n");
    for (unsigned i = 0; i < max; i++){
        test = test + add;
    }
    printf("Test: %u\n", test);
    printf("Done!\n");
}