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
			string[] parts = Console.ReadLine().Split();
			List<frac> fracs = new List<frac>();
			for(int i = 0; i < 4; i++)
				fracs.Add(new frac(int.Parse(parts[i]), 1));
			Console.WriteLine(Check(fracs) ? "YES" : "NO");
		}
	}

	public static IEnumerable<frac> Combine(frac a, frac b)
	{
		yield return a * b;
		yield return a + b;
		if(b.n != 0)
			yield return a / b;
		yield return a - b;
	}

	public static bool Check(List<frac> fracs)
	{
		if(fracs.Count == 1)
			return fracs[0].d * 24 == fracs[0].n;
		else
			for(int i = 0; i < fracs.Count; i++)
				for(int j = 0; j < fracs.Count; j++)
				{
					if(i == j) continue;
					foreach(frac f in Combine(fracs[i], fracs[j]))
					{
						List<frac> fs = new List<frac>();
						fs.Add(f);
						for(int k = 0; k < fracs.Count; k++)
							if(k != i && k != j)
								fs.Add(fracs[k]);
						if(Check(fs)) return true;
					}
				}
		return false;
	}
}

public class frac
{
	public int n, d;

	public frac(int n, int d)
	{
		this.n = n;
		this.d = d;
	}

	public static frac operator *(frac a, frac b)
	{
		return new frac(a.n * b.n, a.d * b.d);
	}

	public static frac operator /(frac a, frac b)
	{
		return new frac(a.n * b.d, a.d * b.n);
	}

	public static frac operator +(frac a, frac b)
	{
		return new frac(a.n * b.d + b.n * a.d, a.d * b.d);
	}

	public static frac operator -(frac a, frac b)
	{
		return new frac(a.n * b.d - b.n * a.d, a.d * b.d);
	}
}