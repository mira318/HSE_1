#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = int(1e4) + 7;
long long Graph[N][N];
long long S[N][N];
int n;
long long inf;
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
			if (i < from)
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
		}
	}
	long long dist;
	map<pair<int, int>, bool> Was;
	#pragma omp parallel
	{
		#pragma omp for private(dist, j, Was)
		for (int i = 0; i < n; ++i)
		{
			for (int j = i; j < n; ++j)
			{

				dist = search_way(i, j, &Was, 0, -inf);
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

