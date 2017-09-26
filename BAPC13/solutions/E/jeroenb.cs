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
			int n = int.Parse(Console.ReadLine());
			string[] key1 = Console.ReadLine().Split();
			string[] key2 = Console.ReadLine().Split();
			string[] message = Console.ReadLine().Split();
			Dictionary<string, int> pos = new Dictionary<string, int>();
			for(int i = 0; i < n; i++)
				pos[key2[i]] = i;
			for(int i = 0; i < n; i++)
			{
				if(i > 0) Console.Write(' ');
				Console.Write(message[pos[key1[i]]]);
			}
			Console.WriteLine();
		}
	}
}