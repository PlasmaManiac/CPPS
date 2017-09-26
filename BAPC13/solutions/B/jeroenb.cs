/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Collections.Generic;

public class jeroenb
{
	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		while (tests-- > 0)
		{
			int n = int.Parse(Console.ReadLine());
			int N = int.Parse(Console.ReadLine());
			string[] parts = Console.ReadLine().Split();
			int xp = int.Parse(parts[0]);
			int yp = int.Parse(parts[1]);
			int[] x = new int[n];
			int[] y = new int[n];
			int[] s = new int[n];
			for (int i = 0; i < n; i++)
			{
				parts = Console.ReadLine().Split();
				x[i] = int.Parse(parts[0]);
				y[i] = int.Parse(parts[1]);
				s[i] = int.Parse(parts[2]);
			}

			double sum = 0;
			double[] r = new double[n];
			for (int i = 0; i < n; i++)
			{
				r[i] = s[i] / (double)((double)(x[i] - xp) * (x[i] - xp) + (double)(y[i] - yp) * (y[i] - yp));
				sum += r[i];
			}

			bool found = false;
			for (int i = 0; !found && i < n; i++)
			{
				if (r[i] > 6 * (N + sum - r[i]))
				{
					Console.WriteLine(i + 1);
					found = true;
				}
			}
			if (!found) Console.WriteLine("NOISE");
		}
	}
}
