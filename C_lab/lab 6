// лаба_6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "my_struct.h"
#include <locale.h> 
#define DEBUG 0
#ifndef MY_STRUCT
#define MY_STRUCT
#endif
const int M = 999999999;
int datecmp(struct BirthDate A, struct BirthDate B) //Функция сравнивает две переменных типа BirthDate.
//Возвращает число > 0, если первая дата рождения позже по времени чем вторая и возвращает число < 0, если первая дата рождения раньше по времени, чем вторая  
{
	if (A.year == B.year)
	{
		if (A.month == B.month)
		{
			return(A.day - B.day);
		}
		return(A.month - B.month);
	}
	return(A.year - B.year);
}
int strcmp(char* A, char* B)// Функция сравнивает строки A и B. Возвращает 1, если они одинаковы и 0 в противном случае.
{
	int i = 0, sz = 0;
	while (A[i] != '\0' && B[i] != '\0')
	{
		i++;
	}
	if (A[i] != '\0' || B[i] != '\0')
	{
		return 0;
	}
	sz = i;
	i = 0;
	for (; i < sz; ++i)
	{
		if (A[i] != B[i])
		{
			return 0;
		}
	}
	return 1;
}
void autoFill(Employee* A)//Функция заполняет массив A структур Employee заранее подготовленной информацией
{
	
	struct fio fo = {"Иванов", "Иван", "Иванович"};
	struct BirthDate date = {12, 7, 1997};
	struct Address addr = {"Москва", "3-ая Строительная", "5k2", 112};
	struct fio fo1 = { "Черкасов", "Алексей", "Юрьевичвич" };
	struct BirthDate date1 = { 12, 11, 1997 };
	struct Address addr1 = { "Санкт-Петербург", "3-ая Строительная", "5k2", 16};
	struct fio fo2 = { "Разумихин", "Николай", "Сергеевич" };
	struct BirthDate date2 = { 1, 7, 1997 };
	struct Address addr2 = { "Санкт-Петербург", "Лиговский проспект", "5k2", 7};
	struct fio fo3 = { "Астафьев", "Иван", "Трифонавич" };
	struct BirthDate date3 = { 12, 4, 1995 };
	struct Address addr3 = { "Нижний Новгород", "Тверская-Ямская", "8c4", 163};
	struct fio fo4 = { "Карасёв", "Андрей", "Михайлович"};
	struct BirthDate date4 = { 26, 9, 1997 };
	struct Address addr4 = { "Курск", "Ленина", "52", 196};
	A[0].fio = fo;
	A[0].BirthDate = date;
	A[0].Address = addr;
	A[1].fio = fo1;
	A[1].BirthDate = date1;
	A[1].Address = addr1;
	A[2].fio = fo2;
	A[2].BirthDate = date2;
	A[2].Address = addr2;
	A[3].fio = fo3;
	A[3].BirthDate = date3;
	A[3].Address = addr3;
	A[4].fio = fo4;
	A[4].BirthDate = date4;
	A[4].Address = addr4;
}
void userFill(Employee* A, int s)//Функция позволяет пользователю 
//самостоятельно, поэтапно заполнить массив A структур Employee  
{
	int i = 0;
	printf("PLease, input all information in English\n");
	for (; i < s; ++i)
	{
		printf("Input Surename\n");
		scanf(" ");
		gets(A[i].fio.Surename);
		printf("Input Name\n");
		gets(A[i].fio.Name);
		printf("Input Secondname\n");
		gets(A[i].fio.Secondname);
		printf("Input Day of Birth\n");
		scanf("%d", &(A[i].BirthDate.day));
		printf("Input Month of Birth\n");
		scanf("%d", &(A[i].BirthDate.month));
		printf("Input Year of Birth\n");
		scanf("%d", &(A[i].BirthDate.year));
		printf("Input Town of living\n");
		scanf(" ");
		gets(A[i].Address.town);
		printf("Input Street of living\n");
		gets(A[i].Address.street);
		printf("Input House of living\n");
		gets(A[i].Address.house);
		printf("Input Number of flat\n");
		scanf("%d", &(A[i].Address.flat));
	}
}
void write(Employee B)//Функция выводит один элемент типа Employee на экран
{
	printf("FIO:\n");
	puts(B.fio.Surename);
	puts(B.fio.Name);
	puts(B.fio.Secondname);
	printf("Date of birth:\n");
	printf("%d.%d.%d\n", B.BirthDate.day, B.BirthDate.month, B.BirthDate.year);
	printf("Address:\n");
	puts(B.Address.town);
	puts(B.Address.street);
	puts(B.Address.house);
	printf("%d\n", B.Address.flat);
}
void search(Employee* A, int sz)//Функция запрашивает у пользователя, номер дома, по которому следует искать служащего, 
//проходится по всему массиву с информацией и находит самого молодого служащего, живущего в данном доме
{
	int i = 0;
	Employee Ans;
	printf("Input the number of house you looking in\n");
	scanf(" ");
	gets(Ans.Address.house);
	Ans.BirthDate.day = M;
	Ans.BirthDate.month = M;
	Ans.BirthDate.year = M;
	for (; i < sz; ++i)
	{
		if (strcmp(A[i].Address.house, Ans.Address.house))
		{
			if (datecmp(A[i].BirthDate, Ans.BirthDate))
			{
				Ans = A[i];
			}
		}
	}
	if (Ans.BirthDate.year != M)
	{
		printf("I found this employee:\n");
		write(Ans);
	}
	else
	{
		printf("We don't have employees, who live in this house\n");
	}
}
int main()//Функция заводит массив структур Empoyee, в зависимости от значения константы DEBUG
//вызывает функции автоматического или пользовательского заполнения. 
//Далее выводит получившийся массив на экран и запускает функцию поиска самого молодого служащего из данного дома. 
//В случае корректного завершения работы, функция возвращает 0.
{
	
	struct Employee A[23];
	int size, i = 0;
	setlocale(LC_ALL, "rus");
	#if DEBUG
		autoFill(A);
		size = 5;
	#else
		printf("Input array size <= 20\n");
		scanf("%d", &size);
		userFill(A, size);
	#endif
	for (; i < size; ++i)
	{
		write(A[i]);
	}
	search(A, size);
	return 0;
}
