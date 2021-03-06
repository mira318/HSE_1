
#include "stdafx.h"
#include <string.h>
#include <malloc.h>
#include<stdio.h>
char *readline()
{
	int bufferLength, position = 0;
	char *buffer;
	char b;
	bufferLength = 255;
	buffer = (char*)malloc(sizeof(char)* bufferLength);
	scanf("%c", &b);
	while (b != '\0' && b != '\n')
	{
		if (position >= bufferLength - 1)
		{
			bufferLength += 255;
			buffer = (char*)realloc(buffer, sizeof(char)* bufferLength);
		}
		buffer[position] = b;
		position++;
		scanf("%c", &b);
	}
	buffer[position] = '\0';
	position++;
	buffer = (char*)realloc(buffer, sizeof(char)*position);
	return buffer;
}

int divide(char* S, char*** Words)
{
	int n = 0, i, wordsz = 0;
	char* new_word = NULL;
	for (i = 0; i < strlen(S); i++)
	{
		if (S[i] == ' ' && wordsz > 0)
		{
			(*Words) = (char**)realloc((*Words), (n + 1) * sizeof(char*));
			(*Words)[n] = (char*)malloc((wordsz + 1) * sizeof(char));
			strcpy((*Words)[n], new_word);
			(*Words)[n][wordsz] = '\0';
			//printf("Words[%d] = ", n);
			//puts((*Words)[n]);
			n++;
			new_word = (char*)realloc(new_word, 0);
			wordsz = 0;
		}
		if (S[i] != ' ')
		{
			new_word = (char*)realloc(new_word, (wordsz + 1) * sizeof(char));
			new_word[wordsz] = S[i];
			wordsz++;
		}
	}
	if (wordsz > 0)
	{
		(*Words) = (char**)realloc((*Words), (n + 1) * sizeof(char*));
		(*Words)[n] = (char*)malloc((wordsz + 1) * sizeof(char));
		strcpy((*Words)[n], new_word);
		(*Words)[n][wordsz] = '\0';
		n++;
	}
	//printf("n = %d\n", n);
	return n;
}

void count(char** Words, int am)
{
	int i, j, tek_num = 0;
	long double max_share = 0;
	for (i = 0; i < am; ++i)
	{
		for (j = 0; j < strlen(Words[i]); ++j)
		{
			if (Words[i][j] == 'a' || Words[i][j] == 'b')
			{
				tek_num++;
			}
		}
		if (max_share < (long double)tek_num / strlen(Words[i]))
		{
			max_share = (long double)tek_num / strlen(Words[i]);
		}
		tek_num = 0;
	}
	for (i = 0; i < am; ++i)
	{
		for (j = 0; j < strlen(Words[i]); ++j)
		{
			if (Words[i][j] == 'a' || Words[i][j] == 'b')
			{
				tek_num++;
			}
		}
		if (max_share == (long double)tek_num / strlen(Words[i]))
		{
			puts(Words[i]);
		}
		tek_num = 0;
	}
}
int main()
{
	char* S;
	char** Words = NULL;
	int am, i;
	printf("Input your string\n");
	S = readline();
	am = divide(S, &Words);
	printf("words with max share of a and b:\n");
	count(Words, am);
    return 0;
}
