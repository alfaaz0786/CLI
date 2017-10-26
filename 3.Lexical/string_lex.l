%{
#include<stdio.h>


char key[20];
%}

num (010)*
%%

{num}+ {printf ("pattern Accepted");}
.*     {printf ("pattern Rejected");}

%%

int main(int argc , char *argv[])
{	
	printf("enter the string");
	yylex();

}
int yywrap()
{
return 1;
}


/* output:
prjlab@prjlab-dx2480-MT:~/Desktop$ lex string.l
prjlab@prjlab-dx2480-MT:~/Desktop$ cc lex.yy.c -ll -ly
prjlab@prjlab-dx2480-MT:~/Desktop$ ./a.out 
enter the string 010
pattern Rejected
010010
pattern Accepted
010010010
pattern Accepted
101
pattern Rejected
*/
