using namespace std;
#include <iostream>
#include <string>

using namespace std;


int main()
{
	int testcases;
	int seq_pos = 0;
	bool win = false;
	string sequence;
	string side1;
	string side2;

	cin >> testcases;
	for (; testcases != 0; testcases--)
	{
		
		cin >> sequence;
		cin >> side1;
		cin >> side2;

		for (int i = 0; i < side1.length(); i++)
		{
			if (side1[i] == sequence[seq_pos] || side2[i] == sequence[seq_pos] || side1[i] == '*'){
				seq_pos++;
				if (seq_pos == sequence.length())
				{
					win = true;
				}
			}
		}

		if (win)
			cout << "win" << endl;
		else
			cout << "lose" << endl;

		seq_pos = 0;
		win = false;
	}
}

