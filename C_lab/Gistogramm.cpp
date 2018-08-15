// Gist.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <malloc.h>
#define N 10000
typedef struct Day
{
	int year, month, day;
	float T;
}Day;
int main()
{
	Day* ALL_results = NULL;
	Day* My_results = NULL;
	int* Clusters = NULL;
	FILE* f, *f2;
	int size = 0, i, ch, my_year, size2 = 0, clussz, count, j;
	float T1, T3, Tmin = N, Tmax = -N, Tcur, Tnow;
	f = fopen("input.txt", "rt");
	f2 = fopen("input.txt", "rt");
	fseek(f2, -1, SEEK_END);
	while(ftell(f) < ftell(f2))
	{
		size++;
		ALL_results = (Day*)realloc(ALL_results, size*sizeof(Day));
		fscanf(f, "%d", &ALL_results[size - 1].year);
		fscanf(f, "%d", &ALL_results[size - 1].month);
		fscanf(f, "%d", &ALL_results[size - 1].day);
		fscanf(f, "%f", &T1);
		fscanf(f, "%f", &ALL_results[size - 1].T);
		fscanf(f, "%f", &T3);
		fscanf(f, "%d", &ch);
	}
	printf("Inter the year\n");
	scanf("%d", &my_year);
	for(i = 0; i < size; ++i)
	{
		if(ALL_results[i].year == my_year)
		{
			size2++;
			My_results = (Day*)realloc(My_results, size2*sizeof(Day));
			My_results[size2 - 1] = ALL_results[i];
			if(Tmin > ALL_results[i].T)
			{
				Tmin = ALL_results[i].T; 
			}
			if(Tmax < ALL_results[i].T)
			{
				Tmax = ALL_results[i].T; 
			}
		}
	}
	clussz = ((int)(Tmax - Tmin) + 5)/5;
	Clusters = (int*)malloc(clussz*sizeof(int));
	Tcur = Tmin;
	for(i = 0; i < clussz; ++i)
	{
		Clusters[i] = 0;
		printf("%d [%f, %f)\n", i, Tcur, Tcur + 5);
		Tcur = Tcur + 5;
	}
	for(i = 0; i < size2; ++i)
	{
		Tcur = My_results[i].T;
		Tnow = Tmin;
		count = 0;
		while(Tnow < Tcur)
		{
			Tnow = Tnow + 5;
			count++;
		}
		Clusters[count] = Clusters[count] + 1;
	}
	for(i = 0; i < clussz; ++i)
	{
		printf("Clusters[%d] = %d\n", i, Clusters[i]);
		
	}
	for(i = 0; i < clussz; ++i)
	{
		printf("%d ", i);
		for(j = 0; j < ((Clusters[i] + 4)/5); ++j)
		{
			printf("#");
		}
		printf("\n");
	}
	
	return 0;
}
