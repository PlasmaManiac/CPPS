// Solution to Fare Dodging
// Author: Thomas Beuman

// Time complexity: O(n^3)
// Memory: O(n^2)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: dijkstra (without heap) with vertices doubled


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 400;
const double inf = 1e9; // "infinity"

double Cost[N][N]; // Adjacency matrix
double E[N]; // Expected cost to reach each vertex
bool Seen[N];


int main()
{ int cases, casenr, n, m, start, end, s, p, y, a, b, c, d, i, j;
  double best;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d %d %d %d %d %d %d\n", &n, &m, &start, &end, &s, &p, &y);
    start--; end--;

    // Initialize all costs to inf
    for (i = 0; i < 2*n; i++)
      for (j = 0; j < 2*n; j++)
        Cost[i][j] = 1e9;

    // Double the vertices: one (i) for not having paid the start up cost,
    //                      one (i+n) for having paid it
    for (i = 0; i < n; i++)
    { Cost[i][i+n] = s; // Paying the start up cost
      Cost[i+n][i] = 0;
    }

    // Read and process connections
    for (i = 0; i < m; i++)
    { scanf("%d %d %d %d\n", &a, &b, &c, &d);
      a--; b--;
      Cost[a][b] = Cost[b][a] = c/100.0 * (y + p*d); // Traveling without ticket
      Cost[a+n][b+n] = Cost[b+n][a+n] = p*d; // Traveling with ticket
    }

    n *= 2;
    // Initialize the expected costs ("distances")
    for (i = 0; i < n; i++)
      E[i] = 1e9;
    memset(Seen, false, sizeof(Seen));
    E[start] = 0;

    while (true)
    { 
      // Look for unprocessed vertex with lowest expected cost
      i = -1;
      best = 1e9;
      for (j = 0; j < n; j++)
        if (!Seen[j] && E[j] < best)
          best = E[i = j];

      if (i == end) // Reached the end; we can stop
        break;

      Seen[i] = true;

      // Update all the neighboring vertices
      for (j = 0; j < n; j++)
        if (Cost[i][j] < 1e9 && E[i] + Cost[i][j] < E[j])
          E[j] = E[i] + Cost[i][j];
    }

    // Print result
    printf("%.2lf\n", E[end]);
  }
  return 0;
}

