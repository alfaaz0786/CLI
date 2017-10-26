%{
	#include"y.tab.h"
	#include<stdio.h>
%}

num [0-9]+
eol \n

%%

{num} {yylval.dval = atoi(yytext);
       return NUM;}
{eol} {return 0;} 
.   {return yytext[0];} 

%%


