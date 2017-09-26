using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	int testcases;
	cin >> testcases;

	for (; testcases != 0; testcases--)
	{
		int length = 0;
		cin >> length;
		vector<int> nums(length);

		for (int i = 0; i < length; i++)
		{
			cin >> nums[i];
		}

		double max_so_far = 0;
		double max_ending_here = 0;
		int max_start_index = 0;
		int startIndex = 0;
		int max_end_index = -1;

		for (int i = 0; i < length; i++) {
			if (0 > max_ending_here +nums[i]) {
				startIndex = i + 1;
				max_ending_here = 0;
			}
			else {
				max_ending_here += nums[i];
			}

			if (max_ending_here > max_so_far) {
				max_so_far = max_ending_here;
				max_start_index = startIndex;
				max_end_index = i;
			}
		}

		cout << max_start_index + 1 << " " << max_end_index + 1;
	}
}