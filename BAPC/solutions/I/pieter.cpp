// Solution to Spy Identification Codes
// Author: Pieter Bootsma

// Time complexity: O(sqrt(c))
// Memory: O(log(c))

// @EXPECTED_RESULTS@: CORRECT

// Solution method: prime factorization with special case for primes occurring more than once

#include <iostream>
#include <map>
#include <cmath>
#include <set>

using namespace std;

map<int,int> factor(int n)
{
	map<int,int> r;
	while (n % 2 == 0)
	{
		n /= 2;
		r[2]++;
	}
	for (int i = 3; i <= (int)sqrt(n); i += 2)
	{
		while (n%i == 0)
		{
			n /= i;
			r[i]++;
		}
	}
	if (n > 2)
	{
		r[n]++;
	}
	return r;
}

void dostep()
{
	int c;
	cin >> c;
	
	map<int,int> factors = factor(c);
	typedef map<int,int>::iterator mapit;
	set<int> sics;
	typedef set<int>::iterator setit;
	
	for (mapit it = factors.begin(); it != factors.end(); it++)
	{
		int n = it->first;
		int c = it->second;
		while (c > 0)
		{
			if (c % 2)
				sics.insert(n);
			
			c /= 2;
			n *= n;
		}
	}
	
	for (setit it = sics.begin(); it != sics.end(); it++)
	{
		if (it != sics.begin())
			cout << ' ';
		cout << *it;
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
