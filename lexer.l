%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.tab.h"
//extern YYSTYPE yylval;

%}
%option noyywrap

delim           [ \t]
whitesp         {delim}+

%%

"+"                     { return PLUS; }
"-"                     { return MINUS; }
"/"                     { return SLASH; }
"*"                     { return ASTERISK; }
"%"                     { return PERCENT; }
"="                     { return EQUALS; }
";"                     { return SEMI; }
"("                     { return LPAREN; }
")"                     { return RPAREN; }
"print"                 { return PRINT; }
[a-zA-Z][a-zA-Z0-9_]*   { yylval.str = strdup(yytext); return REF; }
XXXX[-]?[0-9]+    { sscanf(yytext, "%ld", &yylval.ival); return INT; }
[-]?[0-9]+    { yylval.ival = strtol(yytext, NULL, 10); return INT; }
[-]?[0-9]*[.]?[0-9]+    { sscanf(yytext, "%lf", &yylval.fval); return FLOAT; }
