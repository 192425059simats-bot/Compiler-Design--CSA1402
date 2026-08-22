%{
#include <stdio.h>
%}

%%
https?://[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}(/[a-zA-Z0-9_./-]*)?
        { printf("Valid URL\n"); }

.*      { printf("Invalid URL\n"); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    yylex();
    return 0;
}