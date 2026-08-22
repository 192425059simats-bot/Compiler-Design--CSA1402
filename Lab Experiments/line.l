%{
#include <stdio.h>
int line_no = 1;
%}

%%
\n      { printf("\n%4d  ", ++line_no); }
.       { printf("%s", yytext); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("%4d  ", line_no);
    yylex();
    return 0;
}