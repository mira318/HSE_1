#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

/*выбор задания*/

int bufsize;
int menu()
{
	int ret, a;
	printf("Выберите задание(1 или 2):");
	ret = scanf("%d", &a);
	if (ret != 1 || (a != 1 && a != 2))
	{
		printf("ERROR\n");
		exit(10);
	}
	return a;
}
/*1 ЗАДАЧА*/
void createFile()
{
	short k;
	FILE *f;
	f = fopen("f.txt", "rb");
	if (f)
	{
		printf("file already exist\n");
		exit(10);
	}
	f = fopen("f.txt", "wb");
	for (int i = 1; i<5; i++)
	{
		for (int j = 2; j<6; j++)
		{
			k = (short)i / j;
			fwrite(&k, sizeof(short), 1, f);
		}
	}
	fclose(f);
}
short* ReadBuf(short* OldBuf, FILE** f, FILE* f2, int index)
{
	short b;
	int i = 0;
	short* Buff = (short*)malloc(sizeof(short) * 12 * 10000000);
	for (i = 0; i + index < 12 * 10000000; i++)
	{
		Buff[i] = OldBuf[i + index];
	}
	while (ftell(*f) < ftell(f2) && i < 12 * 10000000)
	{
		fread(&b, sizeof(short), 1, *(f));
		Buff[i] = b;
		i++;
	}
	bufsize = i;
	free(OldBuf);
	return Buff;
}
void out1()
{
	FILE* f, *f2;
	short cur;
	f = fopen("f.txt", "rb");
	if (!f)
	{
		printf("No this file\n");
		exit(23);
	}
	else
	{
		f2 = fopen("f.txt", "rb");
		fseek(f2, 0, SEEK_END);
		while (ftell(f) < ftell(f2))
		{
			fread(&cur, sizeof(short), 1, f);
			printf("%d ", cur);
		}
		printf("\n");
	}
	fclose(f);
	fclose(f2);
}
/*найти наибольшее значение в каждой группе и вставить его после этой группы*/
void task1()
{
	FILE *f, *f2, *f3;
	int index = 0, col = 0, bufind = 0, maxind, i;
	short cur, maxcur;
	short* MAX = NULL;
	short* Buffer = NULL;
	bufsize = 0;
	f = fopen("f.txt", "r+b");
	if (!f)
	{
		exit(1);
	}
	f2 = fopen("f.txt", "rb");
	fseek(f2, 0, SEEK_END);
	f3 = fopen("f.txt", "r+b");
	while (ftell(f) < ftell(f2))
	{
		fread(&cur, sizeof(short), 1, f);
		if (index == 0)
		{
			maxcur = cur;
		}
		else
		{
			if (cur >= maxcur)
			{
				maxcur = cur;
			}
		}
		index++;
		if (index == 10)
		{
			col++;
			MAX = (short*)realloc(MAX, col * sizeof(short));
			MAX[col - 1] = maxcur;
			index = 0;
		}
	}
	if (index)
	{
		col++;
		MAX = (short*)realloc(MAX, col * sizeof(short));
		MAX[col - 1] = maxcur;
		index = 0;
	}
	index = 0;
	maxind = 0;
	fseek(f, 0, SEEK_SET);
	Buffer = ReadBuf(Buffer, &f, f2, 12 * 10000000);
	while (ftell(f3) < ftell(f2))
	{
		while (ftell(f3) <= ftell(f))
		{
			if (index != 10)
			{
				fwrite(&Buffer[bufind], sizeof(short), 1, f3);
				bufind++;
				index++;
			}
			else
			{
				fwrite(&MAX[maxind], sizeof(short), 1, f3);
				maxind++;
				index = 0;
			}
		}
		if (ftell(f) < ftell(f2))
		{
			Buffer = ReadBuf(Buffer, &f, f2, bufind);
			bufind = 0;
		}
	}
	while (bufind < bufsize)
	{
		if (index != 10)
		{
			fwrite(&Buffer[bufind], sizeof(short), 1, f3);
			bufind++;
			index++;
		}
		else
		{
			fwrite(&MAX[maxind], sizeof(short), 1, f3);
			maxind++;
			index = 0;
		}
	}
	if (index)
	{
		fwrite(&MAX[maxind], sizeof(short), 1, f3);
	}
	free(MAX);
	free(Buffer);
	fclose(f);
	fclose(f2);
	fclose(f3);
}

/*ввод для второй задачи*/
/*считаю строку*/
char *readline(FILE **myfile)
{
	int bufferLength, position = 0;
	bufferLength = 255;
	char *buffer;
	char b;
	buffer = (char*)malloc(sizeof(char)* bufferLength);
	while ((b = getc(*(myfile))) != '\n' && b != EOF)
	{
		if (position >= bufferLength - 1)
		{
			bufferLength += 255;
			buffer = (char*)realloc(buffer, sizeof(char)* bufferLength);
		}
		buffer[position] = b;
		position++;
	}
	buffer[position] = '\0';
	buffer = (char*)realloc(buffer, sizeof(char)* (position + 1));
	return buffer;
}
void input2()
{
	char* s;
	int i, n;
	FILE *myfile, *input;
	input = stdin;
	myfile = fopen("f.txt", "rt");
	if (myfile != NULL)
	{
		printf("File f.txt already exist\n");
		exit(100);
	}
	myfile = fopen("f.txt", "wt");
	printf("Enter number of strings\n");
	scanf(" ");
	scanf("%d", &n);
	printf("Enter words and use between them symbol " ". To stop the current string and start a new one press Enter\n");
	for (i = 0; i < n; i++)
	{
		scanf(" ");
		s = readline(&input);
		fputs(s, myfile);
		fputs("\n", myfile);
	}
	fclose(myfile);
}

void printfile2()
{
	char ch;
	FILE* g, *g2;
	g = fopen("out.txt", "rt");
	if (g == NULL)
	{
		printf("ERROR\n");
		exit(100);
	}
	printf("Содержимое файла g\n");
	g2 = fopen("out.txt", "rt");
	fseek(g2, 0, SEEK_END);
	while (ftell(g) < ftell(g2))
	{
		ch = fgetc(g);
		printf("%c", ch);
	}
	fclose(g);
	fclose(g2);
}
void createFile2()
{
	int i, j;
	FILE* f;
	f = fopen("f.txt", "rt");
	if (f)
	{
		printf("File already exist\n");
		exit(7);
	}
	f = fopen("f.txt", "wt");
	char* S1, *S2, *S3, *S4, *S5;
	S1 = (char*)malloc(500 * sizeof(char));

	S2 = (char*)malloc(500 * sizeof(char));

	S3 = (char*)malloc(500 * sizeof(char));

	S4 = (char*)malloc(500 * sizeof(char));

	S5 = (char*)malloc(500 * sizeof(char));
	for (i = 0; i < 7; ++i)
	{
		S1[i] = ' ';
	}
	for (; i < 25; ++i)
	{
		S1[i] = '0' + i;
	}
	for (; i < 3; ++i)
	{
		S1[i] = ' ';
	}
	for (; i < 12; ++i)
	{
		S1[i] = 'b' + i;
	}
	for (; i < 1; ++i)
	{
		S1[i] = ' ';
	}
	S1 = (char*)realloc(S1, i * sizeof(char));
	fputs(S1, f);
	for (i = 0; i < 27; ++i)
	{
		S2[i] = '9' + i;
	}
	for (; i < 8; ++i)
	{
		S2[i] = ' ';
	}
	for (; i < 4; ++i)
	{
		S2[i] = '4' + i;
	}
	for (; i < 5; ++i)
	{
		S2[i] = ' ';
	}
	for (; i < 25; ++i)
	{
		S2[i] = 'K' + i;
	}
	S2 = (char*)realloc(S2, i * sizeof(char));
	fputs(S2, f);
	for (i = 0; i < 3; ++i)
	{
		S3[i] = ' ';
	}
	for (; i < 25; ++i)
	{
		S3[i] = '7' + i;
	}
	S3 = (char*)realloc(S3, i * sizeof(char));
	fputs(S3, f);
	for (i = 0; i < 5; ++i)
	{
		S4[i] = 'p' + i;
	}
	for (; i < 7; ++i)
	{
		S4[i] = ' ';
	}
	S4 = (char*)realloc(S4, i * sizeof(char));
	fputs(S4, f);
	for (i = 0; i < 25; ++i)
	{
		S5[i] = '3' + i;
	}
	for (; i < 7; ++i)
	{
		S5[i] = ' ';
	}
	for (; i < 6; ++i)
	{
		S5[i] = 'M' + i;
	}
	for (; i < 17; ++i)
	{
		S5[i] = ' ';
	}
	for (; i < 25; ++i)
	{
		S5[i] = 'o' + i;
	}
	for (; i < 3; ++i)
	{
		S5[i] = ' ';
	}
	for (; i < 14; ++i)
	{
		S5[i] = '9' + i;
	}
	for (; i < 7; ++i)
	{
		S5[i] = ' ';
	}
	for (; i < 15; ++i)
	{
		S5[i] = 'w' + i;
	}
	for (; i < 9; ++i)
	{
		S5[i] = ' ';
	}
	S5 = (char*)realloc(S5, i * sizeof(char));
	fputs(S5, f);
	fclose(f);
}
void task2()
{
	int am = 0, max_am = -1, i, lastp, j, came = 0;
	char a;
	char* S;
	FILE* myfile, *myfile2, *g;
	myfile = fopen("f.txt", "rt");
	if (!myfile)
	{
		printf("No file f.txt\n");
		exit(666);
	}
	myfile2 = fopen("f.txt", "rt");
	g = fopen("out.txt", "rt");
	if (g)
	{
		printf("Output file out.txt already exist\n");
		exit(3);
	}
	g = fopen("out.txt", "wt");
	fseek(myfile2, 0, SEEK_END);
	while (ftell(myfile) < ftell(myfile2))
	{
		S = readline(&myfile);
		for (i = 0; i < strlen(S); ++i)
		{
			if (S[i] == ' ')
			{
				if (max_am < am)
				{
					max_am = am;
				}
				am = 0;
			}
			if (S[i] >= '0' && S[i] <= '9')
			{
				am++;
			}
		}
		if (max_am < am)
		{
			max_am = am;
		}
		am = 0;
	}
	fseek(myfile, 0, SEEK_SET);
	while (ftell(myfile) < ftell(myfile2))
	{
		am = 0;
		S = readline(&myfile);
		lastp = -1;
		for (i = 0; i < strlen(S); ++i)
		{
			if (S[i] >= '0' && S[i] <= '9')
			{
				am++;
			}
			if (S[i] == ' ')
			{
				if (am == max_am)
				{
					for (j = lastp + 1; j < i; ++j)
					{
						came = 1;
						fputc(S[j], g);
					}
					if (came)
					{
						came = 0;
						fprintf(g, "\n");
					}
				}
				lastp = i;
				am = 0;
			}
		}
		if (am == max_am)
		{
			for (j = lastp + 1; j < strlen(S); ++j)
			{
				came = 1;
				fputc(S[j], g);
			}
			if (came)
			{
				came = 0;
				fprintf(g, "\n");
			}
		}
	}
	fclose(myfile);
	fclose(myfile2);
	fclose(g);
}
int main()
{
	int a;
	char c;
	setlocale(LC_ALL, "rus");
	a = menu();
	if (a == 1)
	{
		printf("Dear user, do you want to enter your or my file? Write Y or M\n");
		scanf(" ");
		scanf("%c", &c);
		if (c == 'M')
		{
			createFile();
			out1();
			task1();
			out1();
		}
		else
		{
			if (c == 'Y')
			{
				out1();
				task1();
				out1();
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		printf("Dear user, do you want to enter your file or my file or create new file? Write Y or M or C\n");
		scanf(" ");
		scanf("%c", &c);
		if (c == 'M')
		{
			createFile2();
			task2();
			printfile2();
		}
		else
		{
			if (c == 'Y')
			{
				task2();
				printfile2();
			}
			else
			{
				if (c == 'C')
				{
					input2();
					task2();
					printfile2();
				}
				else
					return 0;
			}
		}
	}
	return 0;
}
