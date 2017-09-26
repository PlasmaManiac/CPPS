/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Collections.Generic;

public class jeroenb
{
	static int n, c, s;
	static int[] p;
	static LinkedList<int>[] outg;
	static bool[,,] done, mem;

	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0) {
			string[] parts = Console.ReadLine().Split();
			n = int.Parse(parts[0]);
			c = int.Parse(parts[1]);
			s = int.Parse(parts[2]);
			p = new int[n];
			outg = new LinkedList<int>[n];
			for(int i = 0; i < n; i++)
			{
				p[i] = int.Parse(Console.ReadLine());
				outg[i] = new LinkedList<int>();
			}
			for(int i = 0; i < c; i++)
			{
				parts = Console.ReadLine().Split();
				int a = int.Parse(parts[0]);
				int b = int.Parse(parts[1]);
				outg[a-1].AddLast(b-1);
			}
			done = new bool[n,2,2];
			mem = new bool[n,2,2];
			if(canWin(s-1, 0, 0))
				Console.WriteLine('0');
			else
				Console.WriteLine('1');
		}
	}

	public static bool canWin(int i, int cur, int pl)
	{
		if(done[i,cur,pl])
			return mem[i,cur,pl];
		done[i,cur,pl] = true;
		if(outg[i].Count == 0)
			return mem[i,cur,pl] = cur == pl;
		else
		{
			foreach(int next in outg[i])
			{
				if(pl == p[i] && canWin(next, 1 - cur, pl))
					return mem[i,cur,pl] = true;
				if(pl != p[i] && canWin(next, 1 - cur, 1 - pl))
					return mem[i,cur,pl] = false;
			}
			return mem[i,cur,pl] = pl != p[i];
		}
	}
}