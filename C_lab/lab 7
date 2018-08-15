// лаба7.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <malloc.h>
#include <string>
#include <stdio.h>
#define DEBUG 0
#define N 10000
//Функция создаёт проверяет, что бинарного файла f нет на компьютере, безопасно создает его по заданию a и заполняет его вещественными числами.
int create1()
{
	int i, j;
	long double k;
	FILE* f;
	f = fopen("f.txt", "rb");
	if (f)
	{
		printf("File already exist. Use another DEBUG value");
		return 0;
	}
	f = fopen("f.txt", "wb");
	for (i = 1; i < 5; ++i)
	{
		for (j = 2; j < 7; ++j)
		{
			k = (long double)i / j;
			fwrite(&k, sizeof(long double), 1, f);
			//printf("k = %lf\n", k);
		}
	}
	k = 1.2345;
	fwrite(&k, sizeof(long double), 1, f);
	fclose(f);
	return 1;
}
//Функция проверяет, существует ли файл f на компьютере, если возможно, то находит в файле последний минимум и последний максимум и записывает максимум после последнего минимума, сдвигая все элементы, которые могут быть после последнего минимума
void tacka()
{
	long double    *A = NULL, min, max, tek;
	int size = 0;
	FILE* f, *f2;
	int place, j;
	min = N;
	max = -N;
	f = fopen("f.txt", "r+b");
	if (f == NULL)
	{
		printf("No such input file\n");
	}
	else
	{
		f2 = fopen("f.txt", "r+b");
		fseek(f2, 0, SEEK_END);
		while (ftell(f) < ftell(f2))
		{
			fread(&tek, sizeof(long double), 1, f);
			if (tek <= min)
			{
				min = tek;
				place = 0;
			}
			else
			{
				place++;
				A = (long double*)realloc(A, sizeof(long double)*place);
				size = place;
				A[size - 1] = tek;
			}
			if (tek >= max)
			{
				max = tek;
			}
		}
		if (tek == min)
		{
			size = 0;
		}
		fseek(f, -(place - 2) * sizeof(long double) - (place) * sizeof(char), SEEK_END);
		fwrite(&max, sizeof(long double), 1, f);
		if (size > 0)
		{
			for (j = 0; j < size - 1; ++j)
			{
				fwrite(&(A[j]), sizeof(long double), 1, f);
			}
		}
		fwrite(&(A[size - 1]), sizeof(long double), 1, f);
		fclose(f);
		fclose(f2);
		free(A);
	}
}
//Функция проверяет наличие файла f на компьютере и выводит его содержимое на экран.
void out1()
{
	long double cop;
	FILE* f = fopen("f.txt", "rb");
	if (f != NULL)
	{
		FILE* f2 = fopen("f.txt", "rb");
		fseek(f2, -1, SEEK_END);

		while (ftell(f) < ftell(f2))
		{
			fread(&cop, sizeof(long double), 1, f);
			printf("%lf ", cop);
		}
		fclose(f);
		fclose(f2);
	}
}
//Функция проверяет существование текстового файла f на компьютере, безопасно создает его и заполняет строками, которые начинаются и заканчиваются символом “ ” по заданию b.
int create2()
{
	FILE* f;
	int i, j;
	f = fopen("f.txt", "rt");
	if (f)
	{
		printf("File already exist. Use another DEBUG value");
		return 0;
	}
	else
	{
		f = fopen("f.txt", "wt");
		for (i = 0; i < 5; ++i)
		{
			fprintf(f, "%c", ' ');
		}
		for (i = 0; i < 21; ++i)
		{
			fprintf(f, "%c", 'a' + i);
		}
		for (i = 0; i < 5; ++i)
		{
			fprintf(f, "%c", ' ');
		}
		for (i = 0; i < 15; ++i)
		{
			fprintf(f, "%c", 'a' + i % 4);
		}
		for (i = 0; i < 2; ++i)
		{
			fprintf(f, "%c", ' ');
		}
		fprintf(f, "%c", '\n');



		for (i = 0; i < 1; ++i)
		{
			fprintf(f, "%c", ' ');
		}
		for (i = 0; i < 7; ++i)
		{
			fprintf(f, "%c", 'a' + i);
		}
		for (i = 0; i < 5; ++i)
		{
			fprintf(f, "%c", ' ');
		}
		for (i = 0; i < 32; ++i)
		{
			fprintf(f, "%c", 'a' + (i % 7));
		}
		for (i = 0; i < 4; ++i)
		{
			fprintf(f, "%c", ' ');
		}
		fprintf(f, "%c", '\n');




		for (i = 71; i < 90; ++i)
		{
			fprintf(f, "%c", ' ');
		}
		for (i = 111; i < 132; ++i)
		{
			fprintf(f, "%c", 'a' + (i % 5));
		}
		for (i = 0; i < 3; ++i)
		{
			fprintf(f, "%c", ' ');
		}
		for (i = 0; i < 32; ++i)
		{
			fprintf(f, "%c", 'a' + (i % 7));
		}
		fprintf(f, "%c", '\n');
		fclose(f);
		return 1;
	}
}
//Функция сортирует массив строк по их длине, начиная с наибольших.
void sort(char** Strings, int sz)
{
	char* S1;
	int flag = 1, i = 0, count = 0;
	while (flag)
	{
		flag = 0;
		for (i = 0; i < sz - 1 - count; ++i)
		{
			if (strlen(Strings[i]) < strlen(Strings[i + 1]))
			{
				S1 = Strings[i];
				Strings[i] = Strings[i + 1];
				Strings[i + 1] = S1;
				flag = 1;
			}
		}
		count++;
	}
}
//Функция проверяет наличие файла f и отсутствие файла g на компьютере. Если это возможно, выполняет задание b: считывает все строки из файла f, удаляет пробелы в начале и конце строк, вызывает функцию сортировки строк и записывает полученный массив отсортированных строк в файл g.
int tackb()
{
	FILE* f;
	FILE* g;
	FILE* f2;
	char c;
	char S[N];
	char** ALL_strings = NULL;
	int size = 0, i;
	f = fopen("f.txt", "rt");
	if (f == NULL)
	{
		printf("No such input file\n");
		return 0;
	}
	g = fopen("g.txt", "rt");
	if (g != NULL)
	{
		printf("File g.txt already exist. Please, delete or remove it\n");
		return 0;
	}
	g = fopen("g.txt", "wt");
	f2 = fopen("f.txt", "rt");
	fseek(f2, 0, SEEK_END);
	while (ftell(f) < ftell(f2))
	{
		fgets(S, N, f);
		size++;
		while (S[0] == ' ')
		{
			strcpy(S, S + 1);
		}
		while (S[strlen(S) - 1] == ' ' || S[strlen(S) - 1] == '\n')
		{
			S[strlen(S) - 1] = '\0';
		}
		ALL_strings = (char**)realloc(ALL_strings, size * sizeof(char*));
		ALL_strings[size - 1] = (char*)malloc(strlen(S) * sizeof(char));
		strcpy(ALL_strings[size - 1], S);
	}
	sort(ALL_strings, size);
	for (i = 0; i < size; ++i)
	{
		fputs(ALL_strings[i], g);
		fputc('\n', g);
	}
	fclose(f);
	fclose(f2);
	fclose(g);
	free(ALL_strings);
	return 1;
}
//Функция проверяет существование файла g и, если это возможно, выводит его содержимое на экран.
void out2()
{
	FILE* g;
	FILE* g2;
	char S[N];
	g = fopen("g.txt", "rt");
	g2 = fopen("g.txt", "rt");
	fseek(g2, 0, SEEK_END);
	while (ftell(g) < ftell(g2))
	{
		fgets(S, N, g);
		puts(S);
	}
	fclose(g);
	fclose(g2);
}
//Функция запрашивает вариант выполняемого задания у пользователя, создаёт или использует уже имеющийся файл для его выполнения в зависимости от значения константы DEBUG. Завершает выполнение задания, если произошли ошибки при создании/поиске файлов и выводит результат выполнения задания, если все файлы были найдены корректно.
int main()
{
	char var;
	char* infile;
	char* outfile;
	printf("Inter the varient of tack\n");
	scanf("%c", &var);
	if (var == 'a')
	{
#if DEBUG
		if (!create1())
		{
			return 0;
		}
#endif
		out1();
		tacka();
		printf("\nThe result is\n");
		out1();
	}
	else
	{
		if (var == 'b')
		{
#if DEBUG
			if (!create2())
			{
				return 0;
			}
#endif
			if (tackb())
			{
				printf("\nThe result is\n");
				out2();
			}
		}
		else
		{
			printf("Incorrect varient of tack");
		}
	}
	return 0;
}
