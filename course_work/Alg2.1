#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
const int N = int(1e4) + 7;
long long Graph[N][N];
long long S[N][N];
int n;
long long dist, inf;
int Was[N];
void search_way(int from, int to, long long res)
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
				search_way(i, to, res + Graph[from][i]);
			}
		}
	}
	Was[from] = 0;
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
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			for (int t = 0; t < n; ++t)
			{
				Was[t] = 0;
			}
			dist = -inf;
			search_way(i, j, 0);
			S[i][j] = dist;
			S[j][i] = dist;
			if (S[i][j] == -inf)
			{
				S[i][j] = inf;
				S[j][i] = inf;
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
	fclose(stdin);
	fclose(stdout);
	return 0;
}

