// NIS.Alg1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = int(1e4) + 7;
long long Graph[N][N];
long long S[N][N];
bool Was[N];
long long inf = 1000000000000;
int comp_am, n;
vector<int> Comp[N];
void dfs(int v)
{
	Comp[comp_am].push_back(v);
	Was[v] = true;
	for (int i = 0; i < n; ++i)
	{
		if (Graph[v][i] != inf && !Was[i])
		{
			dfs(i);
		}
	}
}
bool check()
{
	int a, b;
	for (int i = 0; i < Comp[comp_am].size(); ++i)
	{
		for (int j = 0; j < Comp[comp_am].size(); ++j)
		{
			a = Comp[comp_am][i];
			b = Comp[comp_am][j];
			if (Graph[a][b] != inf && Graph[a][b] > 0)
			{
				return true;
			}
		}
	}
	return false;
}
void Floid()
{
	int a, b, c;
	for (int i = 0; i < Comp[comp_am].size(); ++i)
	{
		for (int j = 0; j < Comp[comp_am].size(); ++j)
		{
			a = Comp[comp_am][i];
			b = Comp[comp_am][j];
			if (a != b && Graph[a][b] != inf)
			{
				S[a][b] = -S[a][b];
			}
		}
	}
	#pragma omp parallel
	{
		#pragma omp for private(j, k) firstprivate(a, b, c)
		for (int i = 0; i < Comp[comp_am].size(); ++i)
		{
			c = Comp[comp_am][i];
			for (int j = 0; j < Comp[comp_am].size(); ++j)
			{
				a = Comp[comp_am][j];
				for (int k = j + 1; k < Comp[comp_am].size(); ++k)
				{
					b = Comp[comp_am][k];
					if (a != b && a != c && b != c)
					{
						S[a][b] = min(S[a][b], S[a][c] + S[b][c]);
						S[b][a] = S[a][b];
					}
				}
			}
		}
	}
	for (int i = 0; i < Comp[comp_am].size(); ++i)
	{
		for (int j = 0; j < Comp[comp_am].size(); ++j)
		{
			a = Comp[comp_am][i];
			b = Comp[comp_am][j];
			if (S[a][b] != inf)
			{
				S[a][b] = -S[a][b];
			}
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input8.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	cin >> inf;
	comp_am = 0;
	for (int i = 0; i < n; ++i)
	{
		Was[i] = false;
		for (int j = 0; j < n; ++j)
		{
			cin >> Graph[i][j];
			if (i == j)
			{
				S[i][j] = 0;
				Graph[i][j] = 0;
			}
			else
			{
				S[i][j] = Graph[i][j];
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (Was[i] == false)
		{
			dfs(i);
		}
		if (check())
		{
			for (int j = 0; j < Comp[comp_am].size(); ++j)
			{
				for (int k = 0; k < Comp[comp_am].size(); ++k)
				{
					int a = Comp[comp_am][j];
					int b = Comp[comp_am][k];
					if (a == b)
					{
						S[a][b] = 0;
					}
					else
					{
						S[a][b] = inf;
					}
				}
			}
		}
		else
		{
			Floid();
		}
		comp_am++;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << S[i][j] << " ";
		}
		cout << endl;
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
