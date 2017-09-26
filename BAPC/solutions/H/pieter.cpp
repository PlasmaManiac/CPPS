// Solution to Car Equipment
// Author: Pieter Bootsma

// Time complexity: O(n)
// Memory: O(1)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: multiply and add

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		int s,n;
		cin >> s >> n;
		for (int i = 0; i < n; i++)
		{
			int m,p;
			cin >> m >> p;
			s += m*p;
		}
		cout << s << endl;
	}
	return 0;
}
