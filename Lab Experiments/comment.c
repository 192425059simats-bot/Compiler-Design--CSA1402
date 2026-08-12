#include <stdio.h>
#include <string.h>

int main()
{
    char input[500];

    printf("Enter a line:\n");
    fgets(input, sizeof(input), stdin);

    /* Check for single-line comment */
    if (input[0] == '/' && input[1] == '/')
    {
        printf("It is a single-line comment.\n");
    }

    /* Check for multi-line comment */
    else if (input[0] == '/' && input[1] == '*')
    {
        if (strstr(input, "*/") != NULL)
        {
            printf("It is a multi-line comment.\n");
        }
        else
        {
            printf("It is an incomplete multi-line comment.\n");
        }
    }

    /* Not a comment */
    else
    {
        printf("It is not a comment.\n");
    }

    return 0;
}