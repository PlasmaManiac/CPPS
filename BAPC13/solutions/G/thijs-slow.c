// @EXPECTED_RESULTS@: TIMELIMIT
// -> O(n^2) due to strlen() in loop. Note: might be optimised to O(n) (= correct) on some compilers

#include <stdio.h>
#include <string.h>

char str[100005];

void doStep()
{
	int ok = 1;
	char count[26] = {0};
	scanf("%s", str);
	int i;
	// O(n^2) due to strlen() inside the loop
	for (i=0; i<strlen(str); i++)
	{
		int idx = str[i]-'A'; 
		count[idx]++;
		if (count[idx] == 3)
		{
			if (str[i+1] != str[i])
				ok = 0;
			count[idx] = -1;
		}
	}
	if (ok)
		printf("OK\n");
	else
		printf("FAKE\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--) doStep();
	return 0;
}
