/*
 * @EXPECTED_RESULTS@: CORRECT
 */
using System;
using System.Collections.Generic;

public class jeroenb
{
	static int[] dr = new int[] { 1, 0, -1, 0 };
	static int[] dc = new int[] { 0, 1, 0, -1 };

	public static void Main(string[] args)
	{
		int tests = int.Parse(Console.ReadLine());
		while(tests-- > 0)
		{
			string[] parts = Console.ReadLine().Split();
			int h = int.Parse(parts[0]);
			int w = int.Parse(parts[1]);
			string[] grid = new string[h];
			for(int i = 0; i < h; i++)
				grid[i] = Console.ReadLine();
			List<char> keys = new List<char>(Console.ReadLine().ToCharArray());
			bool[,] found = new bool[h,w];
			int ans = 0;
			for(int i = 0; i < 26; i++)
			{ // We can find a new key at most 26 times
				bool[,] done = new bool[h,w];
				Queue<Point> Q = new Queue<Point>();
				for(int j = 0; j < w; j++)
				{
					Q.Enqueue(new Point(0, j));
					Q.Enqueue(new Point(h-1, j));
				}
				for(int j = 0; j < h; j++)
				{
					Q.Enqueue(new Point(j, 0));
					Q.Enqueue(new Point(j, w-1));
				}
				while(Q.Count > 0)
				{
					Point top = Q.Dequeue();
					// Are we still in the grid?
					if(top.r < 0 || top.r >= h || top.c < 0 || top.c >= w) continue;
					char cur = grid[top.r][top.c];
					// No walls or visited cells
					if(done[top.r,top.c] || cur == '*') continue;
					done[top.r,top.c] = true;
					// If it's a door, can we open it?
					if(char.IsUpper(cur) && !keys.Contains(char.ToLower(cur))) continue;
					if(cur == '$' && !found[top.r,top.c])
					{ // Yeah! A valuable document!
						ans++;
						found[top.r,top.c] = true;
					}
					// Oh, a new key, nice!
					if(char.IsLower(cur) && !keys.Contains(cur))
						keys.Add(cur);
					// Ok, let's continue walking
					for(int j = 0; j < 4; j++)
						Q.Enqueue(new Point(top.r+dr[j], top.c+dc[j]));
				}
			}
			Console.WriteLine(ans);
		}
	}

	class Point
	{
		public int r, c;

		public Point(int r, int c)
		{
			this.r = r; this.c = c;
		}
	}
}