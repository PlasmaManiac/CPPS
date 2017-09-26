// Solution to How Much?
// Author: Thomas Beuman

// Time complexity: O(n)
// Memory: O(1)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: multiply and add

#include <stdio.h>

int main()
{ int cases, casenr, cost, s, n, i, m, p;
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { scanf("%d\n%d\n", &s, &n);
    cost = s;
    for (i = 0; i < n; i++)
    { scanf("%d %d\n", &m, &p);
      cost += m * p;
    }
    printf("%d\n", cost);
  }
  return 0;
}

