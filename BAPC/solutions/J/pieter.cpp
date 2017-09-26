// Solution to RAID Reshaping
// Author: Pieter Bootsma

// Time complexity: O(n*e)
// Memory: O(n*e)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: memoization

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int nsets;
int sets[105];
int possible[105];
int mem[1000005][105];

int calc(int i, int req)
{
	if (req > possible[i])
		return -1;
	else if (req <= 0)
		return 0;
	else if (mem[req][i])
		return mem[req][i];
	
	int a = calc(i+1, req);
	int b = sets[i] + calc(i+1, max(0, req - 2*sets[i]));
	
	int res = min(a,b);
	
	if (a < 0)
		res = b;
	else if (b < 0)
		res = a;
	
	mem[req][i] = res;
	
	return res;
}

void dostep()
{
	int required;
	cin >> nsets >> required;
	
	for (int i = 0; i < nsets; i++)
	{
		cin >> sets[i];
	}
	
	possible[nsets] = 0;
	for (int i = nsets-1; i >= 0; i--)
	{
		possible[i] = possible[i+1] + 2*sets[i];
	}
	
	memset(mem, 0, (possible[0]+5)*105*sizeof(int));
	
	int min = calc(0, required);
	if (min < 0)
		cout << "FULL" << endl;
	else
		cout << min << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
