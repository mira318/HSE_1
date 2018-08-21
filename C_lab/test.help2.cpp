// labask.test.Stepan.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>


int main()
{
	long long n, ans_k;
	setlocale(LC_ALL, "rus");
	scanf("%lld", &n);
	ans_k = n % 100;
	n = n / 100;
	printf("%lld руб. ", n);
	if (ans_k < 10)
	{
		printf("0");
	}
	printf("%lld коп.\n", ans_k);
    return 0;
}
