// @EXPECTED_RESULTS@: CORRECT
import java.io.*;
import java.util.*;

class jeroenvw
{
	static BufferedReader in;

	public static void main(String[] v) throws IOException
	{
		in = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(in.readLine());
		for (int i=0; i<N; i++) go();
	}

	static void go() throws IOException
	{
		int code = Integer.parseInt(in.readLine());

		// There are less than 32 results: 2**32 > 10**9
		int[] result = new int[32];
		int nresults = 0;

		for (int p=2;p*p<=code;p++) {
			int n = 0;
			while (code%p == 0) {
				n++;
				code /= p;
			}
			if (n==0) continue;

			//System.err.println("" + p + " ^ " + n);

			// code was divisible by p^n
			int twopower = 1<<30;
			while (twopower>0)
			{
				if (n>=twopower)
				{
					result[nresults++] = (int)Math.pow(p, twopower);
					n -= twopower;
				}
				twopower /= 2;
			}
		}
		if (code>1)
			result[nresults++] = code;

		Arrays.sort(result);
		int start = 0;
		while (result[start] == 0) start++;
		for (int i=start; i<result.length-1;i++)
		{
			System.out.print("" + result[i] + " ");
		}
		System.out.println("" + result[result.length-1]);
	}
}
