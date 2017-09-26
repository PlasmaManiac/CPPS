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
			int product = int.Parse(Console.ReadLine());
			Dictionary<int, int> factors = new Dictionary<int, int>();
			int cur = 2;
			while(cur * cur <= product)
			{
				while(product % cur == 0)
				{
					if(!factors.ContainsKey(cur)) factors[cur] = 0;
					factors[cur]++;
					product /= cur;
				}
				cur++;
			}
			if(product > 1) factors[product] = 1;

			List<int> ret = new List<int>();
			foreach(int fac in factors.Keys)
			{
				int num = factors[fac];
				cur = fac;
				while(num > 0)
				{
					if((num & 1) == 1) ret.Add(cur);
					num >>= 1;
					cur *= cur;
				}
			}

			ret.Sort();
			bool start = true;
			foreach(int ans in ret)
			{
				if(start) start = false;
				else Console.Write(' ');
				Console.Write(ans);
			}
			Console.WriteLine();
		}
	}
}