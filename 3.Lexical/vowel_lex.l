%{
	#include<stdio.h>
	FILE *fp;
	int vc=0 , sc=0 , cc=0;
%}

vowel [aeiouAEIOU]
consonant [a-zA-Z]
SP " "
%%

{vowel} {vc++;}
{consonant} {cc++;}
{SP} {sc++;}

%%

int main(int argc , char argv[])
{
	fp = fopen("myfile1.txt","r");
	yyin = fp;
	yylex();
	printf("vowel count = %d\n" , vc);
	printf("consonant count = %d\n" , cc);
	printf("space count = %d\n" , sc);
	return 0;
}

/*output
prjlab@prjlab-dx2480-MT:~/Desktop$ lex ass2.l
prjlab@prjlab-dx2480-MT:~/Desktop$ cc lex.yy.c -ll -ly
prjlab@prjlab-dx2480-MT:~/Desktop$ ./a.out

vowel count = 3
consonant count = 7
space count = 2

string
All the Best
*/
