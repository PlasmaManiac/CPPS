/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;

public class jeroenvw2
{
	public static void Main(string[] args)
	{
		int N = int.Parse(Console.ReadLine());
		for (int i=0;i<N;i++) go();
	}
	static void go()
	{
		string[] parts = Console.ReadLine().Split();
		int n = int.Parse(parts[0]);
		int e = int.Parse(parts[1]);
		int[] setsizes = new int[n];
		parts = Console.ReadLine().Split();
		for (int i = 0; i < n; i++)
			setsizes[i] = int.Parse(parts[i]);

		bool[] possible = new bool[4000*102];
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
		for (int i=e;i<possible.Length;i++)
		{
			if (possible[i])
			{
				// To convert is half the savings
				Console.WriteLine(i/2);
				return;
			}
		}

		Console.WriteLine("FULL");
	}
}
