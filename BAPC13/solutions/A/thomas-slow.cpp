// Solution to Area Coverage
// Author: Thomas Beuman

// Time complexity: O(xmax * n)
// Memory: O(n)

// @EXPECTED_RESULTS@: TIMELIMIT

// Solution method: line-sweep, but processing all lines individually


#include <cstdio>
#include <algorithm>
using namespace std;


const int N = 1000;

int X1[N], Y1[N], X2[N], Y2[N];

int X1sorted[N], X2sorted[N];
int Y1sortedbyX1[N], Y2sortedbyX1[N], Y1sortedbyX2[N], Y2sortedbyX2[N];


// Sorts A, B and C according to A (using good ol' bubblesort)
void mysort (int A[], int B[], int C[], int n)
{ int i, j;
  for (i = 0; i < n; i++)
    for (j = i+1; j < n; j++)
      if (A[i] > A[j])
      { swap(A[i], A[j]);
        swap(B[i], B[j]);
        swap(C[i], C[j]);
      }
}


int main()
{ int cases, casenr, n, i, ymin, ymax, y, j, view, leftbound;
  long long A;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
      scanf("%d %d %d %d\n", &X1[i], &Y1[i], &X2[i], &Y2[i]);

    // Sort all coordinates by X1 and X2
    for (i = 0; i < n; i++)
    { X1sorted[i] = X1[i];
      X2sorted[i] = X2[i];
      Y1sortedbyX1[i] = Y1sortedbyX2[i] = Y1[i];
      Y2sortedbyX1[i] = Y2sortedbyX2[i] = Y2[i];
    }
    mysort(X1sorted, Y1sortedbyX1, Y2sortedbyX1, n);
    mysort(X2sorted, Y1sortedbyX2, Y2sortedbyX2, n);

    // Determine smallest and largest y-coordinate
    ymin = 1000000;
    ymax = 0;
    for (i = 0; i < n; i++)
    { ymin = min(ymin, Y1[i]);
      ymax = max(ymax, Y2[i]);
    }

    A = 0;
    // Loop over all horizontal lines
    for (y = ymin; y < ymax; y++)
    { 
      view = 0; // Number of photos currently in view
      leftbound = 0; // Initialized to keep compiler happy

      // Look for first coordinate in range
      for (i = 0; i < n && !(Y1sortedbyX1[i] <= y && y < Y2sortedbyX1[i]); i++);
      for (j = 0; j < n && !(Y1sortedbyX2[j] <= y && y < Y2sortedbyX2[j]); j++);

      // Scan from left to right
      while (j < n)
      { 
        if (i < n && X1sorted[i] < X2sorted[j]) // Next coordinate is left side of new photo
        { if (view == 0) // Nothing currently in view
            leftbound = X1sorted[i]; // Establish new boundary
          view++;
          // Look for next left coordinate in range
          for (i++; i < n && !(Y1sortedbyX1[i] <= y && y < Y2sortedbyX1[i]); i++);
        }

        else // Next coordinate is right side of old photo
        { view--;
          if (view == 0) // Nothing in view anymore
            A += X2sorted[j] - leftbound; // Add to area
          // Look for next right coordinate in range
          for (j++; j < n && !(Y1sortedbyX2[j] <= y && y < Y2sortedbyX2[j]); j++);
        }
      }
    }

    // Print result
    printf("%lld\n", A);
  }
  return 0;
}

