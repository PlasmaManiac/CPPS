// Solution to Genuine Messages
// Author: Thomas Beuman

// Time complexity: O(n^2)
// Memory: O(n)

// @EXPECTED_RESULTS@: TIMELIMIT
// -> strlen() in loop. Note: some compilers might make this O(n) [= correct]

// Solution method: bookkeeping, but secretly O(n^2)


#include <cstdio>
#include <cstring>
using namespace std;


char Message[100001];
int Freq[26];


int main()
{ int cases, casenr, i, c;
  bool ok;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    scanf("%s\n", Message);
    memset(Freq, 0, sizeof(Freq));
    ok = true;

    // Process the message
    for (i = 0; ok && i < (int)strlen(Message); i++) // strlen is linear!
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

