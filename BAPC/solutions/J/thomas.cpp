// Solution to Just Enough Space
// Author: Thomas Beuman

// Time complexity: O(n^2 * Smax)
// Memory: O(n * Smax)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: dynamic programming


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int inf = 0x7fffffff; // "Infinity"

int S[100];
bool Possible[200000];


int main()
{ int cases, casenr, n, e, i, toconvert, best, s;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d %d\n", &n, &e);
    for (i = 0; i < n; i++)
      scanf("%d", &S[i]);

    toconvert = (e+1)/2; // (The +1 is for rounding up)

    if (toconvert == 0)
    { printf("0\n");
      continue;
    }
    if (toconvert > 2000*n) // More needs to be converted than could possibly be available
    { printf("FULL\n");
      continue;
    }
    
    memset(Possible, false, sizeof(Possible));
    Possible[0] = true;
    best = inf;

    // Dynamic programming:
    // Keep track of all total amounts of disk space that are possible
    for (i = 0; i < n; i++)
    { for (s = toconvert-1; s >= 0; s--)
        if (Possible[s])
        { if (s + S[i] < toconvert)
            Possible[s + S[i]] = true;
          else
            best = min(best, s + S[i]);
        }
    }

    // Print result
    if (best == inf)
      printf("FULL\n");
    else
      printf("%d\n", best);
  }
  return 0;
}

