#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char a[50][50],ch;
int n;
void first(char ch);
void follow(char ch);
void main()
{
  
    int choice;

    printf("Enter The Number of Productions : ");
    scanf("%d", &n);
    getchar();
    printf("\nEnter the Productions :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }
    do
    {
        printf("\nEnter the Element : ");
        scanf(" %c", &ch);
        
        printf("FIRST(%c) : { ", ch);
        first(ch);
        printf(" }");
        
        printf("\tFOLLOW(%c) : { ", ch);
        follow(ch);
        printf(" }");
        
        printf("\n\nDo You Want to Continue? (1/ 0): ");
        scanf("%d", &choice);

    }while (choice);
}
void first(char ch)
{
    int m=0;
    if(!isupper(ch))
    {
      printf("%c",ch);
    }
    for(int k=0;k<n;k++)
    {
      if(a[k][0]==ch)
      {
         if(islower(a[k][2]))
         {
            printf("%c",a[k][2]);
         }
         else
         first(a[k][2]);
      }
   }
}
void follow(char ch)
{
   
   if(a[0][0]==ch)
   
   printf("$");
     for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < strlen(a[i]); j++)
        {
            if (a[i][j] == ch)
            {
                if (a[i][j + 1] != '\0')
                {
                    if (!isupper(a[i][j + 1]))
                    {
                        printf("%c", a[i][j + 1]);
                    }
                    else
                    {
                        first(a[i][j + 1]);
                    }
                }
                else if (a[i][j] != a[i][0])
                {
                   follow(a[i][0]);
                }
            }
        }
    }
}         

/*  

		OUTPUT

user@user-Lenovo-H50-50:~/Desktop/S7R205/FIRST-FOLLOW$ ./a.out
Enter The Number of Productions : 6

Enter the Productions :
S=aBDh
B=cC 
C=bC
D=EF
E=g
F=f

Enter the Element : S
FIRST(S) : { a }	FOLLOW(S) : { $ }

Do You Want to Continue? (1/ 0): 1

Enter the Element : B
FIRST(B) : { c }	FOLLOW(B) : { g }

Do You Want to Continue? (1/ 0): 1

Enter the Element : C
FIRST(C) : { b }	FOLLOW(C) : { g }

Do You Want to Continue? (1/ 0): 1

Enter the Element : D
FIRST(D) : { g }	FOLLOW(D) : { h }

Do You Want to Continue? (1/ 0): 1

Enter the Element : E
FIRST(E) : { g }	FOLLOW(E) : { f }

Do You Want to Continue? (1/ 0): 1

Enter the Element : F
FIRST(F) : { f }	FOLLOW(F) : { h }

Do You Want to Continue? (1/ 0): 0
*/     




