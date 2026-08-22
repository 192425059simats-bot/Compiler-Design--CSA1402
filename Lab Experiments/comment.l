%{
#include <stdio.h>
int comment_count = 0;
FILE *out;
%}

%%
"//".*                  { comment_count++; }
"/*"([^*]|\*+[^*/])*\*+"/" { comment_count++; }
\n                      { fprintf(out, "\n"); }
.                       { fprintf(out, "%s", yytext); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    out = fopen("output.c", "w");

    if (out == NULL)
    {
        printf("Error opening output file.\n");
        return 1;
    }

    yylex();

    fclose(out);

    printf("Number of comment lines: %d\n", comment_count);

    return 0;
}