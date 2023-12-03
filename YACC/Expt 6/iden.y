%{
	#include <stdio.h>;
	int valid=1;
%}

%token letter digit

%%
start:letter S
S : letter S
| digit S
|;
	
%%

int yyerror()
{
	printf("\nInvalid identifier\n\n");
	valid = 0;
	return 0;
}	

void main()
{
	printf("\nEnter an identifier : ");
	yyparse();
	if(valid == 1)
	{
		printf("\nValid identifier\n\n");
	}
}
