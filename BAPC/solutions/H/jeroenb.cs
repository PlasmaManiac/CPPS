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
		while(tests-- > 0)
		{
			int s = int.Parse(Console.ReadLine());
			int n = int.Parse(Console.ReadLine());
			for(int i = 0; i < n; i++)
			{
				string[] parts = Console.ReadLine().Split();
				int m = int.Parse(parts[0]);
				int p = int.Parse(parts[1]);
				s += m * p;
			}
			Console.WriteLine(s);
		}
	}
}