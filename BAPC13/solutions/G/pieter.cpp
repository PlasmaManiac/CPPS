// Solution to Message signing
// Author: Pieter Bootsma

// Time complexity: O(n)
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: count occurences of each character

#include <iostream>

using namespace std;

void dostep()
{
	string s;
	cin >> s;
	
	int occurences[256] = {0};
	
	for (size_t i = 0; i < s.length(); i++)
	{
		occurences[s[i]]++;
		char c = s[i];
		if ((occurences[c] % 3) == 0)
		{
			i++;
			if ((i >= s.length()) || (s[i] != c))
			{
				cout << "FAKE" << endl;
				return;
			}
		}
	}
	
	cout << "OK" << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	
	return 0;
}
