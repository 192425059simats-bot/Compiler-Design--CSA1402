#include <stdio.h>
#include <ctype.h>

char expression[100];
int temp = 1;

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

int main()
{
    char lhs;
    char operands[100][20];
    char operators[100];
    int opTop = -1;
    int operandTop = -1;

    printf("Enter assignment expression: ");
    scanf("%s", expression);

    lhs = expression[0];

    int i = 2;

    while (expression[i] != '\0')
    {
        if (isalnum(expression[i]))
        {
            char tempOperand[20];

            tempOperand[0] = expression[i];
            tempOperand[1] = '\0';

            operandTop++;
            strcpy(operands[operandTop], tempOperand);
        }
        else if (expression[i] == '+' ||
                 expression[i] == '-' ||
                 expression[i] == '*' ||
                 expression[i] == '/')
        {
            while (opTop >= 0 &&
                   precedence(operators[opTop]) >= precedence(expression[i]))
            {
                char a[20], b[20], result[20];

                strcpy(b, operands[operandTop--]);
                strcpy(a, operands[operandTop--]);

                sprintf(result, "t%d", temp++);

                printf("%s = %s %c %s\n",
                       result, a, operators[opTop], b);

                strcpy(operands[++operandTop], result);
                opTop--;
            }

            operators[++opTop] = expression[i];
        }

        i++;
    }

    while (opTop >= 0)
    {
        char a[20], b[20], result[20];

        strcpy(b, operands[operandTop--]);
        strcpy(a, operands[operandTop--]);

        sprintf(result, "t%d", temp++);

        printf("%s = %s %c %s\n",
               result, a, operators[opTop], b);

        strcpy(operands[++operandTop], result);
        opTop--;
    }

    printf("%c = %s\n", lhs, operands[operandTop]);

    return 0;
}