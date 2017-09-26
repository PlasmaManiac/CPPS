// Solution to Identification Codes
// Author: Thomas Beuman

// Time complexity:
// - O(10^9 * log(10^9))  (precalculation)
// - O(5*10^7)  (per test case)
// Memory: O(10^9)

// @EXPECTED_RESULTS@: TIMELIMIT

// Solution method:
// - Precalculate all SICs using a prime sieve
// - For every test case: traverse through the list


#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;


const int M = 1<<30;
const int Mroot = 1<<15;

char Prime[M>>3];
int AllCodes[51000000];

int SIC[99];


bool prime (int n)
{ return Prime[n>>3] & (1 << (n&7));
}


int main()
{ 
  int cases, casenr, s, i, j, c, n;


  /*** Precalculation (prime sieve) ***/

  // Initialize even numbers to false, odd to true (170 = 10101010)
  memset(Prime, 170, sizeof(Prime));
  Prime[0] = 172; // 2 is prime, 1 is not (172 = 10101100)
  s = 0;

  // Special case: p = 2
  for (i = 1; i < 32; i *= 2)
    AllCodes[s++] = 1<<i; // Add 2^i

  for (i = 3; i < Mroot; i += 2)
    if (prime(i))
    { 
      // Set all multiples of i to false
      for (j = i*i; j < M; j += 2*i)
        Prime[j>>3] &= ~(1 << (j&7));

      // Add all powers i^(2^k) to list
      for (j = i; true; j *= j)
      { AllCodes[s++] = j;
        if (j > Mroot)
          break;
      }
    }

  // Add all remaining prime numbers
  for (i = Mroot + 1; i < M; i += 2)
    if (prime(i))
      AllCodes[s++] = i;


  /*** Process test cases ***/

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    scanf("%d\n", &c);
    n = 0; // Number of SICs
    
    // Traverse through the list backwards
    for (i = s-1; i >= 0; i--)
      if (c % AllCodes[i] == 0)
      { SIC[n++] = AllCodes[i];
        c /= AllCodes[i];
      }

    // Sort the SICs and print
    sort(SIC, SIC+n);
    for (i = 0; i < n; i++)
      printf("%d%c", SIC[i], i < n-1 ? ' ' : '\n');
  }
  return 0;
}

