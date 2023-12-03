#include<stdio.h>
#include<string.h>
void main()
{
	FILE *f1,*f2;
	char op[5],a1[5],a2[5],res[5];
	f1=fopen("Input.txt","r");
	f2=fopen("Output.txt","w");
	fscanf(f1,"%s%s%s%s",op,a1,a2,res);	
	while(!feof(f1))
	{
		if(strcmp(op,"+")==0)
		{
			fprintf(f2,"\nMOV R0,%s",a1);
			fprintf(f2,"\nADD R0,%s",a2);
			fprintf(f2,"\nMOV %s,R0",res);
		}
		if(strcmp(op,"-")==0)
		{
			fprintf(f2,"\nMOV R0,%s",a1);
			fprintf(f2,"\nSUB R0,%s",a2);
			fprintf(f2,"\nMOV %s,R0",res);
		}
		if(strcmp(op,"*")==0)
		{
			fprintf(f2,"\nMOV R0,%s",a1);
			fprintf(f2,"\nMUL R0,%s",a2);
			fprintf(f2,"\nMOV %s,R0",res);
		}
		if(strcmp(op,"/")==0)
		{
			fprintf(f2,"\nMOV R0,%s",a1);
			fprintf(f2,"\nDIV R0,%s",a2);
			fprintf(f2,"\nMOV %s,R0",res);
		}
		if(strcmp(op,"=")==0)
		{
			fprintf(f2,"\nMOV R0,%s",a1);
			fprintf(f2,"\nMOV %s,R0",res);
		}
		fscanf(f1,"%s%s%s%s",op,a1,a2,res);
	}
	printf("8086 Assembly Language Instruction Generated Successfully.\n");
	fclose(f1);
	fclose(f2);
}

/*

INPUT

+ a b t1
- c d t2
= t ? x

OUTPUT

MOV R0,a
ADD R0,b
MOV t1,R0
MOV R0,c
SUB R0,d
MOV t2,R0
MOV R0,t
MOV x,R0

*/
