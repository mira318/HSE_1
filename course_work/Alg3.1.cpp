#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = int(1e4) + 7;
long long Graph[N][N];
long long S[N][N];
int n;
long long dist, inf;
map<pair<int, int>, bool> Was;
void search_way(int from, int to, long long res)
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
				if (Was.find(make_pair(from, i)) == Was.end() || Was[make_pair(from, i)] == false)
				{
					Was[make_pair(from, i)] = true;
					search_way(i, to, res + Graph[from][i]);
					Was[make_pair(from, i)] = false;
				}
			}
			else
			{
				if (Was.find(make_pair(i, from)) == Was.end() || Was[make_pair(i, from)] == false)
				{
					Was[make_pair(i, from)] = true;
					search_way(i, to, res + Graph[from][i]);
					Was[make_pair(i, from)] = false;
				}
			}
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
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
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
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



