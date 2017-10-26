%{
	#include<stdio.h>
	FILE *fp1 ;
	
%}

preprocessor 	#.*
function 	main"(".")"*|printf"(".*");"*|scanf"(".*");"
userdefine 	[a-zA-Z]+"(".*");"
keyword 	int|char|float|double
condition 	if|else
identifier 	[a-zA-Z]+
operator 	[+|-|/|*]
reloperator 	["<="|">="|"<"|">"]
comment 	"/*"[\t\n]*.*[\n].*"*/"|"//".[\t\n]*.*
whitespace 	[" "|"\n"|"\t"]
brackets 	"{"|"}"|"["|"]"|"("|")"
token 		;

%%
{preprocessor} 	{printf ("\nit is preprocessor           \t"); printf("%s",yytext);}
{function} 	{printf ("\nit is function	         \t"); printf("%s",yytext);}
{userdefine} 	{printf ("\nit is user define function   \t"); printf("%s",yytext);}
{condition} 	{printf ("\nit is condition oper         \t"); printf("%s",yytext);}
{keyword} 	{printf ("\nit is keyword                \t"); printf("%s",yytext);}
{identifier}    {printf ("\nit is identifier             \t"); printf("%s",yytext);} 
{operator} 	{printf ("\nit is operator               \t"); printf("%s",yytext);}
{reloperator}   {printf ("\nit is relational operator    \t"); printf("%s",yytext);}
{comment} 	{printf ("\nit is comment                \t"); printf("%s",yytext);}
{whitespace}    {printf ("\nit is whitespace             \t"); printf("%s",yytext);}
{brackets} 	{printf ("\nit is brackets               \t"); printf("%s",yytext);}
{token} 	{printf ("\nit is semicolon              \t"); printf("%s",yytext);}

%%

int main (int argc , char argv[])
{
	fp1 = fopen("input.c","r");
	yyin = fp1;
	yylex();

}

int yywrap()			
{
return 1;
}


INPUT:

//Program to find Greater Number
#include<stdio.h>
using namespace std

void main()
{
	int i;
	printf("\n enter 1 no");
	scanf("%d",n);
	i++;

}



INPUT:

OUTPUT:
prjlab@prjlab-dx2480-MT:~/Desktop$ lex token.l
prjlab@prjlab-dx2480-MT:~/Desktop$ cc lex.yy.c -ll -ly
prjlab@prjlab-HP-202-G1-MT:~/Desktop$ ./a.out 

it is whitespace             	

it is comment                	//Program to find Greater Number
it is whitespace             	

it is preprocessor           	#include<stdio.h>
it is whitespace             	

it is identifier             	using
it is whitespace             	 
it is identifier             	namespace
it is whitespace             	 
it is identifier             	std
it is whitespace             	

it is whitespace             	

it is identifier             	void
it is whitespace             	 
it is function	         	main()
it is whitespace             	

it is brackets               	{
it is whitespace             	

it is whitespace             		
it is keyword                	int
it is whitespace             	 
it is identifier             	i
it is semicolon              	;
it is whitespace             	

it is whitespace             		
it is function	         	printf("\n enter 1 no");
it is whitespace             	

it is whitespace             		
it is function	         	scanf("%d",n);
it is whitespace             	

it is whitespace             		
it is identifier             	i
it is operator               	+
it is operator               	+
it is semicolon              	;
it is whitespace             	

it is whitespace             	

it is brackets               	}
it is whitespace 
