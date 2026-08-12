%{
#include <stdio.h>

int whitespace = 0;
int newline = 0;
%}

%%

[ \t]+      {
                whitespace += yyleng;
            }

\n          {
                newline++;
            }

.           {
                /* Ignore other characters */
            }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the text (Press Ctrl+Z and Enter to finish):\n");

    yylex();

    printf("\nNumber of whitespaces : %d\n", whitespace);
    printf("Number of newlines    : %d\n", newline);

    return 0;
}