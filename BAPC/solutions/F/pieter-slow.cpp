// Solution to Fare Dodging
// Author: Pieter Bootsma

// Time complexity: O(n^3)
// Memory: O(n^2)

// @EXPECTED_RESULTS@: TIMELIMIT

// Solution method: Floyd-Warshall on two-layered graph

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <cstdio>

using namespace std;

#define MAX_VER 405
#define INFINITE 9e30

int NV = 0;
double dis[MAX_VER][MAX_VER];

void reset() {
	for(int i = 0; i < MAX_VER; i++)
	{
		for (int j = 0; j < MAX_VER; j++)
		{
			dis[i][j] = i==j ? 0 : INFINITE;
		}
	}
	
	NV = 0;
}

void floydwarshall()
{
	for (int k=1; k <= NV; k++)
	{
		for (int j=1; j <= NV; j++)
		{
			for (int i=1; i <= NV; i++)
			{
				if (dis[i][k] + dis[k][j] < dis[i][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
}


void dostep()
{
	reset();
	
	int n,m,start,end,s,p,y;
	cin >> n >> m >> start >> end >> s >> p >> y;
	
	for (int i = 1; i <= n; i++)
	{
		dis[i][i+n] = s;
		dis[i+n][i] = 0;
	}
	
	for (int i = 0; i < m; i++)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		dis[a][b] = ((y+d*p)*c)/100.;
		dis[b][a] = ((y+d*p)*c)/100.;
		dis[a+n][b+n] = d*p;
		dis[b+n][a+n] = d*p;
	}
	
	NV = 2*n;
	floydwarshall();
	
	printf("%.2f\n", dis[start][end]);
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
