using namespace std;
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct pos{
	int x;
	int y;
	bool hit;
};


bool collision(pos mos, pos swat){
	if ((swat.x - 50 <= mos.x && swat.x + 50 >= mos.x) && (swat.y - 50 <= mos.y && swat.y + 50 >= mos.y)) {
		return !mos.hit;
	}
}

int main()
{
	int testcases;
	cin >> testcases;

	for (; testcases != 0; testcases--)
	{
		int mos = 0;
		cin >> mos;
		vector<pos> mosquittos(mos);

		for (int i = 0; i < mos; i++)
		{
			cin >> mosquittos[i].x;
			cin >> mosquittos[i].y;
		}

		int swat = 0;
		cin >> swat;
		vector<pos> swats(swat);

		for (int i = 0; i < swat; i++)
		{
			cin >> swats[i].x;
			cin >> swats[i].y;
		}

		int count = 0;

		for (int j = 0; j < swat; j++){
			for (int i = 0; i < mos; i++){
				if (   (swats[j].x - 50 <= mosquittos[i].x && swats[j].x + 50 >= mosquittos[i].x) 
					&& (swats[j].y - 50 <= mosquittos[i].y && swats[j].y + 50 >= mosquittos[i].y)
					&& !mosquittos[i].hit) {
					count++; 
					mosquittos[i].hit = true;
				}
			}
		}
		cout << count << endl;
	}
}
