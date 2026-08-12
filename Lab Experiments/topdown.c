#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;
int error = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    if (input[pos] == '+')
    {
        pos++;
        T();
        Eprime();
    }
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if (input[pos] == '*')
    {
        pos++;
        F();
        Tprime();
    }
}

void F()
{
    if (strncmp(&input[pos], "id", 2) == 0)
    {
        pos += 2;
    }
    else if (input[pos] == '(')
    {
        pos++;
        E();

        if (input[pos] == ')')
            pos++;
        else
            error = 1;
    }
    else
    {
        error = 1;
    }
}

int main()
{
    printf("Enter input string: ");
    scanf("%s", input);

    E();

    if (input[pos] != '\0')
        error = 1;

    if (error == 0)
        printf("String is accepted by the grammar.\n");
    else
        printf("String is rejected by the grammar.\n");

    return 0;
}