// Solution to Message signing
// Author: Pieter Bootsma

// Time complexity: O(n^2)
// Memory: O(n)

// @EXPECTED_RESULTS@: TIMELIMIT
// -> Time complexity

// Solution method: check every occurring character in O(n) time

#include <iostream>

using namespace std;

void dostep()
{
	string s;
	cin >> s;
	
	bool fake = false;
	
	for (size_t i = 0; i < s.length(); i++)
	{
		// Check character s[i]
		
		int occurrences = 0;
		for (size_t j = 0; j < s.length(); j++)
		{
			if (s[j] == s[i])
			{
				occurrences++;
				if ((occurrences % 3) == 0)
				{
					j++;
					if ((j >= s.length()) || (s[j] != s[i]))
					{
						fake = true;
					}
				}
			}
		}
	}
	
	cout << (fake ? "FAKE" : "OK") << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	
	return 0;
}
