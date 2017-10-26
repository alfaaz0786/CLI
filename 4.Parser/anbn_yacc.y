%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B NL
%%
start:s NL	{printf("\n\tValid Series");}
s: A s1 B;
s1: A s1 B|A B;
%%
main()
{
	printf("\n\tEnter a Series: ");
	yyparse();
}
int yyerror(char *s)
{
	printf("\n\tInvalid Series");
	exit(0);
}



OUTPUT:
prjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ yacc -d anbn.y
prjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ lex anbn.l
prjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ gcc lex.yy.c y.tab.c -ll -ly
prjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ ./a.out

	Enter a Series: aabb

	Valid Series

	Invalid Seriesprjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ ./a.out

	Enter a Series: aaabb

	Invalid Seriesprjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ ./a.out

	Enter a Series: aaabbb

	Valid Seriesaaabb

	Invalid Seriesprjlab@prjlab-dx2480-MT:~/Desktop/BEB29$
