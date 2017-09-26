using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int cost(int i, int j, vector<int>* v){

	int cost = 0;
	//j++;

	for (; j < i; j++)
	{
		cost += (*v)[j] * (i - j);
	}

	if (!(i == v->size() - 1))
	{
		for (; i < v->size(); i++)
		{
			cost += (*v)[i];
		}
	}

	return cost;
}

int main()
{
	int testcases;
	cin >> testcases;
	int floors = 0;
	
	
	for (; testcases != 0; testcases--)
	{
		cin >> floors;
		vector<int> costs(floors + 1);

		for (int i = 0; i < costs.size() - 1; i++)
		{
			costs[i] = 0;
		}

		vector<int> people(floors + 1);
		people[0] = 0;

		for (int i = 1; i <= floors; i++)
		{
			cin >> people[i];
		}

		int min = INT_MAX;
		for (int i = 1; i <= floors; i++)
		{
			min = INT_MAX;
			for (int j = 0; j < i; j++)
			{
				int cost_ij = cost(i, j, &people);

				if (cost_ij < min){
					min = cost_ij;
				}
			}
			costs[i] = min;
		}

		cout << costs[floors];
	}
}

