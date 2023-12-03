%{
	#include<stdio.h>
	int valid = 1;
%}

%token Number;

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

AE : E {printf("\nResult : %d",$$);}
E : E '+' E {$$=$1 + $3 ;}
|E '-' E {$$=$1 - $3 ;}
|E '*' E {$$=$1 * $3 ;}
|E '/' E {$$=$1 / $3 ;}
|E '%' E {$$=$1 % $3 ;}
|'('E')' {$$=$2 ;}
|Number {$$=$1;}
;

%%

int yyerror()
{
	printf("\nInvalid Arithmatic Expression\n");
	valid = 0;
	return 0;
}

void main()
{
	printf("\nEnter an Arithmatic Expression : ");
	yyparse();
	if(valid == 1)
	{
		printf("\n\nValid Arithmatic Expression\n");
	}
}
