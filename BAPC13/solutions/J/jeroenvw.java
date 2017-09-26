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
		StringTokenizer st = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(in.readLine());
		int[] setsizes = new int[n];
		for (int i=0;i<n;i++) setsizes[i] = Integer.parseInt(st.nextToken());

		// At most 4000 savings per set, 100 sets
		// Note: intentionally DP'ing up until the max savings, not stopping
		// (for example) at e+4000 here.
		boolean[] possible = new boolean[4000*102];
		possible[0] = true;
		for (int i=0;i<n;i++)
		{
			for (int j=4000*100;j>=0;j--)
			{
				if (possible[j])
					possible[j+2*setsizes[i]] = true;
			}
		}
		
		// Now find the best
		for (int i=e;i<possible.length;i++)
		{
			if (possible[i])
			{
				// To convert is half the savings
				System.out.println("" + i/2);
				return;
			}
		}

		System.out.println("FULL");
	}
}
