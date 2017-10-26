%{
	#include<stdio.h>
	FILE *fp;
	int wc=0 , cc=0 , sc=0 , lc=0 , nc=0 , ssc=0 ;
%}

word [a-zA-Z]+
ssymbol ['@'|'$'|'#'|'&'|'!']
digit [0-9]
LN "\n"
SP " "
%%

{word} {wc++ ; cc+=yyleng;}
{ssymbol} {ssc++;}
{digit} {nc++;}
{LN} {lc++;}
{SP} {sc++;}
%%

int main( int argc , char argv[] )
{
	fp = fopen("myfile.txt","r");
	yyin = fp;
	yylex();
	printf("word count = %d\n" , wc);
	printf("symbol count = %d\n" , ssc);
	printf("digit count = %d\n" , nc);
	printf("line count = %d\n" , lc);
	printf("space count = %d\n" , sc);
	return 0;

}



/*output
prjlab@prjlab-dx2480-MT:~/Desktop$ lex ass1.l
prjlab@prjlab-dx2480-MT:~/Desktop$ cc lex.yy.c -ll -ly
prjlab@prjlab-dx2480-MT:~/Desktop$ ./a.out
word count = 2
symbol count = 2
digit count = 3
line count = 6
space count = 1

myfile.txt
ABC
aabn
2
3
4
@ #
*/
