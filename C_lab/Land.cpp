// Land.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <malloc.h>
#include <string>
const int N = 10007;
int good(int count, int len, int x, int y, int** My_Map, char** Map)
{
	printf("good(%d, %d)\n", x, y);
	if ((x >= 0) && (x < count) && (y > 0) && (y < len))
	{
		if (Map[x][y] == '#' || My_Map[x][y] == 1)
			return 0;
	}

	if ((x > 0) && (y > 0) && (y < len))
	{
		printf("1 ");
		if (Map[x - 1][y] == '#')
			return 1;
	}
	if ((x < count - 1) && (y > 0) && (y < len))
	{

		printf("2 ");
		if (Map[x + 1][y] == '#')
			return 1;
	}
	if ((y > 0) && (x >= 0) && (x < count))
	{

		printf("3 ");
		if (Map[x][y - 1] == '#')
			return 1;
	}
	if ((y < len - 1) && (x >= 0) && (x < count))
	{

		printf("4 ");
		if (Map[x][y + 1] == '#')
			return 1;
	}

	if (x > 0 && y > 0)
	{

		printf("5 ");
		if (Map[x - 1][y - 1] == '#')
			return 1;
	}
	if (x > 0 && y < len - 1)
	{

		printf("6 ");
		if (Map[x - 1][y + 1] == '#')
			return 1;
	}
	if (x < count - 1 && y > 0)
	{

		printf("7 ");
		if (Map[x + 1][y - 1] == '#')
			return 1;
	}
	if (x < count - 1 && y < len - 1)
	{

		printf("8 ");
		if (Map[x + 1][y + 1] == '#')
			return 1;
	}
	printf("finished\n");
	return 0;
}
void rek(int count, int len, int fromx, int fromy, int x, int y, int** My_Map, char** Map)
{
	if (good(count, len, x, y, My_Map, Map))
	{
		printf("(%d, %d) ", x, y);
		My_Map[x][y] = 1;
		rek(count, len, fromx, fromy, x - 1, y, My_Map, Map);
		rek(count, len, fromx, fromy, x + 1, y, My_Map, Map);
		rek(count, len, fromx, fromy, x, y - 1, My_Map, Map);
		rek(count, len, fromx, fromy, x, y + 1, My_Map, Map);
		rek(count, len, fromx, fromy, x - 1, y - 1, My_Map, Map);
		rek(count, len, fromx, fromy, x - 1, y + 1, My_Map, Map);
		rek(count, len, fromx, fromy, x + 1, y - 1, My_Map, Map);
		rek(count, len, fromx, fromy, x + 1, y + 1, My_Map, Map);
		if (x != fromx || y != fromy)
		{
			printf("(%d, %d)", x, y);
		}
	}
}
int main()
{
	FILE* f, *f2;
	char name[100];
	int i, flag = 0, x = 1, y = 1, count = 0, len;
	char** Map = NULL;
	char S[N];
	char S1[N];
	int** My_Map = NULL;
	printf("Input file name\n");
	scanf(" ");
	gets_s(name);
	f = fopen(name, "rt");
	f2 = fopen(name, "rt");
	fseek(f2, 0, SEEK_END);
	while (ftell(f) < ftell(f2))
	{
		fgets(S, N, f);
		count++;
		printf("S = ");
		puts(S);
		Map = (char**)realloc(Map, count * sizeof(char*));
		Map[count - 1] = (char*)malloc(strlen(S) * sizeof(char));
		strcpy(Map[count - 1], S);
	}
	len = strlen(Map[0]) - 1;
	My_Map = (int**)malloc(count * sizeof(int*));
	for (i = 0; i < count; ++i)
	{
		My_Map[i] = (int*)malloc(len * sizeof(int));
		memset(My_Map[i], 0, len);
	}
	while (!flag && x < count - 1)
	{
		y = 1;
		while (!flag && y < len - 1)
		{

			if (Map[x][y + 1] == '#')
			{
				flag = 1;
			}
			else
			{
				y++;
			}
		}
		if(!flag)
			x++;
	}
	printf("len = %d\n", len);
	printf("count = %d\n", count);
	if (x == len)
	{
		printf("No land\n");
		return 0;
	}
	else
	{
		rek(count, len, x, y, x, y, My_Map, Map);
	}
	fclose(f);
	fclose(f2);
    return 0;
}

