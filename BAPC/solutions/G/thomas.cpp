// Solution to Genuine Messages
// Author: Thomas Beuman

// Time complexity: O(n)
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: bookkeeping


#include <cstdio>
#include <cstring>
using namespace std;


char Message[100001];
int Freq[26];


int main()
{ int cases, casenr, n, i, c;
  bool ok;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    scanf("%s\n", Message);
    memset(Freq, 0, sizeof(Freq));
    ok = true;

    // Process the message
    n = strlen(Message);
    for (i = 0; ok && i < n; i++)
    { 
      c = Message[i] - 'A'; // Convert to integer 0-25
      Freq[c]++;

      if (Freq[c] == 3) // If seen for the third time
      { if (Message[i+1] != Message[i]) // Check if the next character is the same
          ok = false;
        i++; // Ignore this next character
        Freq[c] = 0;
      }
    }

    printf("%s\n", ok ? "OK" : "FAKE");
  }
  return 0;
}

