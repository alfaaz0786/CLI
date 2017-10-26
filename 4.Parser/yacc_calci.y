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

S : E {printf("\n result : %d ",$1);}
;
E : E '+' E {$$ = $1 + $3;}
  | E '-' E {$$ = $1 - $3;}
  | E '*' E {$$ = $1 * $3;}
  | E '/' E {$$ = $1 / $3;}
  | NUM {$$ = $1;}
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
 prjlab@prjlab-dx2480-MT:~$ cd Desktop
prjlab@prjlab-dx2480-MT:~/Desktop$ cd BEB29
prjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ yacc -d yacc_calci.y
yacc_calci.y: warning: 16 shift/reduce conflicts [-Wconflicts-sr]
prjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ lex lex_calci.l
prjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ gcc lex.yy.c y.tab.c -ll -ly
prjlab@prjlab-dx2480-MT:~/Desktop/BEB29$ ./a.out
2+3*5

 result : 17
 
