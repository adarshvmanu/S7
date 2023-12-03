%{
	#include "y.tab.h";
%}

%%

[a-zA-Z]+ {return letter;}
[0-9]+ {return digit;}
[\t];
[\n] {return 0;}
. {return (yytext[0]);}

%%

int yywrap()
{
	return 1;
}

/*

OUTPUT

user@user-Lenovo-H50-50:~/Desktop/S7R205/YACC/Expt 6$ yacc -d iden.y
user@user-Lenovo-H50-50:~/Desktop/S7R205/YACC/Expt 6$ lex iden.l
user@user-Lenovo-H50-50:~/Desktop/S7R205/YACC/Expt 6$ gcc lex.yy.c y.tab.c -w
user@user-Lenovo-H50-50:~/Desktop/S7R205/YACC/Expt 6$ ./a.out

Enter an identifier : camelCase

Valid identifier

*/
