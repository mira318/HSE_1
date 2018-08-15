// Spirel.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <malloc.h>

int main()
{
	int n, m, k, d, count = 0, i, posx, posy, j, flag = 1, flag2 = 1;
	int** Matrix;
	scanf_s("%d %d %d %d", &n, &m, &k, &d);
	Matrix = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; ++i)
	{
		Matrix[i] = (int*)malloc(m * sizeof(int));
	}
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			Matrix[i][j] = -1;
		}
	}
	if (k == 0 && d == 0)
	{
		for (i = 0; i < n; ++i)
		{
			Matrix[i][0] = count % 16;
			count++;
		}
		posx = n - 1;
		posy = 0;
	}

	if (k == 0 && d == 1)
	{

		for (i = 0; i < m; ++i)
		{
			Matrix[0][i] = count % 16;
			count++;
		}
		posx = 0;
		posy = m - 1;

	}

	if (k == 1 && d == 0)
	{

		for (i = m - 1; i >= 0; --i)
		{
			Matrix[0][i] = count % 16;
			count++;
		}
		posx = 0;
		posy = 0;

	}

	if (k == 1 && d == 1)
	{

		for (i = 0; i < n; ++i)
		{
			Matrix[i][m - 1] = count % 16;
			count++;
		}
		posx = n - 1;
		posy = m - 1;
	}

	if (k == 3 && d == 0)
	{

		for (i = 0; i < m; ++i)
		{
			Matrix[n - 1][i] = count % 16;
			count++;
		}
		posx = n - 1;
		posy = n - 1;
	}

	if (k == 3 && d == 1)
	{

		for (i = n - 1; i >= 0; --i)
		{
			Matrix[i][0] = count % 16;
			count++;
		}
		posx = 0;
		posy = 0;
	}

	if (k == 2 && d == 0)
	{
		for (i = n - 1; i >= 0; --i)
		{
			Matrix[i][m - 1] = count % 16;
			count++;
		}
		posx = 0;
		posy = m - 1;
	}
	if (k == 2 && d == 1)
	{

		for (i = m - 1; i >= 0; --i)
		{
			Matrix[n - 1][i] = count % 16;
			count++;
		}
		posx = n - 1;
		posy = 0;
	}

	while (flag)
	{
		flag = 0;
		if (posx - 1 >= 0)
		{
			if (Matrix[posx - 1][posy] == -1)
			{
				flag = 1;
				flag2 = 1;
				while (flag2)
				{
					Matrix[posx - 1][posy] = count % 16;
					count++;
					posx--;
					flag2 = 0;
					if (posx - 1 >= 0)
					{
						if (Matrix[posx - 1][posy] == -1)
						{
							flag2 = 1;
						}
					}
				}
			}
		}
		if (posx + 1 < n)
		{
			if (Matrix[posx + 1][posy] == -1)
			{
				flag = 1;
				flag2 = 1;
				while (flag2)
				{
					Matrix[posx + 1][posy] = count % 16;
					count++;
					posx++;
					flag2 = 0;
					if (posx + 1 < n)
					{
						if (Matrix[posx + 1][posy] == -1)
						{
							flag2 = 1;
						}
					}
				}
			}
		}
		if (posy - 1 >= 0)
		{
			if (Matrix[posx][posy - 1] == -1)
			{
				flag = 1;
				flag2 = 1;
				while (flag2)
				{
					Matrix[posx][posy - 1] = count % 16;
					count++;
					posy--;
					flag2 = 0;
					if (posy - 1 >= 0)
					{
						if (Matrix[posx][posy - 1] == -1)
						{
							flag2 = 1;
						}
					}
				}
			}
		}
		if (posy + 1 < m)
		{
			if (Matrix[posx][posy + 1] == -1)
			{
				flag = 1;
				flag2 = 1;
				while (flag2)
				{
					Matrix[posx][posy + 1] = count % 16;
					count++;
					posy++;
					flag2 = 0;
					if (posy + 1 < m)
					{
						if (Matrix[posx][posy + 1] == -1)
						{
							flag2 = 1;
						}
					}
				}
			}
		}
	}
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			if (Matrix[i][j] < 10)
			{
				printf("%d", Matrix[i][j]);
			}
			else
			{
				printf("%c", Matrix[i][j] - 10 + 'A');
			}
		}
		printf("\n");
	}
    return 0;
}

