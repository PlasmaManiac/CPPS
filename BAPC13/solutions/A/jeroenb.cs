/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Collections.Generic;
using System.Linq;

public class jeroenb
{
	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			int n = int.Parse(Console.ReadLine());
			Satellite[] sat = new Satellite[n];
			for(int i = 0; i < n; i++)
			{
				string[] parts = Console.ReadLine().Split();
				sat[i] = new Satellite(int.Parse(parts[0]), int.Parse(parts[1]), int.Parse(parts[2]), int.Parse(parts[3]));
			}
			Array.Sort(sat);
			
			// Find all distinct x values (at most n)
			SortedList<int, int> sxs = new SortedList<int, int>();
			for(int i = 0; i < n; i++)
			{
				if(!sxs.ContainsKey(sat[i].x1))
					sxs.Add(sat[i].x1, 0);
				if(!sxs.ContainsKey(sat[i].x2))
					sxs.Add(sat[i].x2, 0);
			}
			int[] xs = sxs.Keys.ToArray();
			
			// For each block of x[i] to x[i+1]
			long ans = 0;
			for(int i = 0; i < xs.Length - 1; i++)
			{
				// Count in y direction
				int from = 0;
				int to = 0;
				for(int j = 0; j < n; j++)
				{
					if(sat[j].x1 > xs[i] || sat[j].x2 < xs[i+1]) continue;
					if(sat[j].y1 > to)
					{
						ans += (long)(to - from) * (long)(xs[i+1] - xs[i]);
						from = sat[j].y1;
						to = sat[j].y2;
					} else to = Math.Max(to, sat[j].y2);
				}
				ans += (long)(to - from) * (long)(xs[i+1] - xs[i]);
			}
			Console.WriteLine(ans);
		}
	}
}

class Satellite : IComparable<Satellite>
{
	public int x1, y1, x2, y2;

	public Satellite(int x1, int y1, int x2, int y2)
	{
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;
	}

	public int CompareTo(Satellite other)
	{
		return y1.CompareTo(other.y1);
	}
}