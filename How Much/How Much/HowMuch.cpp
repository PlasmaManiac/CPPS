using namespace std;

#include <iostream>
struct car{
	int price = 0;

	int numberofparts = 0;
	int parts_sum = 0;
};

int main()
{
	int testcases;

	for (cin >> testcases; testcases > 0; testcases--)
	{
		car currentcar;
		cin >> currentcar.price;
		cin >> currentcar.numberofparts;
		for (int count = currentcar.numberofparts; count > 0; count--)
		{
			int amount;
			cin >> amount;
			int price;
			cin >> price;

			currentcar.parts_sum += amount * price;
		}

		cout << currentcar.parts_sum + currentcar.price << endl;
	}
}
