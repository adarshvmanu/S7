%{
#include<stdio.h>
int c=0,count=0;
%}
identifier[a-zA-Z][a-zA-Z0-9]*
string["][a-z A-Z 0-9 %]*["]
%%
" "|"\t" {}
#.* {printf("%s is a Preprocessor Directive\n",yytext);}
\(|\)|\%|\;|\,|\!|\[|\] {printf("%s is a Special Symbol\n",yytext);}
int|void|main|scanf|char|if|else|do|while|printf {printf("%s is a Keyword\n",yytext);}
"/*" {c=1;}
"*/" {c=0;count++;}
\{ {printf("Block Begins\n");}
\} {printf("Block Ends\n");}
{identifier} {if(!c)printf("%s is an Identifier\n",yytext);}
{string} {printf("%s is a String\n",yytext);}
[0-9]+ {printf("%s is a Number\n",yytext);}
\=|\<|\>|\<=|\>=|\== {printf("%s is a Relational Operator\n",yytext);}
\+|\-|\*|\/ {printf("%s is an Arithmetic Operator\n",yytext);} 

%%
void main(int argc,char* argv[]){
	yyin=fopen(argv[1],"r");
	yylex();
	printf("Number of Comments : %d\n",count);
}
int yywrap(){
	return 1;
}

/*
OUTPUT

#include<stdio.h> is a Preprocessor Directive

void is a Keyword
main is a Keyword
( is a Special Symbol
) is a Special Symbol

Block Begins

int is a Keyword
a is an Identifier
= is a Relational Operator
5 is a Number
, is a Special Symbol
b is an Identifier
= is a Relational Operator
7 is a Number
, is a Special Symbol
c is an Identifier
; is a Special Symbol

printf is a Keyword
( is a Special Symbol
"This is a String" is a String
) is a Special Symbol
; is a Special Symbol

c is an Identifier
= is a Relational Operator
a is an Identifier
+ is an Arithmetic Operator
b is an Identifier
; is a Special Symbol

printf is a Keyword
( is a Special Symbol
"%d" is a String
, is a Special Symbol
c is an Identifier
) is a Special Symbol
; is a Special Symbol

Block Ends

Number of Comments : 1
*/
