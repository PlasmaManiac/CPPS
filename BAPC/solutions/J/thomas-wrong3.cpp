// Solution to Just Enough Space
// Author: Thomas Beuman

// Time complexity: O(10^7) (can be adjusted manually)
// Memory: O(n)

// @EXPECTED_RESULTS@: WRONG-ANSWER

// Solution method: random


#include <cstdio>
#include <cstring>
using namespace std;


const int inf = 0x7fffffff; // "Infinity"
const int N = 10000000; // Number of iterations


int S[100];
bool Converted[100];


int rseed = 42;
int randnr()
{ return rseed = (16807ll * rseed) % 2147483647;
}


int main()
{ int cases, casenr, n, e, i, toconvert, best, s, k;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d %d\n", &n, &e);
    for (i = 0; i < n; i++)
      scanf("%d", &S[i]);

    toconvert = (e+1)/2; // (The +1 is for rounding up)
    s = 0;
    for (i = 0; i < n; i++)
      s += S[i];

    if (toconvert == 0)
    { printf("0\n");
      continue;
    }
    if (toconvert > s) // More needs to be converted than is available
    { printf("FULL\n");
      continue;
    }

    memset(Converted, false, sizeof(Converted));
    best = inf;
    s = 0;

    for (i = 0; i < N && best > toconvert; i++)
    { k = randnr() % n; // Take a random set

      // Convert (if we don't have enough space yet)
      if (!Converted[k] && s < toconvert)
      { Converted[k] = true;
        s += S[k];
      }

      // Revert (if we have more than enough space)
      else if (Converted[k] && s > toconvert)
      { Converted[k] = false;
        s -= S[k];
      }

      // Check if this solution is better
      if (s >= toconvert && s < best)
        best = s;
    }

    printf("%d\n", best);
  }
  return 0;
}

