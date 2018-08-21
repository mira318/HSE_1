// NIS.Anyway.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <thread>
#include <map>
using namespace std;
const int N = int(1e4) + 7;
long long Graph[N][N];
long long S[N][N];
int n;
long long inf;
map<pair<int, int>, bool> Was1;
map<pair<int, int>, bool> Was2;
map<pair<int, int>, bool> Was3;
map<pair<int, int>, bool> Was4;
long long search_way(int from, int to, map<pair<int, int>, bool>* Was, long long res, long long dist)
{
	if (from == to)
	{
		dist = max(dist, res);
	}
	for (int i = 0; i < n; ++i)
	{
		if (Graph[from][i] != inf)
		{
			if (i >= from)
			{
				if ((*Was).find(make_pair(from, i)) == (*Was).end() || (*Was)[make_pair(from, i)] == false)
				{
					(*Was)[make_pair(from, i)] = true;
					dist = max(dist, search_way(i, to, Was, res + Graph[from][i], dist));
					(*Was)[make_pair(from, i)] = false;
				}
			}
			else
			{
				if ((*Was).find(make_pair(i, from)) == (*Was).end() || (*Was)[make_pair(i, from)] == false)
				{
					(*Was)[make_pair(i, from)] = true;
					dist = max(dist, search_way(i, to, Was, res + Graph[from][i], dist));
					(*Was)[make_pair(i, from)] = false;
				}
			}
		}
	}
	return dist;
}
void tread1(int a)
{
	for (int i = 0; i < a; ++i)
	{
		if (i / n <= i % n)
		{
			long long dist;
			dist = search_way(i / n, i % n, &Was1, 0, -inf);
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
		if (i / n <= i % n)
		{
			long long dist;
			dist = search_way(i / n, i % n, &Was2, 0, -inf);
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
		if (i / n <= i % n)
		{
			long long dist;
			dist = search_way(i / n, i % n, &Was3, 0, -inf);
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
		if (i / n <= i % n)
		{
			long long dist;
			dist = search_way(i / n, i % n, &Was4, 0, -inf);
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
	//freopen("input3.txt", "r", stdin);
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
			if (i <= j)
			{
				time++;
			}
			if (time >= n * n / 8 && a == -1)
			{
				a = i * n + j;
			}
			if (time >= n * n / 4 && b == -1)
			{
				b = i * n + j;
			}
			if (time >= 3 * n * n / 8 && c == -1)
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
