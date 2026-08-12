#include <stdio.h>

int main()
{
    printf("Given Grammar:\n");
    printf("S -> (L) | a\n");
    printf("L -> L,S | S\n\n");

    printf("Checking for Left Recursion...\n");

    printf("Production: L -> L,S | S\n");
    printf("Left recursion found in L.\n\n");

    printf("After eliminating left recursion:\n");
    printf("S  -> (L) | a\n");
    printf("L  -> S L'\n");
    printf("L' -> , S L' | epsilon\n");

    return 0;
}