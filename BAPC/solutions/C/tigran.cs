// @EXPECTED_RESULTS@: CORRECT
/*
 *  By: Tigran
 *  Method: Try all combinations using floats
 */

using System;
using System.Collections.Generic;
using System.Linq;

class TwentyFour
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        while (n-- > 0)
        {
            string[] s = Console.ReadLine().Split();

            Console.WriteLine(
                Solve(new List<float>() {int.Parse(s[0]), int.Parse(s[1]), int.Parse(s[2]), int.Parse(s[3])})
                    ? "YES"
                    : "NO");
        }
    }

    // Try out all permutations
    static bool Solve(List<float> l)
    {
        for (int a = 0; a < 4; a++)
            for (int b = 0; b < 4; b++)
                for (int c = 0; c < 4; c++)
                    for (int d = 0; d < 4; d++)
                        if (a != b && a != c && a != d && b != c && b != d && c != d)
                            if (IsTwentyFour(l[a], l[b], l[c], l[d]))
                                return true;
        return false;
    }

    // Realise that the possible cases are: ((a.b).c).d or (a.b).(c.d) with the . as any possible operator.
    static bool IsTwentyFour(float a, float b, float c, float d)
    {
        var aa = new List<float> { a };
        var bb = new List<float> { b };
        var cc = new List<float> { c };
        var dd = new List<float> { d };

        var results = PerfOp(PerfOp(PerfOp(aa, bb), cc), dd);           // ((a.b).c).d case
        if (results.Any(result => Math.Abs(result - 24) < 0.1f))
            return true;

        results = PerfOp(PerfOp(aa, bb), PerfOp(cc, dd));               // (a.b).(c.d) case
        return results.Any(result => Math.Abs(result - 24) < 0.1f);
    }

    static List<float> PerfOp(List<float> a, List<float> b)
    {
        var result = new List<float>();
        foreach (var aa in a)
            foreach (var bb in b)
            {
                result.Add(aa + bb);
                result.Add(aa - bb);
                result.Add(bb - aa);
                result.Add(aa * bb);
                if (bb != 0) result.Add(aa / bb);
                if (aa != 0) result.Add(bb / aa);
            }
        return result;
    }
}
