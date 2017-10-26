%{
  #include<stdio.h>
  #include<string.h>
  FILE *fp1, *fp2;
  char key1[20],key2[20];
%}

word [a-zA-Z0-9]*
space " "
newline [\n]
%%
{word} {if(strcmp(key1,yytext)==0)
{
fprintf(fp2,"%s",key2);
}
else 
{
fprintf(fp2,"%s",yytext);
}
}
{space} {fprintf(fp2,"%s",yytext);}
{newline} {fprintf(fp2,"%s",yytext);}	
%%

int main(int argc, char *argv[])
{
	fp1=fopen(argv[1],"r");	
	fp2=fopen(argv[2],"w");
	printf("\nEnter the string which you want to replace: ");
	scanf("%s",key1);
	printf("\nEnter the string with which you want to replace: ");
	scanf("%s",key2);
	yyin=fp1;
	yyout=fp2;
	yylex();
}
int yywrap()
{
return 1;
}

/*

OUTPUT:

prjlab@prjlab-dx2480-MT:~/word$ ./a.out ip.txt op2.txt

Enter the string which you want to replace: where

Enter the string with which you want to replace: how
prjlab@prjlab-dx2480-MT:~/word$ 


INPUT FILE(ip.txt):

Good morning
where are you

OUTPUT FILE:

Good morning
how are you

*/
