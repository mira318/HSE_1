#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
const int N = int(1e4) + 7;
long long Graph[N][N];
long long S[N][N];
int n;
long long inf;
long long search_way(int from, int to, int* Was, long long res, long long dist)
{
	Was[from] = 1;
	if (from == to)
	{
		dist = max(dist, res);
		Was[from] = 0;
		return dist;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (Was[i] == 0 && Graph[from][i] != inf)
			{
				dist = max(dist, search_way(i, to, Was, res + Graph[from][i], dist));
			}
		}
	}
	Was[from] = 0;
	return dist;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input7.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	cin >> inf;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> Graph[i][j];
			if (i == j)
			{
				Graph[i][j] = S[i][j] = 0;
			}
		}
	}
	long long dist;
	#pragma omp parallel
	{
		#pragma omp for private(dist, j, t)
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				int Was[N];
				for (int t = 0; t < n; ++t)
				{
					Was[t] = 0;
				}
				dist = search_way(i, j, Was, 0, -inf);
				S[i][j] = dist;
				S[j][i] = dist;
				if (S[i][j] == -inf)
				{
					S[i][j] = inf;
					S[j][i] = inf;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << S[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

