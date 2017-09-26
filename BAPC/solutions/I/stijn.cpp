// @EXPECTED_RESULTS@: CORRECT
#include <iostream>
#include <vector>
#include <set>
#include <ctime>
using namespace std;

const int M = 1000*1000*1000;
const int sqrtM = 40*1000;

int main()
{
	double dt = clock();

	// prime sieve (kan stuk efficienter)
	vector<int> primes;
	{
		vector<bool> f(sqrtM, true);
		f[0] = f[1] = false;
		for(int i = 0; i < sqrtM; i++)
		{
			if ( f[i] )
			{
				primes.push_back(i);
				for(int j = i+i; j < sqrtM; j+=i) f[j] = false;
			}
		}
	}

	int runs = -1; cin >> runs;

	for(int run = 0; run < runs; run++)
	{
		int n = -1; cin >> n;

		set<int> ids;
		for(int i = 0; i < primes.size(); i++)
		{
			// check of n deelbaar is door p^k (kan efficienter)
			int p = primes[i];
			int k = 0;
			for( ; n % p == 0; k++) n /= p;
			
			// k is bepaald, voeg nu getallen van de vorm p^q toe
			// waarbij q = 2^i en sum(q) = k
			for(int q = 1, pq = p; q <= k ; q <<= 1, pq *= pq)
			{
				if ( q & k ) ids.insert( pq );
			}

			if ( n == 1 ) break;
		}
		if ( n > 1 ) ids.insert(n);

		// output
		for(auto it = ids.begin(); it != ids.end(); it++)
		{
			if ( it != ids.begin() ) cout << " ";
			cout << *it;
		}
		cout << endl;
	}

	return 0;
}
