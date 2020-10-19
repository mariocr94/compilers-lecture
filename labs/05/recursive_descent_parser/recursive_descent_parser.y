//E -> T | T + E
//T -> int | int * T | (E)
// Receives the word int.

%{
#include <stdio.h>
%}

%token INT
%%

statement: expression		         {printf("Parsing\n", $1);}
 ;

expression: INT '+' expression      { $$ = $1 + $3;}
 | INT '*' expression               { $$ = $1 * $3;}
 | '(' expression ')'               { $$ = $2;}
 | INT                              { $$ = $1;}
 ;
