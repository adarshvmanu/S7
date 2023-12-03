#include<stdio.h>
#include<string.h>
char stk[30],a[30],act1[30],act2[30];
int i=0,j=0,k=0,n;
void check();
void main()
{
 puts("Grammar:\nE->E+E\nE->E*E\nE->(E)\nE->id");
 printf("Enter the i/p string:");
 scanf("%s",a);
 n=strlen(a);
 strcpy(act1,"Shift->");
 puts("\nStack\t\tI/P string\t\tAction\n");
 for(i=0,j=0;j<n;i++,j++)
 {
  if((a[j]=='i')&&(a[j+1]=='d'))
  {
   stk[i]=a[j];
   stk[i+1]=a[j+1];
   stk[i+2]='\0';
   a[j]=' ';
   a[j+1]=' ';
   j++;
   printf("\n$%s\t\t%s$\t\t%sid",stk,a,act1);
   check();
  }
  else
  {
   stk[i]=a[j];
   stk[i+1]='\0';
   a[j]=' ';
   printf("\n$%s\t\t%s$\t\t%ssymbol",stk,a,act1);
   check();
  }
 }
 check();
}
void check()
{
 strcpy(act2,"Reduce to E");
 for(k=0;k<n;k++)
 {
  if((stk[k]=='i')&&(stk[k+1]=='d'))
  {
   stk[k]='E';
   stk[k+1]='\0';
   printf("\n$%s\t\t%s$\t\t%s",stk,a,act2);
  }
 }
 for(k=0;k<n;k++)
 {
  if((stk[k]=='E')&&(stk[k+1]=='+'||stk[k+1]=='*')&&(stk[k+2]=='E'))
  {
   i=i-2;
   stk[k]='E';
   stk[k+1]='\0';
   printf("\n$%s\t\t%s$\t\t%s",stk,a,act2);
  }
 }
 for(k=0;k<n;k++)
 {
  if((stk[k]=='(')&&(stk[k+1]=='E')&&(stk[k+2]==')'))
  {
   i=i-2;
   stk[k]='E';
   stk[k+1]='\0';
   printf("\n$%s\t\t%s$\t\t%s",stk,a,act2);
  }
 } 
}
/*--OUTPUT--
Stack		I/P string		Action

$id		  +(id*id)$		Shift->id
$E		  +(id*id)$		Reduce to E
$E+		   (id*id)$		Shift->symbol
$E+(		    id*id)$		Shift->symbol
$E+(id		      *id)$		Shift->id
$E+(E		      *id)$		Reduce to E
$E+(E*		       id)$		Shift->symbol
$E+(E*id		         )$		Shift->id
$E+(E*E		         )$		Reduce to E
$E+(E		         )$		Reduce to E
$E+(E)		          $		Shift->symbol
$E+E		          $		Reduce to E
$E		          $		Reduce to E */
