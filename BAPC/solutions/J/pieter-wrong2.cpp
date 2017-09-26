// Solution to RAID Reshaping
// Author: Pieter Bootsma

// Time complexity: O(n*e)
// Memory: O(n*e)

// @EXPECTED_RESULTS@: WRONG-ANSWER

// Solution method: greedy: pick value closest to average required value for min. number of disks (can wrongly use a disk twice)

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int nsets;
int sets[105];

struct sort_avg
{
	int avg;
	sort_avg(int a) : avg(a) {}
	bool operator()(int a, int b)
	{
		return abs(a-avg) < abs(b-avg);
	}
};

void dostep()
{
	int required;
	cin >> nsets >> required;
	
	for (int i = 0; i < nsets; i++)
	{
		cin >> sets[i];
	}
	
	sort(sets, sets+nsets);
	
	// Check how many disks we need at minimum
	int ndisks = 0;
	int total = 0;
	int i;
	for (i = nsets-1; (i >= 0) && (total*2 < required); i--)
	{
		ndisks++;
		total += sets[i];
	}
	if (total*2 < required)
	{
		cout << "FULL" << endl;
		return;
	}
	if (ndisks == 0)
	{
		cout << 0 << endl;
		return;
	}
	
	// Calculate average value of needed disk
	int avg = (required / 2) / ndisks;
	
	// Sort sets on distance to average
	sort(sets, sets+nsets, sort_avg(avg));
	
	// Pick disks until required number is reached
	total = 0;
	for (int i = 0; i < nsets; i++)
	{
		// Always check if we can reach optimum with 1 more disk (with bug)
		for (int j = 0; j < nsets; j++)
		{
			if ((total+sets[j])*2 >= required)
			{
				cout << total+sets[j] << endl;
				return;
			}
		}
		total += sets[i];
		if (total*2 >= required)
		{
			cout << total << endl;
			return;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
