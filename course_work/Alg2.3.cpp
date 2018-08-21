// NIS.Anyway.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <thread>
using namespace std;
const int N = int(1e4) + 7;
long long Graph[N][N];
long long S[N][N];
int n;
long long inf;
int Was1[N];
int Was2[N];
int Was3[N];
int Was4[N];
long long search_way(int from, int to, int* Was, long long res, long long dist)
{
	Was[from] = 1;
	if (from == to)
	{
		dist = max(dist, res);
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (Was[i] == 0 && Graph[from][i] != inf)
			{
				dist = max(search_way(i, to, Was, res + Graph[from][i], dist), dist);
			}
		}
	}
	Was[from] = 0;
	return dist;
}
void tread1(int a)
{
	for (int i = 0; i < a; ++i)
	{
		if (i / n < i % n)
		{
			for (int t = 0; t < n; ++t)
			{
				Was1[t] = 0;
			}
			long long dist;
			dist = search_way(i / n, i % n, Was1, 0, -inf);
			if (dist == -inf)
			{
				S[i / n][i % n] = inf;
				S[i % n][i / n] = inf;
			}
			else
			{
				S[i / n][i % n] = dist;
				S[i % n][i / n] = dist;
			}
		}
	}
}

void tread2(int a, int b)
{
	for (int i = a; i < b; ++i)
	{
		if (i / n < i % n)
		{
			for (int t = 0; t < n; ++t)
			{
				Was2[t] = 0;
			}
			long long dist;
			dist = search_way(i / n, i % n, Was2, 0, -inf);
			if (dist == -inf)
			{
				S[i / n][i % n] = inf;
				S[i % n][i / n] = inf;
			}
			else
			{
				S[i / n][i % n] = dist;
				S[i % n][i / n] = dist;
			}
		}
	}
}

void tread3(int b, int c)
{
	for (int i = b; i < c; ++i)
	{
		if (i / n < i % n)
		{
			for (int t = 0; t < n; ++t)
			{
				Was3[t] = 0;
			}
			long long dist;
			dist = search_way(i / n, i % n, Was3, 0, -inf);
			if (dist == -inf)
			{
				S[i / n][i % n] = inf;
				S[i % n][i / n] = inf;
			}
			else
			{
				S[i / n][i % n] = dist;
				S[i % n][i / n] = dist;
			}
		}
	}
}

void tread4(int c)
{
	for (int i = c; i < n*n; ++i)
	{
		if (i / n < i % n)
		{
			for (int t = 0; t < n; ++t)
			{
				Was4[t] = 0;
			}
			long long dist;
			dist = search_way(i / n, i % n, Was4, 0, -inf);
			if (dist == -inf)
			{
				S[i / n][i % n] = inf;
				S[i % n][i / n] = inf;
			}
			else
			{
				S[i / n][i % n] = dist;
				S[i % n][i / n] = dist;
			}
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input7.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	cin >> inf;
	int a = -1, b = -1, c = -1, time = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> Graph[i][j];
			if (i == j)
			{
				S[i][j] = 0;
			}
			if (i < j)
			{
				time++;
			}
			if (time >= n * (n - 1)/ 8 && a == -1)
			{
				a = i * n + j;
			}
			if (time >= n * (n - 1) / 4 && b == -1)
			{
				b = i * n + j;
			}
			if (time >= 3 * n * (n - 1) / 8 && c == -1)
			{
				c = i * n + j;
			}
		}
	}
	thread t1(tread1, a);
	thread t2(tread2, a, b);
	thread t3(tread3, b, c);
	thread t4(tread4, c);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << S[i][j] << " ";
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
