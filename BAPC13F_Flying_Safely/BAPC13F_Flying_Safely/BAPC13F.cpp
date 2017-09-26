using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <queue>

struct city {
	vector<city> adj;
	bool inTree;

	
};

struct city_weight {
	int i, w = 1, p; //index weight and parent index;

};


int main()
{
	int testcases;
	cin >> testcases;

	for (; testcases != 0; testcases--)
	{
		int cities_num = 0;
		int pilots = 0;

		cin >> cities_num;
		cin >> pilots;

		vector<city> cities(cities_num);

		priority_queue<int> test;
		for (int i = 0; i < pilots; i++)
		{
			int start;
			int end;

			cin >> start;
			cin >> end;
		
		}
}