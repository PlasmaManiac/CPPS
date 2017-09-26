// Solution to Cracking the Safe
// Author: Thomas Beuman

// Time complexity: O(1)
// Memory: O(1)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: try all permutations and operations, using doubles


#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;


const double eps = 1e-6;


bool is24 (double x)
{ return fabs(x-24) < eps;
}

// Performs an operation
double op (double x, double y, int type)
{ switch (type)
  { case 0 : return x+y;
    case 1 : return x-y;
    case 2 : return y-x;
    case 3 : return x*y;
    case 4 : return fabs(y) < eps ? 1e9 : x/y;
    case 5 : return fabs(x) < eps ? 1e9 : y/x;
  }
  return 0; // To keep compiler happy
}

// Try all combinations of operations
bool check (double a, double b, double c, double d)
{ int t1, t2, t3; // The three types of operators
  for (t1 = 0; t1 < 6; t1++)
    for (t2 = 0; t2 < 6; t2++)
      for (t3 = 0; t3 < 6; t3++)
        if (is24(op(op(op(a, b, t1), c, t2), d, t3)) ||  // ((a.b).c).d
            is24(op(op(a, b, t1), op(c, d, t2), t3)))    // (a.b).(c.d)
          return true;
  return false;
}


int main()
{ int cases, casenr, Q[4];
  bool possible;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    scanf("%d %d %d %d\n", &Q[0], &Q[1], &Q[2], &Q[3]);

    // Try all permutations of the four numbers
    sort(Q, Q+4);
    possible = false;
    do
      possible |= check(Q[0], Q[1], Q[2], Q[3]);
    while (next_permutation(Q, Q+4));

    printf("%s\n", possible ? "YES" : "NO");
  }
  return 0;
}

