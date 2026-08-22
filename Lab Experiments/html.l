%{
#include <stdio.h>
%}

%%
"<"[^>]+">"    { printf("%s\n", yytext); }
.|\n           ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("HTML Tags:\n");
    yylex();
    return 0;
}