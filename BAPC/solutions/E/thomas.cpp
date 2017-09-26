// Solution to Encryption
// Author: Thomas Beuman

// Time complexity: O(c*n*log(n))
// Memory: O(c*n)
// (c = #chars/word)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: map
//   Make a map from the second key to the ciphertext,
//   apply it to the first key


#include <cstdio>
#include <string>
#include <map>
using namespace std;


string Key1[1000], Key2[1000], Ciphertext[1000];
map<string,string> M;


// Reads a sentence, splits it into words
void readsentence (int n, string S[])
{ int i;
  char word[11];
  for (i = 0; i < n; i++)
  { scanf("%s", word);
    S[i] = word;
  }
}


int main()
{ int cases, casenr, n, i;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d\n", &n);
    readsentence(n, Key1);
    readsentence(n, Key2);
    readsentence(n, Ciphertext);

    // Build map
    M.clear();
    for (i = 0; i < n; i++)
      M[Key2[i]] = Ciphertext[i];

    // Translate and print
    for (i = 0; i < n; i++)
      printf("%s%c", M[Key1[i]].c_str(), i < n-1 ? ' ' : '\n');
  }
  return 0;
}

