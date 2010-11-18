%{

#include <stdlib.h>
#include <stdio.h>
#include "type.h"
#include "operation.h"
#include "table.h"

%}

%union {
    char *str;
    long ival;
    double fval;
    struct type_value *val;
};

%token PLUS MINUS SLASH ASTERISK PERCENT EQUALS SEMI LPAREN RPAREN PRINT
%token <str> REF
%token <ival> INT 
%token <fval> FLOAT 

%type <val> value factor term expr

%%

statements:
        /* empty */
    |   statements statement
    ;

statement:
        SEMI
    |   REF EQUALS expr { table_set($1, $3); printf("\tset %s to ", $1); type_print($3); printf("\n"); }
    |   PRINT expr      { if ($2) type_print($2); }
    ;

value:
        INT             { $$ = type_construct(TYPE_INT, &$1); }
    |   FLOAT           { $$ = type_construct(TYPE_FLOAT, &$1); }
    |   REF             {
            sym_t* var = table_get($1);
            if (var != NULL) {
                $$ = var->val;
            } else {
                yyerror("Could not find variable"); 
            }
    }
    ;

expr:
        expr PLUS term { $$ = operation(OP_ADD, $1, $3); }
    |   expr MINUS term { $$ = operation(OP_SUBTRACT, $1, $3); }
    |   term
    ;

term: 
        term ASTERISK factor    { $$ = operation(OP_MULTIPLY, $1, $3); }
    |   term SLASH factor       { $$ = operation(OP_DIVIDE, $1, $3); }
    |   term PERCENT factor       { $$ = operation(OP_MODULUS, $1, $3); }
    |   factor
    ;

factor:
        LPAREN expr RPAREN      { $$ = $2; }
    |   value
    ;

%%

#include <stdio.h>
#include "type.h"

int yyerror(char *s) {
    printf("%s\n", s);
    return 0;
}

int main(void) {
    type_initialize_builtins();
    yyparse();
    exit(0);
}
