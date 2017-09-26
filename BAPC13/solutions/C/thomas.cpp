// Solution to Cracking the Safe
// Author: Thomas Beuman

// Time complexity: O(1)
// Memory: O(1)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: all possible expressions hard-coded, using fractions


#include <cstdio>
#include <algorithm>
using namespace std;


// Greatest common divisor
int gcd (int a, int b)
{ return b ? gcd(b, a%b) : a;
}

struct fraction
{ int p, q; // fraction = p/q

  fraction (int x, int y = 1)
  { p = x;
    q = y;
    // Reduce fraction
    int d = gcd(p, q);
    if (d != 0)
    { if (q/d < 0)
        d *= -1;
      p /= d;
      q /= d;
    }
  }
};

fraction operator + (fraction A, fraction B)
{ return fraction(A.p*B.q + A.q*B.p, A.q*B.q);
}

fraction operator - (fraction A, fraction B)
{ return fraction(A.p*B.q - A.q*B.p, A.q*B.q);
}

fraction operator * (fraction A, fraction B)
{ return fraction(A.p*B.p, A.q*B.q);
}

fraction operator / (fraction A, fraction B)
{ return fraction(A.p*B.q, A.q*B.p);
}

bool is24 (fraction A)
{ return A.p == 24 && A.q == 1;
}


bool check (fraction a, fraction b, fraction c, fraction d)
{ return
    is24(a+b+c+d) ||
    is24(a+b+c-d) ||
    is24(a*b+c+d) ||
    is24(a*b+c-d) ||
    is24(a*b-c-d) ||
    is24(a*(b+c)+d) ||
    is24(a*(b+c)-d) ||
    is24(a*(b-c)+d) ||
    is24(a*(b-c)-d) ||
    is24(a*(b+c+d)) ||
    is24(a*(b+c-d)) ||
    is24(a*(b-c-d)) ||
    is24((a+b)*(c+d)) ||
    is24((a+b)*(c-d)) ||
    is24((a-b)*(c-d)) ||
    is24(a/b+c+d) ||
    is24(a*b*c+d) ||
    is24(a*b*c-d) ||
    is24(a*(b*c+d)) ||
    is24(a*(b*c-d)) ||
    is24(a*(b-c*d)) ||
    is24(a*b*(c+d)) ||
    is24(a*b*(c-d)) ||
    is24(a*b+c*d) ||
    is24(a*b-c*d) ||
    is24(a*b/c+d) ||
    is24(a*b/c-d) ||
    is24(a*(b/c+d)) ||
    is24(a*(b/c-d)) ||
    is24(a*(b-c/d)) ||
    is24((a*b+c)/d) ||
    is24((a*b-c)/d) ||
    is24(a*b/(c+d)) ||
    is24(a*b/(c-d)) ||
    is24(a*(b+c)/d) ||
    is24(a*(b-c)/d) ||
    is24(a*b+c/d) ||
    is24(a*b-c/d) ||
    is24(a/(b/c-d)) ||
    is24(a/(b-c/d)) ||
    is24(a*b*c*d) ||
    is24(a*b*c/d) ||
    is24(a*b/c/d);
}


int main()
{ int cases, casenr, a, b, c, d;
  bool possible;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    scanf("%d %d %d %d\n", &a, &b, &c, &d);

    // Try all permutations
    possible = check(a,b,c,d) || check(a,b,d,c) || check(a,c,b,d) || check(a,c,d,b) ||
               check(a,d,b,c) || check(a,d,c,b) || check(b,a,c,d) || check(b,a,d,c) ||
               check(b,c,a,d) || check(b,c,d,a) || check(b,d,a,c) || check(b,d,c,a) ||
               check(c,a,b,d) || check(c,a,d,b) || check(c,b,a,d) || check(c,b,d,a) ||
               check(c,d,a,b) || check(c,d,b,a) || check(d,a,b,c) || check(d,a,c,b) ||
               check(d,b,a,c) || check(d,b,c,a) || check(d,c,a,b) || check(d,c,b,a);

    printf("%s\n", possible ? "YES" : "NO");
  }
  return 0;
}

