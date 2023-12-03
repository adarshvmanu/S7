%{
#include<stdio.h>
int v=0,c=0;
%}
%%

[ \n\t]+ ;
[aeiouAEIOU] {v++;}
[^aeiouAEIOU] {c++;}

%%
int main(){
	printf("Enter the input string : ");
	yylex();
	printf("Vowels : %d\n",v);
	printf("Consonants : %d\n",c);
}
int yywrap()
{
	return 1;
}

/*
OUTPUT

Enter the input string : Hello Abhinav
Vowels : 5
Consonants : 7
*/
