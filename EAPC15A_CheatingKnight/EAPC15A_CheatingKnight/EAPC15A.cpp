using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

int main()
{
	int testcases;
	cin >> testcases;

	for (; testcases != 0; testcases--)
	{
		signed long long int jump = 0;

		cin >> jump;

		signed long long int x = 0;
		signed long long int y = 0;

		cin >> x;
		cin >> y;
		
		x = pow(x, 2.0);
		y = pow(y, 2.0); // square the x and y
		

		signed long long int distance = x + y;
		
		int num_jumps = 0;

		if (distance == 0)
		{
			num_jumps = 0;
		}
		else if (distance < jump )
		{
			num_jumps = 2;
		}
		else
		{
			num_jumps = (int) ceil(sqrt(distance / jump));
			//D = JUMP
			// distance = unSqrtDist
			if ((sqrt(distance) - num_jumps*sqrt(jump)) > 0.0 && ((distance % (num_jumps*jump)) != 0)) num_jumps += 1;
		}
		cout << num_jumps << endl;
	}
}