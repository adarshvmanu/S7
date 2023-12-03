%{
	#include "y.tab.h";
	extern int yylval;
%}

%%
[0-9]+ {yylval = atoi(yytext);return Number;}
[\t];
[\n] return 0;
. {return yytext[0];}
%%

int yywrap()
{
	return 1;
}

/*

OUTPUT

user@user-Lenovo-H50-50:~/Desktop/S7R205/YACC/Expt 7$ yacc -d aexp.y
user@user-Lenovo-H50-50:~/Desktop/S7R205/YACC/Expt 7$ lex aexp.l
user@user-Lenovo-H50-50:~/Desktop/S7R205/YACC/Expt 7$ gcc lex.yy.c y.tab.c -w
user@user-Lenovo-H50-50:~/Desktop/S7R205/YACC/Expt 7$ ./a.out

Enter an Arithmatic Expression : 3*4+5

Result : 17

Valid Arithmatic Expression

*/
