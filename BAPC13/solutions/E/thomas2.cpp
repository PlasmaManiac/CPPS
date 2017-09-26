// Solution to Encryption
// Author: Thomas Beuman

// Time complexity: O(c*n^2)
// Memory: O(c*n)
// (c = #chars/word)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: determine the permutation, then apply it to the ciphertext
// (Deliberately inefficient)


#include <cstdio>
#include <cstring>
using namespace std;


char Key1[1000][11], Key2[1000][11], Ciphertext[1000][11];
int Perm[1000];


// Reads a sentence, splits it into words
void readsentence (char S[][11])
{ int n = 0, i = 0;
  char c = ' ';
  while (c != '\n')
  { scanf("%c", &c);
    if (c == ' ' || c == '\n')
    { S[n][i] = '\0';
      n++;
      i = 0;
    }
    else
      S[n][i++] = c;
  }
}

// Checks whether two strings are equal (like strcmp)
bool equal (char A[], char B[])
{ int i;
  for (i = 0; true; i++)
  { if (A[i] != B[i])
      return false;
    if (A[i] == '\0')
      return true;
  }
}


int main()
{ int cases, casenr, n, i, j;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d\n", &n);
    readsentence(Key1);
    readsentence(Key2);
    readsentence(Ciphertext);

    // Determine permutation
    for (i = 0; i < n; i++)
    { for (j = 0; !equal(Key1[i], Key2[j]); j++); // Find match
      Perm[i] = j;
    }

    // Apply permutation and print
    for (i = 0; i < n; i++)
    { if (i > 0)
        printf(" ");
      for (j = 0; Ciphertext[Perm[i]][j] != '\0'; j++)
        printf("%c", Ciphertext[Perm[i]][j]);
    }
    printf("\n");
  }
  return 0;
}

