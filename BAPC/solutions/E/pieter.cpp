// Solution to RSA
// Author: Pieter Bootsma

// Time complexity: O(n log n)
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: map public keys and their order, then lookup ciphertext positions

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

void dostep()
{
	int n;
	cin >> n;
	
	string s;
	
	vector<string> pos_first;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		pos_first.push_back(s);
	}
	
	map<string,int> second_pos;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		second_pos[s] = i;
	}
	
	vector<string> cipher_words;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		cipher_words.push_back(s);
	}
	
	for (size_t i = 0; i < pos_first.size(); i++)
	{
		if (i > 0)
			cout << ' ';
		cout << cipher_words[second_pos[pos_first[i]]];
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	
	return 0;
}
