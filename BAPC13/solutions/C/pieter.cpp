// Solution to Twenty-four
// Author: Pieter Bootsma

// Time complexity: O(1)
// Memory: O(1)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: combine numbers in all possible ways

#include <iostream>
#include <vector>

using namespace std;

struct fraction
{
	int num,den;
	
	fraction(int n, int d = 1) : num(n), den(d) {}
	
	bool is24() const
	{
		return (den != 0) && (den*24 == num);
	}
	
	fraction operator+(fraction &f)
	{
		return fraction(num*f.den+f.num*den, den*f.den);
	}
	
	fraction operator-(fraction &f)
	{
		return fraction(num*f.den-f.num*den, den*f.den);
	}
	
	fraction operator*(fraction &f)
	{
		return fraction(num*f.num, den*f.den);
	}
	
	fraction operator/(fraction &f)
	{
		return fraction(num*f.den, den*f.num);
	}
};

typedef vector<fraction> VF;

void calc(VF &a, VF &b, VF &out)
{
	for (VF::iterator ita = a.begin(); ita != a.end(); ita++)
	{
		for (VF::iterator itb = b.begin(); itb != b.end(); itb++)
		{
			out.push_back(*ita + *itb);
			out.push_back(*ita - *itb);
			out.push_back(*itb - *ita);
			out.push_back(*ita * *itb);
			out.push_back(*ita / *itb);
			out.push_back(*itb / *ita);
		}
	}
}

void dostep()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	
	VF v1,v2,v3,v4;
	v1.push_back(a);
	v2.push_back(b);
	v3.push_back(c);
	v4.push_back(d);
	
	VF v12;
	calc(v1, v2, v12);
	
	VF v13;
	calc(v1, v3, v13);
	
	VF v14;
	calc(v1, v4, v14);
	
	VF v23;
	calc(v2, v3, v23);
	
	VF v24;
	calc(v2, v4, v24);
	
	VF v34;
	calc(v3, v4, v34);
	
	VF v123;
	calc(v1, v23, v123);
	calc(v2, v13, v123);
	calc(v3, v12, v123);
	
	VF v124;
	calc(v1, v24, v124);
	calc(v2, v14, v124);
	calc(v4, v12, v124);
	
	VF v134;
	calc(v1, v34, v134);
	calc(v3, v14, v134);
	calc(v4, v13, v134);
	
	VF v234;
	calc(v2, v34, v234);
	calc(v3, v24, v234);
	calc(v4, v23, v234);
	
	VF v1234;
	calc(v1, v234, v1234);
	calc(v2, v134, v1234);
	calc(v3, v124, v1234);
	calc(v4, v123, v1234);
	calc(v12, v34, v1234);
	calc(v13, v24, v1234);
	calc(v14, v23, v1234);
	
	for (VF::iterator it = v1234.begin(); it != v1234.end(); it++)
	{
		if (it->is24())
		{
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	
	return 0;
}
