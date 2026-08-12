#include <stdio.h>

void followS()
{
    printf("FOLLOW(S) = { $ }\n");
}

void followA()
{
    printf("FOLLOW(A) = { a, b }\n");
}

void followB()
{
    printf("FOLLOW(B) = { a, b }\n");
}

int main()
{
    printf("Given Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> epsilon\n");
    printf("B -> epsilon\n\n");

    printf("FOLLOW Sets:\n");

    followS();
    followA();
    followB();

    return 0;
}