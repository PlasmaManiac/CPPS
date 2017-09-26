using namespace std;
#include <iostream>
#include <string>
#include <fstream>


int main()
{

	int testcases;
	cin >> testcases;
	//cout << testcases << endl;

	for (; testcases != 0; testcases--)
	{

		int pirates, items, total = 0;

		cin >> pirates;
		cin >> items;
		

		int* values = new int[items];

		for (int i = 0; i != items; i++)
		{
			cin >> values[i];
		}

		for (int i = items / (pirates + 1); i != 0; i--)
		{
			total += values[items - i];
		}

		if (pirates >= items){
			total = 0;
		}
		cout << total;
	}
}