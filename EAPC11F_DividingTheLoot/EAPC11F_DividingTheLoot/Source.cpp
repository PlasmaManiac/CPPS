using namespace std;
#include <iostream>
#include <string>
#include <fstream>


int main()
{

	int testcases;
	cin >> testcases;
	//cout << testcases << endl;

	int pirates;
	int items;
	int total = 0;

	for (; testcases != 0; testcases--)
	{
		cin >> pirates;
		cin >> items;

		int* values = new int[items];

		for (int i = 0; i != items; i++)
		{
			cin >> values[i];
		}
	
		for (int i = items/ (pirates + 1); i != 0; i--)
		{
			total += values[items - i];
		}

		cout << total;
		total = 0;
	}
}