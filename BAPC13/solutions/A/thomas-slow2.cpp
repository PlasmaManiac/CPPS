// Solution to Area Coverage
// Author: Thomas Beuman

// Time complexity: O(2^n)
// Memory: O(n)

// @EXPECTED_RESULTS@: TIMELIMIT

// Solution method: inclusion-exclusion


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 1000;
const int L = 1000000;

int X1[N], Y1[N], X2[N], Y2[N];

bool Ignore[N];


long long inclexcl (int n, int sign, int x1, int x2, int y1, int y2)
{ if (n == 0)
    return 0;
  if (Ignore[n-1])
    return inclexcl(n-1, sign, x1, x2, y1, y2);
  long long A = inclexcl(n-1, sign, x1, x2, y1, y2);
  x1 = max(x1, X1[n-1]);
  x2 = min(x2, X2[n-1]);
  y1 = max(y1, Y1[n-1]);
  y2 = min(y2, Y2[n-1]);
  if (x1 < x2 && y1 < y2)
    A += sign * (long long)(x2-x1) * (y2-y1) + inclexcl(n-1, -sign, x1, x2, y1, y2);
  return A;
}


int main()
{ int cases, casenr, n, i, j;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
      scanf("%d %d %d %d\n", &X1[i], &Y1[i], &X2[i], &Y2[i]);

    // Look for photos completely covered by another photo and ignore them
    memset(Ignore, false, sizeof(Ignore));
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if ((i < j || !(X1[i] == X1[j] && X2[i] == X2[j] && Y1[i] == Y1[j] && Y2[i] == Y2[j])) &&
            X1[i] <= X1[j] && X2[i] >= X2[j] && Y1[i] <= Y1[j] && Y2[i] >= Y2[j])
          Ignore[j] = true;

    // Print result
    printf("%lld\n", inclexcl(n, 1, 0, L, 0, L));
  }
  return 0;
}

