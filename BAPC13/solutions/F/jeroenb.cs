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
			int n = int.Parse(parts[0]);
			int m = int.Parse(parts[1]);
			int start = int.Parse(parts[2]) - 1;
			int end = int.Parse(parts[3]) - 1;
			int s = int.Parse(parts[4]);
			int p = int.Parse(parts[5]);
			int y = int.Parse(parts[6]);
			int[] a = new int[m];
			int[] b = new int[m];
			int[] c = new int[m];
			int[] d = new int[m];
			LinkedList<int>[] outgoing = new LinkedList<int>[n];
			for(int i = 0; i < n; i++)
				outgoing[i] = new LinkedList<int>();
			for(int i = 0; i < m; i++)
			{
				parts = Console.ReadLine().Split();
				a[i] = int.Parse(parts[0]) - 1;
				b[i] = int.Parse(parts[1]) - 1;
				c[i] = int.Parse(parts[2]);
				d[i] = int.Parse(parts[3]);
				outgoing[a[i]].AddLast(i);
				outgoing[b[i]].AddLast(i);
			}

			PriorityQueue<State> Q = new PriorityQueue<State>();
			Q.Push(new State(start, 0, false));
			bool[,] done = new bool[n, 2];
			double ans = -1;
			while(Q.Count > 0)
			{
				State top = Q.Pop();
				if(done[top.i,top.startup?1:0]) continue;
				done[top.i,top.startup?1:0] = true;
				
				if(top.i == end)
				{
					ans = top.cost;
					break;
				}

				foreach(int next in outgoing[top.i])
				{
					int nxt = top.i == a[next] ? b[next] : a[next];

					// Just pay
					Q.Push(new State(nxt, top.cost + (top.startup ? 0 : s) + d[next] * p, true));

					// Take our chances
					Q.Push(new State(nxt, top.cost + c[next] / 100d * (y + d[next] * p), false));
				}
			}
			Console.WriteLine("{0:0.00}", ans);
		}
	}
}

class State : IComparable<State>
{
	public int i;
	public double cost;
	public bool startup;

	public State(int i, double c, bool s)
	{
		this.i = i;
		this.cost = c;
		this.startup = s;
	}

	public int CompareTo(State other)
	{
		return cost.CompareTo(other.cost);
	}
}

public class PriorityQueue<T>
{
	private T[] list;
	public int Count;
	public System.Collections.Generic.Comparer<T> Comparer;

	public PriorityQueue()
	{
		list = new T[1024];
		Count = 0;
		Comparer = System.Collections.Generic.Comparer<T>.Default;
	}

	public void Push(T value)
	{
		if (Count == list.Length)
		{
			T[] tmp = new T[list.Length * 2];
			System.Array.Copy(list, tmp, list.Length);
			list = tmp;
		}
		list[Count++] = value;
		int i = Count - 1;
		while (i > 0 && Comparer.Compare(list[i], list[parent(i)]) < 0)
		{
			T tmp = list[i];
			list[i] = list[parent(i)];
			list[parent(i)] = tmp;
			i = parent(i);
		}
	}

	public T Pop()
	{
		T ret = list[0];
		list[0] = list[--Count];
		int i = 0;
		while (true)
		{
			int left = (i * 2) + 1;
			if (left >= Count) break;
			int right = left + 1;
			int ind = left;
			if (right < Count && Comparer.Compare(list[left], list[right]) >
					0)
				ind = right;
			if (Comparer.Compare(list[i], list[ind]) >= 0)
			{
				T tmp = list[i];
				list[i] = list[ind];
				list[ind] = tmp;
				i = ind;
			}
			else break;
		}
		return ret;
	}

	private int parent(int i)
	{
		return (i - 1) / 2;
	}
}
