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
			string m = Console.ReadLine();
			bool ok = true;
			int[] count = new int[200];
			for(int i = 0; i < m.Length; i++)
			{
				count[m[i]]++;
				if(count[m[i]] == 3)
				{
					count[m[i]] = 0;
					if(i == m.Length - 1) ok = false;
					else if(m[i+1] != m[i]) ok = false;
					i++;
				}
			}
			Console.WriteLine(ok ? "OK" : "FAKE");
		}
	}
}