#include <stdio.h>

int main()
{
    char input;

    printf("Enter an operator: ");
    scanf("%c", &input);

    switch (input)
    {
        case '+':
            printf("Valid Arithmetic Operator: +\n");
            break;

        case '-':
            printf("Valid Arithmetic Operator: -\n");
            break;

        case '*':
            printf("Valid Arithmetic Operator: *\n");
            break;

        case '/':
            printf("Valid Arithmetic Operator: /\n");
            break;

        default:
            printf("Invalid Arithmetic Operator\n");
    }

    return 0;
}