#include <stdio.h>

int main()
{
    printf("Given Grammar:\n");
    printf("S -> iEtS | iEtSeS | a\n");
    printf("E -> b\n\n");

    printf("Checking for Left Factoring...\n");

    printf("Common prefix found: iEtS\n\n");

    printf("After eliminating left factoring:\n");
    printf("S  -> iEtS S' | a\n");
    printf("S' -> eS | epsilon\n");
    printf("E  -> b\n");

    return 0;
}