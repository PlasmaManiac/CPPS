// Solution to Bad Signal
// Author: Thomas Beuman

// Time complexity: O(n^2)
// Memory: O(n)

// @EXPECTED_RESULTS@: TIMELIMIT
// -> Time complexity

// Solution method: check all microphones, compute sum each time


#include <cstdio>
using namespace std;


double R[100000];


int main()
{ int cases, casenr, n, B, px, py, x, y, s, i, j;
  double sum;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input and calculate received signal strengths
    scanf("%d\n%d\n%d %d\n", &n, &B, &px, &py);
    for (i = 0; i < n; i++)
    { scanf("%d %d %d\n", &x, &y, &s);
      R[i] = s / ((double)(x-px)*(x-px) + (double)(y-py)*(y-py));
    }

    // Check for each microphone if it is strong enough
    for (i = 0; i < n; i++)
    { sum = 0;
      for (j = 0; j < n; j++)
        if (j != i)
          sum += R[j];
      if (R[i] > 6 * (B + sum))
        break;
    }

    // Print result
    if (i < n)
      printf("%d\n", i+1);
    else
      printf("NOISE\n");
  }
  return 0;
}

