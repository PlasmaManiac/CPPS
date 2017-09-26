using namespace std;
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

int main()
{
	double input;
	double output;
	int testcases;
	cin >> testcases;

	for (; testcases != 0; testcases--)
	{
		cin >> input;

		if (input > 180)
		{
			input -= 180;
		}

		output = round(input / 10);
		if (output == 0)
		{
			cout << 18 << endl;
			continue;
		}
		else if (output < 10)
			cout << '0' << output << endl;
		else
			cout << output << endl;
	}

}

void read_from_file(const string& filename)
{
	string word;
	ifstream fp;

	// Open the file
	fp.open(filename, ios::in);
	if (!fp.is_open()) {
		cerr << "Cannot open file \"" << filename << "\"" << endl;
		return;
	}

	cout << "Reading file \"" << filename << "\"" << endl;

	cout << word << endl;
	// Continue until the end of file
	while (!fp.eof()) {
		fp >> word;
		if (!fp.eof()) { // prevent last line twice
			cout << word;
		}
	}

	// Close the file
	fp.close();
}