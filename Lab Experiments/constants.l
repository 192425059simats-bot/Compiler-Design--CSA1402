%{
#include <stdio.h>
%}

%%

[0-9]+(\.[0-9]+)? {
    printf("Constant: %s\n", yytext);
}

\"([^\"\\]|\\.)*\" {
    /* Ignore string constants */
}

.|\n {
    /* Ignore other characters */
}

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Constants in the C program:\n");
    yylex();

    return 0;
}