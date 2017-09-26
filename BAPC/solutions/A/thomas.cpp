// Solution to Area Coverage
// Author: Thomas Beuman

// Time complexity: O(n^2 * log(n))
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: line-sweep


#include <cstdio>
#include <algorithm>
using namespace std;


const int N = 1000;

int X1[N], Y1[N], X2[N], Y2[N];
int Y[2*N], L[N], R[N];


int main()
{ int cases, casenr, n, i, k, m, j, leftbound = 0;
  long long A;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
      scanf("%d %d %d %d\n", &X1[i], &Y1[i], &X2[i], &Y2[i]);

    // Gather all y-coordinates and sort them
    for (i = 0; i < n; i++)
    { Y[2*i] = Y1[i];
      Y[2*i+1] = Y2[i];
    }
    sort(Y, Y+2*n);

    A = 0;
    // Loop over all blocks of horizontal lines between two consecutive y-coordinates
    for (k = 0; k < 2*n-1; k++)
    { 
      // Determine all photos in range
      m = 0;
      for (i = 0; i < n; i++)
        if (Y[k] >= Y1[i] && Y[k] < Y2[i])
        { L[m] = X1[i]; // Left side of photo
          R[m] = X2[i]; // Right side of photo
          m++;
        }

      // Sort all coordinates
      sort(L, L+m);
      sort(R, R+m);

      // Scan from left to right
      for (i = j = 0; j < m;)
      { 
        if (i < m && L[i] < R[j]) // Next coordinate is left side of new photo
        { if (i == j) // Nothing currently in view
            leftbound = L[i]; // Establish new boundary
          i++;
        }

        else // Next coordinate is right side of old photo
        { j++;
          if (i == j) // Nothing in view anymore
            A += (long long)(Y[k+1] - Y[k]) * (R[j-1] - leftbound); // Add to area
        }
      }
    }

    // Print result
    printf("%lld\n", A);
  }
  return 0;
}

