//Title : Yacc parser for FOR Loop
//Roll no:
//Class: BE
//Batch : B2

//Lex code
%{
#include"y.tab.h"
extern int yylval;
%}
%%
for { return (FOR); }
"(" { return (OPBR); }
")" { return (CLBR); }
";" {return (SEMIC);  }
"=" { return (EQU); }
"<"|">"|"<="|">="|"^=" { return (RELOP); }
"++" { return (INC); }
"--" { return (DEC); }
[a-zA-Z]+ {yylval=yytext[0];return(ID);}
[0-9]+ {yylval=atof(yytext);return(NUM);}
%%

//Yacc code
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


/*Output:
prjlab@prjlab-HP-dx2480-MT-KL969AV:~$ cd Desktop
prjlab@prjlab-HP-dx2480-MT-KL969AV:~/Desktop$ lex forp.l
prjlab@prjlab-HP-dx2480-MT-KL969AV:~/Desktop$ yacc -d for.y
prjlab@prjlab-HP-dx2480-MT-KL969AV:~/Desktop$ gcc lex.yy.c y.tab.c -ll -ly
prjlab@prjlab-HP-dx2480-MT-KL969AV:~/Desktop$ ./a.out
for(i=0;i<2;i++)
Accepted!
for(i=0;i<2;i++);
prjlab@prjlab-HP-dx2480-MT-KL969AV:~/Desktop$ 
*/

