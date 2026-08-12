#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

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
    if (input[pos] == 'i' && input[pos + 1] == 'd')
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
        {
            printf("Error: Missing )\n");
            return;
        }
    }
    else
    {
        printf("Error: Invalid identifier or expression\n");
    }
}

int main()
{
    printf("Enter expression using id: ");
    scanf("%s", input);

    E();

    if (input[pos] == '\0')
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}