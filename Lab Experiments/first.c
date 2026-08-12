#include <stdio.h>

void firstS()
{
    printf("FIRST(S) = { a, b }\n");
}

void firstA()
{
    printf("FIRST(A) = { epsilon }\n");
}

void firstB()
{
    printf("FIRST(B) = { epsilon }\n");
}

int main()
{
    printf("Given Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> epsilon\n");
    printf("B -> epsilon\n\n");

    printf("FIRST Sets:\n");

    firstS();
    firstA();
    firstB();

    return 0;
}