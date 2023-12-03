%{
#include<stdio.h>
int l=0,w=0,c=0;
%}
%%

[a-z] {c++;}
[A-Z] {c++;}
[0-9] {c++;} 
" " {w++;}
"\n" {l++;w++;}

%%
void main(int argc,char* argv[]){
	yyin=fopen(argv[1],"r");
	yylex();
	printf("Words : %d\n",w);
	printf("Lines : %d\n",l);
	printf("Characters : %d\n",c);
}
int yywrap(){
	return 1;
}

/*
OUTPUT

Words : 4
Lines : 3
Characters : 16
*/
