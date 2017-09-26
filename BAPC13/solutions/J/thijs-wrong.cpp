// Randomly picks disks to be added to the set of disks to be converted.
// Should either fail or run into the timelimit.
// @EXPECTED_RESULTS@: WRONG-ANSWER

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct disk
{
	int s;
	bool in;
};

int rseed = 42;
int randnr()
{ return rseed = (16807ll * rseed) % 2147483647;
}

void dostep()
{
	int c,n;
	cin>>n>>c;
	vector<disk> s(n);
	for(int i=0;i<n;i++)
	{
		cin>>s[i].s;
		s[i].s*=2;
		s[i].in=false;
	}
	int best=-1;
	for (int i=0;i<300; i++)
	{
		for (int j=0;j<n;j++)
			s[j].in=false;
		int saved=0;
		for (int j=0;j<4000&&saved<c; j++)
		{
			int idx=randnr()%n;
			if (s[idx].in)
				continue;
			s[idx].in=true;
			saved+=s[idx].s;
		}
		if (saved>=c && (best==-1||saved<best))
			best=saved;
	}
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
