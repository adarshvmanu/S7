#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[10],stack[10];
int i=0,j=0,z=0,c=0,m=0,k;
void check()
{
 m=strlen(stack);
 for(z=0;z<m;z++)
 {
  if(stack[z]=='i'&&stack[z+1]=='d'){
   stack[z]='E';
   stack[z+1]='\0';
   printf("\n$%s\t\t%s\t\tReduce to E",stack,a);
  }
 }
 
 for(z=0;z<m;z++)
 {
  if(stack[z]=='E'&&stack[z+1]=='+'&&stack[z+2]=='E'){
   stack[z]='E';
   stack[z+1]='\0';
   printf("\n$%s\t\t%s\t\tReduce to E",stack,a);
   i=i-2;
  }
 }
 
 for(z=0;z<m;z++)
 {
  if(stack[z]=='E'&&stack[z+1]=='*'&&stack[z+2]=='E'){
   stack[z]='E';
   stack[z+1]='\0';
   printf("\n$%s\t\t%s\t\tReduce to E",stack,a);
   i=i-2;
  }
 }
 
 for(z=0;z<m;z++)
 {
  if(stack[z]=='('&&stack[z+1]=='E'&&stack[z+2]==')'){
   stack[z]='E';
   stack[z+1]='\0';
   printf("\n$%s\t\t%s\t\tReduce to E",stack,a);
   i=i-2;
  }
 }
}

void main()
{
 puts("Grammar : \nE-->E+E \nE-->E*E \nE-->(E) \nE-->id");
 printf("\n\nEnter the string : ");
 scanf("%s",a);
 c=strlen(a);
 printf("\nSTACK\t\tINPUT\t\tACTION");
 for(i=0,j=0;j<c;i++,j++)
 {
  if(a[j]=='i'&&a[j+1]=='d')
  {
   stack[i]=a[j];
   stack[i+1]=a[j+1];
   stack[i+2]='\0';
   a[j]=' ';
   for(k=j+1;k<c;k++)
   {
    a[k]=a[k+1];
   }
   c=strlen(a);
   printf("\n$%s\t\t%s\t\tShift-->id",stack,a);
   check();
  }
  else
  {
   stack[i]=a[j];
   stack[i+1]='\0';
   a[j]=' ';
   printf("\n$%s\t\t%s\t\tShift-->Symbol",stack,a);
   check();
  }
 }
 while(m>1){
    check();
    m=strlen(stack);
  }
 printf("\n");
}

/* 
OUTPUT

user@user-Lenovo-H50-50:~/Desktop/S7R205/Shift Reduce Parser$ gcc SRP.c
user@user-Lenovo-H50-50:~/Desktop/S7R205/Shift Reduce Parser$ ./a.out
Grammar : 
E-->E+E 
E-->E*E 
E-->(E) 
E-->id


Enter the string : id+(id*id)

STACK		INPUT		ACTION
$id		 +(id*id)		Shift-->id
$E		 +(id*id)		Reduce to E
$E+		  (id*id)		Shift-->Symbol
$E+(		   id*id)		Shift-->Symbol
$E+(id		    *id)		Shift-->id
$E+(E		    *id)		Reduce to E
$E+(E*		     id)		Shift-->Symbol
$E+(E*id	       )		Shift-->id
$E+(E*E		      )		        Reduce to E
$E+(E		      )		        Reduce to E
$E+(E)		       		        Shift-->Symbol
$E+E		       		        Reduce to E
$E		       		        Reduce to E

*/
