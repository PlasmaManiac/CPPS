using namespace std;
#include <iostream>
#include <string>
#include <math.h>

int main()
{
	int amountMessages;
	cin >> amountMessages;

	for (amountMessages; amountMessages > 0; amountMessages--)
	{
		string message; 
		string newmesage;
		cin >> message;
		newmesage = message; // necessary?

		int length = message.length();
		int rotation = sqrt(length);


		for (int row = 0; row < rotation; row++)
		{
			for (int column = 0; column < rotation; column++)
			{
				newmesage[row + rotation*(rotation-1 -column)] = message[column + row*rotation];
			}
		}
		cout << newmesage << endl;
	}
}