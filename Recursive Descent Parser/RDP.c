#include<stdio.h>
#include<string.h>
#include<ctype.h>
int i=0,error=0;
char input[10];
void E();
void Eprime();
void T();
void Tprime();
void F();
void main()
{
	printf("Enter the Arithmetic Expression : ");
	scanf("%s",input);
	E();
	if(strlen(input)==i&&error==0)
		printf("Expression is Accepted\n");
	else
		printf("Expression is Rejected\n");
}
void E(){
	T();
	Eprime();
}
void Eprime(){
	if(input[i]=='+'){
		i++;
		T();
		Eprime();
	}
}
void T(){
	F();
	Tprime();
}
void Tprime(){
	if(input[i]=='*'){
		i++;
		F();
		Tprime();
	}
}
void F(){
	if(isalnum(input[i]))
		i++;
	else if(input[i]=='(')
	{
		i++;
		E();
		if(input[i]==')')
			i++;
		else 
			error=1;
	}
	else
		error=1;
}



/*
	OUTPUT
	
user@user-Lenovo-H50-50:~/Desktop/S7R205/Recursive Descent Parser$ gcc RDP.c
user@user-Lenovo-H50-50:~/Desktop/S7R205/Recursive Descent Parser$ ./a.out
Enter the Arithmetic Expression : 2*4+5*(7)+8
Expression is Accepted
user@user-Lenovo-H50-50:~/Desktop/S7R205/Recursive Descent Parser$ ./a.out
Enter the Arithmetic Expression : 4*5/2
Expression is Rejected

*/
