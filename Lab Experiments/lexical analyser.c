#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>' || ch == '%');
}

int main()
{
    char input[500];
    int i = 0;

    printf("Enter the source code:\n");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0')
    {
        /* Ignore spaces, tabs and new lines */
        if (isspace(input[i]))
        {
            i++;
            continue;
        }

        /* Ignore single-line comments */
        if (input[i] == '/' && input[i + 1] == '/')
        {
            break;
        }

        /* Ignore multi-line comments */
        if (input[i] == '/' && input[i + 1] == '*')
        {
            i += 2;

            while (input[i] != '\0' &&
                   !(input[i] == '*' && input[i + 1] == '/'))
            {
                i++;
            }

            if (input[i] != '\0')
                i += 2;

            continue;
        }

        /* Identify identifiers */
        if (isalpha(input[i]) || input[i] == '_')
        {
            char identifier[MAX];
            int j = 0;

            while (isalnum(input[i]) || input[i] == '_')
            {
                if (j < MAX - 1)
                    identifier[j++] = input[i];

                i++;
            }

            identifier[j] = '\0';

            printf("IDENTIFIER : %s\n", identifier);
            continue;
        }

        /* Identify constants */
        if (isdigit(input[i]))
        {
            char constant[MAX];
            int j = 0;

            while (isdigit(input[i]) || input[i] == '.')
            {
                if (j < MAX - 1)
                    constant[j++] = input[i];

                i++;
            }

            constant[j] = '\0';

            printf("CONSTANT   : %s\n", constant);
            continue;
        }

        /* Identify operators */
        if (isOperator(input[i]))
        {
            printf("OPERATOR   : %c\n", input[i]);
            i++;
            continue;
        }

        /* Ignore other symbols */
        i++;
    }

    return 0;
}