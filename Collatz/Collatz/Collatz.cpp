using namespace std;
#include <iostream>
#include <string>
#include <math.h>

int main()
{
	int input;
	int output;
	int testcases;
	cin >> testcases;
	int validcases = 0;


	for (; testcases != 0; testcases--)
	{
		cin >> input;
		if (input % 2 == 0)
		{

			output = input - ceil((floor((input - 1) / 3)) / 2);

		}
		else
		{
			validcases = ceil((floor((input - 1) / 3)) / 2);
			output = input + 1 - validcases;
		}

		cout << output << endl;

	}
}