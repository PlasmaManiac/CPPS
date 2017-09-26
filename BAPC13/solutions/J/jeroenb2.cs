/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;

public class jeroenb
{
	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			string[] parts = Console.ReadLine().Split();
			int n = int.Parse(parts[0]);
			int e = int.Parse(parts[1]);
			int[] S = new int[n];
			parts = Console.ReadLine().Split();
			for(int i = 0; i < n; i++)
				S[i] = int.Parse(parts[i]);

			int sum = 0;
			for (int i = 0; i < n; i++)
				sum += S[i] * 2;

			if (sum < e)
			{
				Console.WriteLine("FULL");
				continue;
			}

			int[,] dp = new int[2,e+1];
			for(int i = 0; i < 2; i++)
				for (int j = 0; j <= e; j++)
					dp[i,j] = int.MaxValue / 3;
			dp[0, e] = 0;
			for(int i = 0; i < n; i++)
			{
				for (int j = 0; j <= e; j++)
				{
					dp[(i&1)^1,j] = Math.Min(dp[(i&1)^1,j], dp[i&1,j]);
					int r = Math.Max(j - S[i] * 2, 0);
					dp[(i&1)^1,r] = Math.Min(dp[(i&1)^1,r], dp[i&1,j] + S[i]);
				}
				for(int j = 0; j <= e; j++)
					dp[i&1,j] = int.MaxValue / 3;
			}
			Console.WriteLine(dp[n&1,0]);
		}
	}
}