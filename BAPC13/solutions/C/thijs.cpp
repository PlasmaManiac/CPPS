// @EXPECTED_RESULTS@: CORRECT
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

int num[4];

double comp(double a, double b, int op)
{
	switch (op)
	{
	case 0:
		return a + b;
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a / b;
	}
	return -1;
}

void dostep()
{
	cin>>num[0]>>num[1]>>num[2]>>num[3];
	sort(num, num+4);
	
	bool ok=false;
	do {
		for (int i=0; i<4; i++)
			for (int j=0; j<4; j++)
				for (int k=0; k<4; k++)
				{
					// (a*b)*(c*d)
					double a = comp(comp(num[0],num[1],i), comp(num[2], num[3], k), j);
					// ((a*b)*c)*d
					double b = comp(comp(comp(num[0],num[1],i), num[2], j), num[3], k);
					// (a*(b*c))*d
					double c = comp(comp(num[0], comp(num[1],num[2],j), i), num[3], k);
					// a*((b*c)*d)
					double d = comp(num[0], comp(comp(num[1],num[2],j), num[3], k) ,i);
					// a*(b*(c*d))
					double e = comp(num[0], comp(num[1], comp(num[2],num[3],k), j) ,i);
					ok |= (fabs(a-24)<0.001);
					ok |= (fabs(b-24)<0.001);
					ok |= (fabs(c-24)<0.001);
					ok |= (fabs(d-24)<0.001);
					ok |= (fabs(e-24)<0.001);
				}
	} while(next_permutation(num, num+4));
	cout<<(ok?"YES":"NO")<<endl;
}

int main()
{
	int n;
	cin>>n;
	while(n--)dostep();
	return 0;
}
