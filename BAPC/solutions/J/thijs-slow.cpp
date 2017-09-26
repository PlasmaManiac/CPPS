// @EXPECTED_RESULTS@: TIMELIMIT

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> s;
int c,n;

int rec(int sum, int i)
{
	if (sum > c)
		return sum;
	if (i==n)
		return -1;
	int a=rec(sum+s[i], i+1);
	int b=rec(sum, i+1);
	if (a==-1)
		return b;
	if (b==-1)
		return a;
	return min(a, b);
}

void dostep()
{
	cin>>n>>c;
	s.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		s[i]*=2;
	}
	int best=rec(0,0);
	if (best==-1)
		cout<<"FULL"<<endl;
	else
		cout<<(best/2)<<endl;
}

int main()
{
	int n;
	cin>>n;
	while(n--)dostep();
	return 0;
}
