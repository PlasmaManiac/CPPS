// Solution to RAID Reshaping
// Author: Pieter Bootsma

// Time complexity: O(n*e)
// Memory: O(n*e)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: 0/1-knapsack on sets not to convert

#include <iostream>
#include <algorithm>

using namespace std;

int A[105][1000005];

int knapsack(int N, int *weight, int max_w)
{
	fill(A[0], A[0] + max_w + 1, 0);
	for (int i = 0; i < N; i++)
	{
		A[i][0] = 0;
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= max_w; j++)
		{
			A[i][j] = max(A[i-1][j], A[i][j-1]);
			if (weight[i-1] <= j)
			{
				A[i][j] = max(A[i][j], A[i-1][j-weight[i-1]] + weight[i-1]);
			}
		}
	}
	
	return A[N][max_w];
}

void dostep()
{
	int nsets, required;
	cin >> nsets >> required;
	
	required = (required + 1) / 2;
	
	int sets[105];
	int possible = 0;
	for (int i = 0; i < nsets; i++)
	{
		cin >> sets[i];
		possible += sets[i];
	}
	
	if (required > possible)
	{
		cout << "FULL" << endl;
		return;
	}
	
	cout << possible - knapsack(nsets, sets, possible - required) << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
