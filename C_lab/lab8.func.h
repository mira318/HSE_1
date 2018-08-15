#include "stdafx.h"
#ifndef THE_STRUCT
#include "struct.h"
#endif
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <io.h>
long long* Tells;
int sz;
//Функция считывает строку любой длины из заданного файлового потока f
char *readline(FILE **f)
{
	int bufferLength, position = 0;
	char *buffer;
	char b;
	bufferLength = 255;
	buffer = (char*)malloc(sizeof(char)* bufferLength);
	b = fgetc(*(f));
	while (b != '\0' && *(f) != feof && b != '\n')
	{
		if (position >= bufferLength - 1)
		{
			bufferLength += 255;
			buffer = (char*)realloc(buffer, sizeof(char)* bufferLength);
		}
		buffer[position] = b;
		position++;
		b = fgetc(*(f));
	}
	buffer[position] = '\0';
	position++;
	buffer = (char*)realloc(buffer, sizeof(char)*position);
	return buffer;
}
//Функция выводит заданную строку S в файловый поток f 
void writeline(char* S, FILE* f)
{
	int i = 0;
	char a = '\0';
	while (S[i] != a)
	{
		fputc(S[i], f);
		i++;
	}
	fputc(a, f);
}
//Функция выводит данные об одном заданном студенте С на экран
void print_one(struct Student C)
{
	int j;
	printf("ID: %lld\t", C.How.IDE);
	writeline(C.FIO.name, stdout);
	writeline(C.FIO.surename, stdout);
	writeline(C.FIO.secondname, stdout);
	writeline(C.How.Faculty, stdout);
	writeline(C.How.Group, stdout);
	for (j = 0; j < 7; ++j)
	{
		printf("%d ", C.Marks.Res[j]);
	}
	printf("\n");
}
//Функция проверяет, существует ли база, есть ли в базе неудалённые студенты и 
//выводит содержимое всей базы данных на экран в виде таблицы в порядке, указанном в массиве Tells,
//если это возможно, иначе оповещает пользователя о невозможности вывода.
void Print_base_table()
{
	FILE* f;
	struct Student A, B;
	int i, flag = 0, res, j;
	f = fopen("base.txt", "rb");
	if (!f)
	{
		printf("There is no base. Create something new\n");
	}
	else
	{
		B.FIO.name = "";
		B.FIO.surename = "";
		B.FIO.secondname = "";
		B.How.Faculty = "";
		B.How.Group = "";
		for (i = 0; i < 7; ++i)
		{
			B.Marks.Res[i] = -1;
		}
		if (sz == 0)
		{
			printf("All students was deleted. Create a new base\n");
		}
		else
		{
			for (j = 0; j < sz; ++j)
			{
				fseek(f, Tells[j], SEEK_SET);
				fread(&A.How.IDE, sizeof(long long), 1, f);
				A.FIO.name = readline(&f);
				A.FIO.surename = readline(&f);
				A.FIO.secondname = readline(&f);
				A.How.Faculty = readline(&f);
				A.How.Group = readline(&f);
				for (i = 0; i < 7; ++i)
				{
					fread(&A.Marks.Res[i], sizeof(int), 1, f);
				}
				if (strlen(A.FIO.name) > strlen(B.FIO.name))
				{
					B.FIO.name = A.FIO.name;
				}
				if (strlen(A.FIO.surename) > strlen(B.FIO.surename))
				{
					B.FIO.surename = A.FIO.surename;
				}
				if (strlen(A.FIO.secondname) > strlen(B.FIO.secondname))
				{
					B.FIO.secondname = A.FIO.secondname;
				}
				if (strlen(A.How.Faculty) > strlen(B.How.Faculty))
				{
					B.How.Faculty = A.How.Faculty;
				}
				if (strlen(A.How.Group) > strlen(B.How.Group))
				{
					B.How.Group = A.How.Group;
				}
			}
			if (strlen(B.FIO.name) < 4)
			{
				B.FIO.name = "Name";
			}
			if (strlen(B.FIO.surename) < 8)
			{
				B.FIO.surename = "surename";
			}
			if (strlen(B.FIO.secondname) < 10)
			{
				B.FIO.secondname = "secondname";
			}
			if (strlen(B.How.Faculty) < 7)
			{
				B.How.Faculty = "Faculty";
			}
			if (strlen(B.How.Group) < 5)
			{
				B.How.Group = "Group";
			}
			printf("ID ");
			for (i = 0; i < 6; i++)
			{
				printf(" ");
			}
			printf("Name ");
			res = strlen(B.FIO.name) - strlen("Name");
			for (i = 0; i < res; ++i)
			{
				printf(" ");
			}
			printf("Surename ");
			res = strlen(B.FIO.surename) - strlen("Surename");
			for (i = 0; i < res; ++i)
			{
				printf(" ");
			}
			printf("Secondname ");
			res = strlen(B.FIO.secondname) - strlen("Secondname");
			for (i = 0; i < res; ++i)
			{
				printf(" ");
			}
			printf("Faculty ");
			res = strlen(B.How.Faculty) - strlen("Faculty");
			for (i = 0; i < res; ++i)
			{
				printf(" ");
			}
			printf("Group ");
			res = strlen(B.How.Group) - strlen("Group");
			for (i = 0; i < res; ++i)
			{
				printf(" ");
			}
			for (i = 0; i < 7; ++i)
			{
				printf("Subject%d ", i + 1);
			}
			printf("\n");
			for (j = 0; j < sz; ++j)
			{
				fseek(f, Tells[j], SEEK_SET);
				fread(&A.How.IDE, sizeof(long long), 1, f);
				A.FIO.name = readline(&f);
				A.FIO.surename = readline(&f);
				A.FIO.secondname = readline(&f);
				A.How.Faculty = readline(&f);
				A.How.Group = readline(&f);
				for (i = 0; i < 7; ++i)
				{
					fread(&A.Marks.Res[i], sizeof(int), 1, f);
				}
				printf("%8lld", A.How.IDE);
				printf(" ");
				writeline(A.FIO.name, stdout);
				for (i = 0; i < strlen(B.FIO.name) - strlen(A.FIO.name); ++i)
				{
					printf(" ");
				}
				writeline(A.FIO.surename, stdout);
				for (i = 0; i < strlen(B.FIO.surename) - strlen(A.FIO.surename); ++i)
				{
					printf(" ");
				}
				writeline(A.FIO.secondname, stdout);
				for (i = 0; i < strlen(B.FIO.secondname) - strlen(A.FIO.secondname); ++i)
				{
					printf(" ");
				}
				writeline(A.How.Faculty, stdout);
				for (i = 0; i < strlen(B.How.Faculty) - strlen(A.How.Faculty); ++i)
				{
					printf(" ");
				}
				writeline(A.How.Group, stdout);
				for (i = 0; i < strlen(B.How.Group) - strlen(A.How.Group); ++i)
				{
					printf(" ");
				}
				for (i = 0; i < 7; ++i)
				{
					printf("%8d ", A.Marks.Res[i]);
				}
				printf("\n");
			}
		}
	}
	fclose(f);
}
//Функция осуществляет подготовку программы к работе. Если файл с базой уже существует, 
//то функция запоминает число студентов в базе и смещения этих студентов в файле в массив Tells.
void Prep()
{
	FILE* f, *f2;
	struct Student A;
	int i, size = 0;
	f = fopen("base.txt", "rb");
	if (f)
	{
		f2 = fopen("base.txt", "rb");;
		fseek(f2, 0, SEEK_END);
		while (ftell(f) < ftell(f2))
		{
			fread(&A.How.IDE, sizeof(long long), 1, f);
			if (A.How.IDE > 0)
			{
				fseek(f, -sizeof(long long), SEEK_CUR);
				Tells = realloc(Tells, (size + 1) * sizeof(long long));
				Tells[size] = ftell(f);
				size++;
				fseek(f, sizeof(long long), SEEK_CUR);
			}
			A.FIO.name = readline(&f);
			A.FIO.surename = readline(&f);
			A.FIO.secondname = readline(&f);
			A.How.Faculty = readline(&f);
			A.How.Group = readline(&f);
			for (i = 0; i < 7; ++i)
			{
				fread(&A.Marks.Res[i], sizeof(int), 1, f);
			}
		}
		fclose(f);
		fclose(f2);
		sz = size;
	}
}
//Функция позволяет пользователю самостоятельно заполнить создаваемую базу.
void Fill()
{
	FILE* f, *f2;
	int i, j, size;
	f = fopen("base.txt", "wb");
	f2 = stdin;
	printf("Enter amount of students\n");
	scanf("%d", &size);
	Tells = (long long*)malloc(size * sizeof(long long));
	sz = size;
	for (i = 0; i < size; ++i)
	{
		struct Student A;
		Tells[i] = ftell(f);
		A.How.IDE = i + 1;
		fwrite(&A.How.IDE, sizeof(long long), 1, f);
		printf("The student number %d:\n", i + 1);
		printf("Name:");
		scanf(" ");
		A.FIO.name = readline(&f2);
		writeline(A.FIO.name, f);
		printf("Surename:");
		scanf(" ");
		A.FIO.surename = readline(&f2);
		writeline(A.FIO.surename, f); 
		printf("Secondname:");
		scanf(" ");
		A.FIO.secondname = readline(&f2);

		writeline(A.FIO.secondname, f);
		printf("Faculty:");
		scanf(" ");
		A.How.Faculty = readline(&f2);
		writeline(A.How.Faculty, f);
		printf("Group:");
		scanf(" ");
		A.How.Group = readline(&f2);
		writeline(A.How.Group, f);
		for (j = 0; j < 7; ++j)
		{
			printf("Subject %d, Mark:", j + 1);
			scanf("%d", &A.Marks.Res[j]);
			fwrite(&A.Marks.Res[j], sizeof(int), 1, f);
		}
	}
	fclose(f);
}
//Функция осуществляет подготовку к заполнению базы пользователем: 
//проверяет, существует ли база, предостерегает пользователя от удаления всех существующих элементов, если база уже есть, 
//и запускает функцию заполнения базы, если её ещё нет или пользователь согласен на удаление.
void Fill_Check()
{
	char ans;
	if (sz != 0)
	{
		printf("The base is already exist. Are you want to delete everything? Y/N\n");
		scanf(" ");
		scanf("%c", &ans);
		if (ans == 'Y')
		{
			Fill();
		}
		else
		{
			if (ans == 'N')
			{
				printf("You can add new students into the base or alter data about students, which already exist\n");
			}
			else
			{
				printf("Incorrect ans, try again\n");
			}
		}
	}
	else
	{
		Fill();
	}
}
//Функция добавляет новый элемент в базу: 
//считывает данные у пользователя, записывает их в конец файла с базой,
//обновляет размер базы и запоминает новое смещение элемента в массив Tells.
void Add()
{
	FILE* f, *f2;
	int j;
	struct Student A;
	Tells = (long long*)realloc(Tells, (sz + 1)*sizeof(long long));
	f = fopen("base.txt", "ab");
	fseek(f, 0, SEEK_END);
	f2 = stdin;
	Tells[sz] = ftell(f);
	sz++;
	A.How.IDE = ftell(f);
	fwrite(&A.How.IDE, sizeof(long long), 1, f);
	printf("Name:");
	scanf(" ");
	A.FIO.name = readline(&f2);
	writeline(A.FIO.name, f);
	printf("Surename:");
	scanf(" ");
	A.FIO.surename = readline(&f2);
	writeline(A.FIO.surename, f);
	printf("Secondname:");
	scanf(" ");
	A.FIO.secondname = readline(&f2);
	writeline(A.FIO.secondname, f);
	printf("Fuculty:");
	scanf(" ");
	A.How.Faculty = readline(&f2);
	writeline(A.How.Faculty, f);
	printf("Group:");
	scanf(" ");
	A.How.Group = readline(&f2);
	writeline(A.How.Group, f);
	for (j = 0; j < 7; ++j)
	{
		printf("Subject %d, Mark:", j + 1);
		scanf("%d", &A.Marks.Res[j]);
		fwrite(&A.Marks.Res[j], sizeof(int), 1, f);
	}
	fclose(f);
}
//Функция осуществляет поиск элемента в базе. Проверяет, что файл с базой уже существует,
//узнаёт у пользователя все известные ему данные об искомом студенте и выводит список подходящих студентов на экран,
//просит пользователя выбрать одного из студентов, если функция была вызвана при добавлении или удалении элемента.
long long search(int flag2)
{
	FILE* f, *f3;
	int j, i;
	char c;
	long long elseret = -1;
	f = fopen("base.txt", "rb");
	if (f)
	{
		struct Student B;
		struct Student C;
		int flag = 0, sim, k;
		long long alter_IDE;
		f3 = stdin;
		printf("Write everything you know about the student.\n");
		printf("If you don't know ID, write -5\n");
		printf("ID:");
		scanf("%lld", &B.How.IDE);
		printf("If you don't know something simply enter *\n");
		printf("Name:");
		scanf(" ");
		B.FIO.name = readline(&f3);
		printf("Surename:");
		scanf(" ");
		B.FIO.surename = readline(&f3);
		printf("Secondname:");
		scanf(" ");
		B.FIO.secondname = readline(&f3);
		printf("Faculty:");
		scanf(" ");
		B.How.Faculty = readline(&f3);
		printf("Group:");
		scanf(" ");
		B.How.Group = readline(&f3);
		printf("If you don't know the mark, write -1\n");
		for (j = 0; j < 7; ++j)
		{
			printf("Subject %d, Mark:", j + 1);
			scanf("%d", &B.Marks.Res[j]);
		}
		for(i = 0; i < sz; ++i)
		{
			fseek(f, Tells[i], SEEK_SET);
			sim = 0;	
			fread(&C.How.IDE, sizeof(long long), 1, f);
			C.FIO.name = readline(&f);
			C.FIO.surename = readline(&f);
			C.FIO.secondname = readline(&f);
			C.How.Faculty = readline(&f);
			C.How.Group = readline(&f);
			for (j = 0; j < 7; ++j)
			{
				fread(&C.Marks.Res[j], sizeof(int), 1, f);
			}
			if ((C.How.IDE == B.How.IDE || B.How.IDE == -5) && C.How.IDE != -1)
				sim++;

			if (strcmp(C.FIO.name, B.FIO.name) == 0|| strcmp(B.FIO.name, "*\0") == 0)
				sim++;

			if (strcmp(C.FIO.surename, B.FIO.surename) == 0 || strcmp(B.FIO.surename, "*\0") == 0)
				sim++;

			if (strcmp(C.FIO.secondname, B.FIO.secondname) == 0 || strcmp(B.FIO.secondname, "*\0") == 0)
				sim++;

			if (strcmp(C.How.Faculty, B.How.Faculty) == 0 || strcmp(B.How.Faculty, "*\0") == 0)
				sim++;

			if (strcmp(C.How.Group, B.How.Group) == 0 || strcmp(B.How.Group, "*\0") == 0)
				sim++;
			for (k = 0; k < 7; ++k)
			{
				if (C.Marks.Res[k] == B.Marks.Res[k] || B.Marks.Res[k] == -1)
					sim++;
			}
			if (sim == 13)
			{
				if (!flag && !flag2)
				{
					printf("The results are:\n");
				}
				print_one(C);
				flag = 1;
			}
		}
		fclose(f);
		if (flag)
		{
			if (flag2)
			{
				printf("Choose one of this students and enter their ID\n");
				scanf("%lld", &alter_IDE);
				return alter_IDE;
			}
			else
			{
				return elseret;
			}
		}
		else
		{
			printf("No students with this data. Try again\n");
			return elseret;
		}
	}
	else
	{
		printf("File isn't exist. Create something new.\n");
		return elseret;
	}
}
//Функция даёт возможность изменить данные о студенте с заданным ID. 
//Проверяет, что студент с заданным ID существует, считывает новые данные из потока ввода и записывает их в файл с базой 
void Alter(long long Alter_ID)
{
	FILE* f, *f2, *f3;
	struct Student D, F;
	int i, j;
	long long ID2 = -1;
	f = fopen("base.txt", "r+b");
	f2 = fopen("base.txt", "r+b");
	f3 = stdin;
	D.How.IDE = ID2;
	fseek(f2, 0, SEEK_END);
	for(j = 0; j < sz, D.How.IDE != Alter_ID; ++j)
	{
		fseek(f, Tells[j], SEEK_SET);
		fread(&D.How.IDE, sizeof(long long), 1, f);
		D.FIO.name = readline(&f);
		D.FIO.surename = readline(&f);
		D.FIO.secondname = readline(&f);
		D.How.Faculty = readline(&f);
		D.How.Group = readline(&f);
		for (i = 0; i < 7; ++i)
		{
			fread(&D.Marks.Res[i], sizeof(int), 1, f);
		}
	}
	j--;
	if (D.How.IDE != Alter_ID)
	{
		printf("Incorrect student's ID. Try again\n");
	}
	else
	{
		printf("You can't alter the ID. If you want something stay the same enter *, else enter new data\n");
		printf("Name:");
		scanf(" ");
		F.FIO.name = readline(&f3);
		printf("Surename:");
		scanf(" ");
		F.FIO.surename = readline(&f3);
		printf("Secondname:");
		scanf(" ");
		F.FIO.secondname = readline(&f3);
		printf("Faculty:");
		scanf(" ");
		F.How.Faculty = readline(&f3);
		printf("Group:");
		scanf(" ");
		F.How.Group = readline(&f3);
		printf("If you want the mark stay the same write -1, else write the new mark\n");
		for (i = 0; i < 7; ++i)
		{
			printf("Subject %d, Mark:", i + 1);
			scanf("%d", &F.Marks.Res[i]);
		}
		fseek(f, -((strlen(D.FIO.name) + strlen(D.FIO.surename) + strlen(D.FIO.secondname) + strlen(D.How.Faculty) + strlen(D.How.Group) + 5) * sizeof(char) + sizeof(long long) + 7 * sizeof(int)), SEEK_CUR);
		fwrite(&ID2, sizeof(long long), 1, f);
		Tells[j] = ftell(f2);
		fwrite(&D.How.IDE, sizeof(long long), 1, f2);
		if (strcmp(F.FIO.name, "*\0") == 0)
		{
			writeline(D.FIO.name, f2);
		}
		else
		{
			writeline(F.FIO.name, f2);
		}
		if (strcmp(F.FIO.surename, "*\0") == 0)
		{
			writeline(D.FIO.surename, f2);
		}
		else
		{
			writeline(F.FIO.surename, f2);
		}
		if (strcmp(F.FIO.secondname, "*\0") == 0)
		{
			writeline(D.FIO.secondname, f2);
		}
		else
		{
			writeline(F.FIO.secondname, f2);
		}
		if (strcmp(F.How.Faculty, "*\0") == 0)
		{
			writeline(D.How.Faculty, f2);
		}
		else
		{
			writeline(F.How.Faculty, f2);
		}
		if (strcmp(F.How.Group, "*\0") == 0)
		{
			writeline(D.How.Group, f2);
		}
		else
		{
			writeline(F.How.Group, f2);
		}
		for (i = 0; i < 7; ++i)
		{
			if (F.Marks.Res[i] == -1)
			{
				fwrite(&D.Marks.Res[i], sizeof(int), 1, f2);
			}
			else
			{
				fwrite(&F.Marks.Res[i], sizeof(int), 1, f2);
			}
		}
	}
	fclose(f);
	fclose(f2);
}
//Функция даёт возможность удалить студента с заданным ID из базы. 
//Проверяет, что студент с заданным ID существует в базе, если да, то удаляет его и удаляет его смещение из массива смещений Tells,
//иначе оповещает пользователя о вводе некорректного ID. 
void Delete(long long Alter_ID)
{
	FILE* f;
	struct Student D;
	int i, j;
	long long ID2 = -1;
	f = fopen("base.txt", "r+b");
	D.How.IDE = ID2;
	for(j = 0; j < sz, D.How.IDE != Alter_ID; ++j)
	{
		fseek(f, Tells[j], SEEK_SET);
		fread(&D.How.IDE, sizeof(long long), 1, f);
		D.FIO.name = readline(&f);
		D.FIO.surename = readline(&f);
		D.FIO.secondname = readline(&f);
		D.How.Faculty = readline(&f);
		D.How.Group = readline(&f);
		for (i = 0; i < 7; ++i)
		{
			fread(&D.Marks.Res[i], sizeof(int), 1, f);
		}
	}
	if (D.How.IDE != Alter_ID)
	{
		printf("No students with this ID\n");
	}
	else
	{
		j--;
		fseek(f, -((strlen(D.FIO.name) + strlen(D.FIO.surename) + strlen(D.FIO.secondname) + strlen(D.How.Faculty) + strlen(D.How.Group) + 5) * sizeof(char) + sizeof(long long) + 7 * sizeof(int)), SEEK_CUR);
		fwrite(&ID2, sizeof(long long), 1, f);
		for (i = j + 1; i < sz; ++i)
		{
			Tells[i - 1] = Tells[i];
		}
		Tells = (long long*)realloc(Tells, (sz - 1) * sizeof(long long));
		sz--;
	}
	fclose(f);
}
//Функция сравнения двух студентов. Находит студентов в файле, сравнивает их по заданному полю и направлению
//и возвращает результат сравнения типа int
int comp(int a, int b, int fild, int dist)
{
	FILE* f, *f2;
	struct Student A, B;
	int i;
	f = fopen("base.txt", "rb");
	f2 = fopen("base.txt", "rb");
	fseek(f, Tells[a], SEEK_SET);
	fseek(f2, Tells[b], SEEK_SET);
	fread(&A.How.IDE, sizeof(long long), 1, f);
	A.FIO.name = readline(&f);
	A.FIO.surename = readline(&f);
	A.FIO.secondname = readline(&f);
	A.How.Faculty = readline(&f);
	A.How.Group = readline(&f);
	for (i = 0; i < 7; ++i)
	{
		fread(&A.Marks.Res[i], sizeof(int), 1, f);
	}
	fread(&B.How.IDE, sizeof(long long), 1, f2);
	B.FIO.name = readline(&f2);
	B.FIO.surename = readline(&f2);
	B.FIO.secondname = readline(&f2);
	B.How.Faculty = readline(&f2);
	B.How.Group = readline(&f2);
	for (i = 0; i < 7; ++i)
	{
		fread(&B.Marks.Res[i], sizeof(int), 1, f2);
	}
	switch (fild)
	{
		case 1:
		{
			if (dist == 0)
			{
				return A.How.IDE - B.How.IDE;
			}
			else
			{
				return -(A.How.IDE - B.How.IDE);
			}
		}
		case 2:
		{
			if (dist == 0)
			{
				return strcmp(A.FIO.name, B.FIO.name);
			}
			else
			{
				return -strcmp(A.FIO.name, B.FIO.name);
			}
		}
		case 3:
		{
			if (dist == 0)
			{
				return strcmp(A.FIO.surename, B.FIO.surename);
			}
			else
			{
				return -strcmp(A.FIO.surename, B.FIO.surename);
			}
		}
		case 4:
		{
			if (dist == 0)
			{
				return strcmp(A.FIO.secondname, B.FIO.secondname);
			}
			else
			{
				return -strcmp(A.FIO.secondname, B.FIO.secondname);
			}
		}
		case 5:
		{
			if (dist == 0)
			{
				return strcmp(A.How.Faculty, B.How.Faculty);
			}
			else
			{

				return -strcmp(A.How.Faculty, B.How.Faculty);
			}
		}
		case 6:
		{
			if (dist == 0)
			{	
				return strcmp(A.How.Group, B.How.Group);
			}
			else
			{

				return -strcmp(A.How.Group, B.How.Group);
			}
		}
		case 7:
		{
			if (dist == 0)
			{
				return A.Marks.Res[0] - B.Marks.Res[0];
			}
			else
			{
				return -(A.Marks.Res[0] - B.Marks.Res[0]);
			}
		}
		case 8:
		{
			if (dist == 0)
			{
				return A.Marks.Res[1] - B.Marks.Res[1];
			}
			else
			{

				return -(A.Marks.Res[1] - B.Marks.Res[1]);
			}
		}
		case 9:
		{
			if (dist == 0)
			{
				return A.Marks.Res[2] - B.Marks.Res[2];
			}
			else
			{
				return -(A.Marks.Res[2] - B.Marks.Res[2]);
			}
		}
		case 10:
		{
			if (dist == 0)
			{
				return A.Marks.Res[3] - B.Marks.Res[3];
			}
			else
			{

				return -(A.Marks.Res[3] - B.Marks.Res[3]);
			}
		}
		case 11:
		{
			if (dist == 0)
			{
				return A.Marks.Res[4] - B.Marks.Res[4];
			}
			else
			{
				return -(A.Marks.Res[4] - B.Marks.Res[4]);
			}
		}
		case 12:
		{
			if (dist == 0)
			{
				return A.Marks.Res[5] - B.Marks.Res[5];
			}
			else
			{
				return -(A.Marks.Res[5] - B.Marks.Res[5]);
			}
		}
		case 13:
		{
			if (dist == 0)
			{
				return A.Marks.Res[6] - B.Marks.Res[6];
			}
			else
			{
				return -(A.Marks.Res[6] - B.Marks.Res[6]);
			}
		}
		default:
		{
			break;
		}
	}
	fclose(f);
	fclose(f2);
}
//Функция сборки части массива Tells из двух уже отсортированных частей. 
void merge(int beg, int mid, int end, int fild, int dist)
{
	long long* B = (long long*)malloc((end - beg + 1) * sizeof(long long));
	int i, j, k = 0, t;
	i = beg;
	j = mid + 1;
	while (i <= mid && j <= end)
	{
		if (comp(i, j, fild, dist) > 0)
		{
			B[k] = Tells[i];
			i++;
		}
		else
		{
			B[k] = Tells[j];
			j++;
		}
		k++;
	}
	for(t = i; t <= mid; ++t)
	{
		B[k] = Tells[t];
		k++;
	}
	for (t = j; t <= end; ++t)
	{
			B[k] = Tells[t];
			k++;
	}
	for (t = 0; t <= end - beg; ++t)
	{
		Tells[t + beg] = B[t];
	}
	free(B);
}
//Функция сортировки массива Tells. 
//Разделяет массив на 2 части, запускает сортировку обоих частей, запускает функцию соединения отсортированных частей. 
void mergesort(int beg, int end, int fild, int dist)
{
	int mid, i;
	if (beg < end)
	{
		mid = (beg + end) / 2;
		mergesort(beg, mid, fild, dist);
		mergesort(mid + 1, end, fild, dist);
		merge(beg, mid, end, fild, dist);
	}
}
//Функция подготовки к сортировке массива. 
//Проверяет, существуют ли в массиве неудалённые элементы, 
//узнаёт у пользователя поле и направление для сортировки.
void pre_Sort()
{
	char* S;
	FILE* f;
	f = stdin;
	int i, fild = -1, dist = -1, end;
	if (sz == 0)
	{
		printf("No elements in the base, so nothing to sort\n");
	}
	{
		printf("Enter one of the possible filds: ID, Name, Surename, Secondname, Faculty, Group, ");
		for (i = 0; i < 6; ++i)
		{
			printf("Subject%d, ", i + 1);
		}
		printf("Subject7\n");
		scanf(" ");
		S = readline(&f);
		if (strcmp(S, "ID") == 0)
		{
			fild = 1;
		}
		if (strcmp(S, "Name") == 0)
		{
			fild = 2;
		}
		if (strcmp(S, "Surename") == 0)
		{
			fild = 3;
		}
		if (strcmp(S, "Secondname") == 0)
		{
			fild = 4;
		}
		if (strcmp(S, "Faculty") == 0)
		{
			fild = 5;
		}
		if (strcmp(S, "Group") == 0)
		{
			fild = 6;
		}
		if (strcmp(S, "Subject1") == 0)
		{
			fild = 7;
		}
		if (strcmp(S, "Subject2") == 0)
		{
			fild = 8;
		}
		if (strcmp(S, "Subject3") == 0)
		{
			fild = 9;
		}
		if (strcmp(S, "Subject4") == 0)
		{
			fild = 10;
		}
		if (strcmp(S, "Subject5") == 0)
		{
			fild = 11;
		}
		if (strcmp(S, "Subject6") == 0)
		{
			fild = 12;
		}
		if (strcmp(S, "Subject7") == 0)
		{
			fild = 13;
		}
		printf("Enter the direction of the sort 0 - from higher to least, 1 - from least to higher\n");
		scanf("%d", &dist);
		if (dist != 0 && dist != 1)
		{
			printf("Incorrect direction, try again\n");
		}
		else
		{
			if (fild == -1)
			{
				printf("Incorrect fild, try again\n");
			}
			else
			{
				mergesort(0, sz - 1, fild, dist);
			}
		}
	}
}
