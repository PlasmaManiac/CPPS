using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <sstream>

int main()
{
	string input;
	vector<char> output;


	int testcases;

	cin >> testcases;
	for (; testcases != 0; testcases--)
	{

		cin >> input;
		stringstream out;
		auto list_pos = output.begin();

		for (int i = 0; i < (int)input.size(); i++) {
			char c = (char)input[i];

			switch (c)
			{
			case '-':
				if (output.size() > 0 && list_pos != output.begin())
				{
					if (list_pos == output.end())
						list_pos--;

					list_pos = output.erase(list_pos);
				}
				break;
			case '<':
				if (list_pos != output.begin())
				{
					list_pos--;
				}
				break;
			case '>':
				if (list_pos != output.end())
				{
					list_pos++;
				}
				break;
			default:
			{
					   if (list_pos == output.end())
						   output.push_back(c);
					   else if (list_pos == output.begin())
						   output.insert(list_pos,c);
					   else
					   {
						   list_pos++;
						   list_pos = output.insert(list_pos, c);
					   }
					   break;
			}
			}
		}

		for (char letter : output)
		{
			out << letter;
		}
		cout << out.str() << endl;

		output.clear();
		out.clear();
	}
}


