using namespace std;
#include <iostream>
#include <string>
#include <fstream>

int main()
{
	int testcases;

	cin >> testcases;
	cout << testcases << endl;

	int cities;
	int pilots;


	for (; testcases != 0; testcases--)
	{
		cin >> cities;
		cin >> pilots;

		int lol = 0;
		for (int i = 0; i < pilots; i++){
			cin >> lol;
			cin >> lol;
		}

		cout << cities - 1 << endl;
	}
}