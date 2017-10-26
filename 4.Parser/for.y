%{
#include<stdio.h>
int flag=0;
%}

%token FOR OPBR CLBR SEMIC RELOP EQU ID NUM INC DEC RELOP RELOP RELOP RELOP

%%

S:FOR OPBR E1 SEMIC E2 SEMIC E3 CLBR {printf
("Accepted!");flag=1;}
;

E1:ID EQU ID
|  ID EQU NUM
;
E2:ID RELOP ID
|  ID RELOP NUM
;
E3:ID INC
|  ID DEC
;

%%

main()
{
yyparse();
}

yyerror()
{
if(flag==0)
printf("For Loop Error");
}

yywrap()
{
return 1;
}

