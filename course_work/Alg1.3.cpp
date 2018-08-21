// NIS.Alg1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <thread>
#include <vector>
using namespace std;
const int N = int(1e4) + 7;
long long Graph[N][N];
long long S[N][N];
bool Was[N];
long long inf = 1000000000000;
int comp_am, n, step1 = -1, step2 = -1, step3 = -1;
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
void Floid1(int c, int step1)
{
	int a, b;
	for (int j = 0; j < step1; ++j)
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
void Floid2(int c, int step1, int step2)
{
	int a, b;
	for (int j = step1; j < step2; ++j)
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
void Floid3(int c, int step2, int step3)
{
	int a, b;
	for (int j = step2; j < step3; ++j)
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
void Floid4(int c, int step3)
{
	int a, b;
	for (int j = step3; j < Comp[comp_am].size(); ++j)
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
void Floid()
{
	int a, b, c, time = 0, step1 = -1, step2 = -1, step3 = -1;
	if (Comp[comp_am].size() > 0)
	{
		for (int i = 0; i < Comp[comp_am].size(); ++i)
		{
			for (int j = i + 1; j < Comp[comp_am].size(); ++j)
			{
				time++;
				a = Comp[comp_am][i];
				b = Comp[comp_am][j];
				if (time >= Comp[comp_am].size() * (Comp[comp_am].size() - 1) / 8 && step1 == -1)
				{
					step1 = i;
				}
				if (time >= Comp[comp_am].size() * (Comp[comp_am].size() - 1) / 4 && step2 == -1)
				{
					step2 = i;
				}
				if (time >= 3 * Comp[comp_am].size() * (Comp[comp_am].size() - 1) / 8 && step3 == -1)
				{
					step3 = i;
				}
				if (a != b && Graph[a][b] != inf)
				{
					S[a][b] = -S[a][b];
					S[b][a] = S[a][b];
				}
			}
		}
		
		for (int i = 0; i < Comp[comp_am].size(); ++i)
		{
			c = Comp[comp_am][i];
			thread t1(Floid1, c, step1);
			thread t2(Floid2, c, step1, step2);
			thread t3(Floid3, c, step2, step3);
			thread t4(Floid4, c, step3);
			t1.join();
			t2.join();
			t3.join();
			t4.join();
		}
		for (int i = 0; i < Comp[comp_am].size(); ++i)
		{
			for (int j = i + 1; j < Comp[comp_am].size(); ++j)
			{
				a = Comp[comp_am][i];
				b = Comp[comp_am][j];
				if (S[a][b] != inf)
				{
					S[a][b] = -S[a][b];
					S[b][a] = S[a][b];
				}
			}
		}
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b; 
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
				for (int k = j + 1; k < Comp[comp_am].size(); ++k)
				{
					a = Comp[comp_am][j];
					b = Comp[comp_am][k];
					if (a == b)
					{
						S[a][b] = 0;
					}
					else
					{
						S[a][b] = inf;
					}
					S[b][a] = S[a][b];
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


