%{
#include "y.tab.h"
extern int yylval;
%}
%%
(int)+				{ yylval = atoi(yytext); return INT; }
[ \t] ; 			/* ignore whitespace */
\n return 0; 		/* logical EOF */
. return yytext[0];
%%
