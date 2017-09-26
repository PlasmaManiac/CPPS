// Solution to Just Enough Space
// Author: Thomas Beuman

// Time complexity: O(n^2 * Smax)
// Memory: O(n^2 * Smax)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: depth-first search with memoization


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int inf = 0x7fffffff; // "Infinity"

int S[100];
bool Possible[101][200000];


// Finds the best solution given the first m sets
int dfs (int m, int s, int toconvert)
{ if (s >= toconvert) // Quotum met
    return s;
  if (m == 0 || Possible[m][s]) // No sets left or already processed
    return inf;
  Possible[m][s] = true; // Mark as processed

  // Try converting and not converting set m; return the best solution
  return min(dfs(m-1, s, toconvert), dfs(m-1, s + S[m-1], toconvert));
}

int main()
{ int cases, casenr, n, e, i, toconvert, best;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d %d\n", &n, &e);
    for (i = 0; i < n; i++)
      scanf("%d", &S[i]);

    toconvert = (e+1)/2; // (The +1 is for rounding up)
    if (toconvert > 2000*n) // More needs to be converted than could possibly be available
      best = inf;
    else
    { memset(Possible, false, sizeof(Possible));
      best = dfs(n, 0, toconvert);
    }

    // Print result
    if (best == inf)
      printf("FULL\n");
    else
      printf("%d\n", best);
  }
  return 0;
}

