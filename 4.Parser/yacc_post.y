%{
	#include <stdio.h>
	void yyerror();
	int yylex();
%}
%union
{
	int dval;
}
%token <dval>NUM
%type <dval>E
%%

S : E 
;
E : E '+' E {printf("+");}
  | E '-' E {printf("-");}
  | E '*' E {printf("*");}
  | E '/' E {printf("/");}
  | NUM {$$ = $1;
  		printf("%d",$1);
  	}
;
%%
int main()
{
	yyparse();
	return 1;
}
 void yyerror()
 {
 	printf("\n Error");
 }
 
 
 OUTPUT:
 
prjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ lex lex_calci.l
prjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ gcc lex.yy.c y.tab.c -ll -ly
prjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ ./a.out
2+3*5
235*+
