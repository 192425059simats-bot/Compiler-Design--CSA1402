%{
#include <stdio.h>

int characters = 0;
int words = 0;
int lines = 0;
%}

%x COMMENT

%%

"//".*                  { characters += yyleng; }

"/*"                    {
                            characters += yyleng;
                            BEGIN(COMMENT);
                        }

<COMMENT>"*/"           {
                            characters += yyleng;
                            BEGIN(INITIAL);
                        }

<COMMENT>\n             {
                            lines++;
                            characters++;
                        }

<COMMENT>.              {
                            characters++;
                        }

\n                      {
                            lines++;
                            characters++;
                        }

[ \t]+                  {
                            characters += yyleng;
                        }

[a-zA-Z0-9_]+           {
                            characters += yyleng;
                            words++;
                        }

.                       {
                            characters++;
                        }

%%

int yywrap()
{
    return 1;
}

int main()
{
    yylex();

    printf("\nNumber of characters : %d\n", characters);
    printf("Number of lines      : %d\n", lines);
    printf("Number of words      : %d\n", words);

    return 0;
}