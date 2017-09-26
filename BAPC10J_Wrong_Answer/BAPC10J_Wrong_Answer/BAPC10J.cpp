using namespace std;
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct word{
	int x;
	int y;
	vector<string> text;
	vector<word> intersections;
};


int main()
{	
	int testcases = 0;

	cin >> testcases;
	for (; testcases != 0; testcases--)
	{
		int horizontal_num = 0;
		int verticle_num = 0;

		cin >> horizontal_num;
		cin >> verticle_num;

		vector<word> horizontals(horizontal_num);
		vector<word> verticles(verticle_num);


		for (int i = 0; i < horizontal_num; i++)
		{
			string input;
			cin >> horizontals[i].x;
			cin >> horizontals[i].y;
			cin >> input;
			horizontals[i].text.push_back(input);
		}

		for (int i = 0; i < verticle_num; i++)
		{
			string input;
			cin >> verticles[i].x;
			cin >> verticles[i].y; 
			cin >> input;
			verticles[i].text.push_back(input);
		}

		for (int i = 0; i < verticle_num; i++)
		{
			for (int j = 0; j < horizontal_num; j++)
			{
				if (verticles[i].x >= horizontals[i].x && verticles[i].x <= (horizontals[i].x + horizontals[i].text.size()))
				{
					verticles[i].intersections.push_back(horizontals[i]);
					horizontals[i].intersections.push_back(verticles[i]);
				}
				else
				{
					
				}
			}
		}


	}
}