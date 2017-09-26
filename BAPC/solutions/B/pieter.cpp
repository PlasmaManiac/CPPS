// Solution to Signal Interference
// Author: Pieter Bootsma

// Time complexity: O(n)
// Memory: O(1)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: find signal with highest strength, compare with noise and rest

#include <iostream>

using namespace std;

double recv(double s, double x, double y, double xl, double yl)
{
	double xdiff = x-xl;
	double ydiff = y-yl;
	return s / (xdiff*xdiff + ydiff*ydiff);
}

void dostep()
{
	int n,N,xl,yl;
	cin >> n >> N >> xl >> yl;
	
	int max = 0;
	double maxr = 0;
	double noise = N;
	for (int i = 1; i <= n; i++)
	{
		int x,y,s;
		cin >> x >> y >> s;
		double r = recv(s, x, y, xl, yl);
		if (r > maxr)
		{
			noise += maxr;
			maxr = r;
			max = i;
		}
		else
		{
			noise += r;
		}
	}
	
	if (maxr > 6*noise)
		cout << max << endl;
	else
		cout << "NOISE" << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
