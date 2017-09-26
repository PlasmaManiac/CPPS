using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <tuple>

int main()
{
	int testcases;
	cin >> testcases;

	for (; testcases != 0; testcases--)
	{
		int num_line_seg = 0;
		cin >> num_line_seg;

		int light_x = 0;
		int light_y = 0;

		cin >> light_x;
		cin >> light_y;

		vector<int> begin(num_line_seg);
		vector<int> end(num_line_seg);

		for (int i = 0; i < num_line_seg; i++)
		{
			int x_s = 0;
			int y_s = 0;

			cin >> x_s;
			cin >> y_s;


			double angle = 0;

			if (x_s < light_x){
				double x_dif = x_s - light_x;
				double y_dif = light_y - y_s;
			
				angle = atan(x_dif / y_dif);
				begin.push_back(angle);

			}
			else{

			}


		}
		cout << light_x  << endl;
	}
}