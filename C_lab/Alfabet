// Alfabet.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#define N 100000
typedef struct Rule
{
    char From;
    char* To;
}Rule;
char* redo(char* Str, Rule* Ysl, int sz)
{
    char* Str2;
    int i, count = 0, j, flag, pos, k;
    for (i = 0; i < strlen(Str); ++i)
    {
   	 flag = 0;
   	 for (j = 0; j < sz; ++j)
   	 {
   		 if (Str[i] == Ysl[j].From)
   		 {
   			 //printf("came\n");
   			 //printf("Ysl[%d].To = ", j);
   			 //puts(Ysl[j].To);
   			 count = count + strlen(Ysl[j].To);
   			 flag = 1;
   			 //printf("count = %d\n", count);
   		 }
   	 }
   	 if (!flag)
   	 {
   		 count++;
   	 }
    }
    Str2 = (char*)malloc((count + 1) * sizeof(char));
    pos = 0;
    for (i = 0; i < strlen(Str); ++i)
    {
   	 flag = 0;
   	 for (j = 0; j < sz; ++j)
   	 {
   		 if (Str[i] == Ysl[j].From)
   		 {
   			 flag = 1;
   			 for (k = 0; k < strlen(Ysl[j].To); ++k)
   			 {
   				 Str2[pos] = Ysl[j].To[k];
   				 pos++;
   			 }
   		 }
   	 }
   	 if (!flag)
   	 {
   		 Str2[pos] = Str[i];
   		 pos++;
   	 }
    }
    Str2[pos] = '\0';
    //printf("Str2 = ");
    //puts(Str2);
    return Str2;
}
int main()
{
    char S[N], Srul[N], *S1, *S2, *Letters;
    Rule* Ysl;
    int letnum, i, j, amrule;
    printf("Enter amount of letters in your alfabet\n");
    scanf("%d", &letnum);
    Letters = (char*)malloc(letnum * sizeof(char));
    printf("Enter your letters:\n");
    for (i = 0; i < letnum; ++i)
    {
   	 printf("Letters[%d] = ", i);
   	 scanf(" %c", &(Letters[i]));
    }
    printf("Enter amount of your rules\n");
    scanf("%d", &amrule);
    Ysl = (Rule*)malloc(amrule * sizeof(Rule));
    printf("Enter your rules:\n");
    if(amrule != 0)
   	 scanf(" ");
    for (i = 0; i < amrule; ++i)
    {
   	 scanf("%c ", &Ysl[i].From);
   	 //printf("Ysl[%d].From = %c\n", i, Ysl[i].From);
   	 scanf(" ");
   	 gets(Srul);
   	 //puts(Srul);
   	 Ysl[i].To = (char*)malloc(strlen(Srul) * sizeof(char));
   	 strcpy(Ysl[i].To, Srul);
   	 //printf("Ysl[%d].To = ", i);
   	 //puts(Ysl[i].To);
    }
    printf("Input your string\n");
    scanf(" ");
    gets(S);
    //printf("strlen(S) = %d\n", strlen(S));
    //for (i = 0; i < amrule; ++i)
    //{
   	 //printf("Ysl[%d] = ", i);
   	 //printf("%c ", Ysl[i].From);
   	 //puts(Ysl[i].To);
   	 //printf("\n");
    //}
    S1 = (char*)malloc(strlen(redo(S, Ysl, amrule)) * sizeof(char));
    S1 = redo(S, Ysl, amrule);
    puts(S1);
    for (i = 0; i < 4; ++i)
    {
   	 //printf("i = %d", i);
   	 if (i % 2 == 0)
   	 {
   		 S2 = (char*)malloc(strlen(redo(S1, Ysl, amrule)) * sizeof(char));
   		 S2 = redo(S1, Ysl, amrule);
   		 puts(S2);
   	 }
   	 else
   	 {
   		 S1 = (char*)malloc(strlen(redo(S2, Ysl, amrule)) * sizeof(char));
   		 S1 = redo(S2, Ysl, amrule);
   		 puts(S1);
   	 }
    }
    return 0;
}



