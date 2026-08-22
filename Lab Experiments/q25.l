%{
#include <stdio.h>
%}

%%
[A-Z][A-Z0-9_]*    { printf("Capital Word: %s\n", yytext); }
[ \t\n]+           ;
.                  ;
%%

int main()
{
    printf("Enter a sentence:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}