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

			int[] dp = new int[e+1];
			for(int i = 0; i <= e; i++)
				dp[i] = int.MaxValue / 3;
			dp[e] = 0;
			for(int i = 0; i < n; i++)
			{
				for (int j = 0; j <= e; j++)
				{
					int r = Math.Max(j - S[i] * 2, 0);
					dp[r] = Math.Min(dp[r], dp[j] + S[i]);
				}
			}
			Console.WriteLine(dp[0]);
		}
	}
}