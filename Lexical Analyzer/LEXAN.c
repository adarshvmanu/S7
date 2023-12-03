#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main ()
{
	FILE *fp;
	int t=0;
	int j=0;
	int i,flag;
	char ch,str[20];
	fp=fopen("prgm.c","r");
	
	char keyword[30][30] = {"void","main","if","else","do","while","printf","scanf","include","stdio","int"};

	while(!feof(fp))
	{
		i=0;
		flag=0;
		ch=fgetc(fp);
	        if( ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch==',' || ch=='!' || ch=='%'|| ch=='#')

		{

			printf("%c is a Special symbol\n",ch);
			t++;
		}
		
		else if( ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='='|| ch=='<'||ch=='>')
		{
			printf("%c is an Operator\n",ch);
			t++;
		}

		else if(isdigit(ch))
		{
			printf("%c is a Digit\n",ch);
			t++;
		}

		else if(isalpha(ch))
		{
			str[i]=ch;
			i++;
			ch=fgetc(fp);
			while(isalnum(ch) && ch!=' ')
			{
				str[i]=ch;
				i++;
				ch=fgetc(fp);
			}
			str[i]='\0';
			for(j=0;j<=30;j++)
			{
				if(strcmp(str,keyword[j])==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				printf("%s is a Keyword\n",str);
				t++;
			}
			else
			{
				printf("%s is an Identifier\n",str);
				t++;
			}
			if( ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch==',' || ch=='!' || ch=='%'|| ch=='#')
			{
				printf("%c is a Special symbol\n",ch);
				t++;
			}
		}
		else if(ch=='\n'){}
	}
	fclose(fp);	
	return 0;
}


/*
OUTPUT

void is a Keyword
main is a Keyword
( is a Special symbol
) is a Special symbol
{ is a Special symbol
int is a Keyword
a is an Identifier
5 is a Digit
, is a Special symbol
b is an Identifier
7 is a Digit
, is a Special symbol
c is an Identifier
; is a Special symbol
c is an Identifier
a is an Identifier
b is an Identifier
; is a Special symbol
printf is a Keyword
( is a Special symbol
% is a Special symbol
d is an Identifier
, is a Special symbol
c is an Identifier
) is a Special symbol
; is a Special symbol
} is a Special symbol

*/
