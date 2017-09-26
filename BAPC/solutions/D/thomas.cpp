// Solution to Dreaded Alternating Game
// Author: Thomas Beuman

// Time complexity: O(c)
// Memory: O(c)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: depth-first search with memoization


#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


int P[10000]; // Player in control
vector<int> Adj[10000]; // Places that can be moved to

int W[10000][2]; // Memoization


// Returns the winner given the current place and the parity of the number of moves so far
int winner (int place, int parity)
{ 
  // Check if already calculated
  if (W[place][parity] >= 0)
    return W[place][parity];

  int p = P[place], n = Adj[place].size(), w, i;

  if (n == 0) // No possible move:
    w = parity; // Winner is determined by parity

  else
  { w = 1-p; // By default, winner is opponent
    for (i = 0; i < n; i++)
      if (winner(Adj[place][i], 1-parity) == p) // If move i lets p win...
        w = p; // ...p wins
  }

  // Store and return
  return W[place][parity] = w;
}


int main()
{ int cases, casenr, n, c, s, i, a, b;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d %d %d\n", &n, &c, &s);
    for (i = 0; i < n; i++)
    { scanf("%d\n", &P[i]);
      Adj[i].clear();
    }
    for (i = 0; i < c; i++)
    { scanf("%d %d\n", &a, &b);
      Adj[a-1].push_back(b-1);
    }

    memset(W, -1, sizeof(W));
    printf("%d\n", winner(s-1, 0));
  }
  return 0;
}

