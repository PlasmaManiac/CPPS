// @EXPECTED_RESULTS@: WRONG-ANSWER
// -> 32-bit int overflow
import java.io.*;
import java.util.*;

class jeroenvw_wrong
{
	static BufferedReader in;

	public static void main(String[] v) throws IOException
	{
		in = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(in.readLine());
		for (int i=0; i<N; i++) go();
	}

	static class Rand implements Comparable
	{
		int x, y1, y2;
		Rand begin; // Null if begin itself, set to begin if end

		Rand(int x, int y1, int y2)
		{
			this.x = x; this.y1 = y1; this.y2 = y2;
			begin = null;
		}
		Rand(int x, Rand begin)
		{
			this.x = x;
			this.y1 = begin.y1;
			this.y2 = begin.y2;
			this.begin = begin;
		}

		public int compareTo(Object o)
		{
			Rand r = (Rand)o;
			int diff = this.x - r.x;
			return diff;
		}
	}

	static void go() throws IOException
	{
		int n = Integer.parseInt(in.readLine());

		Rand[] randen = new Rand[n*2];
		int nrand = 0;

		for (int i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());

			Rand begin = randen[nrand++] = new Rand(x1, y1, y2);
			randen[nrand++] = new Rand(x2, begin);
		}

		Arrays.sort(randen);

		TreeMap<Integer, Integer> sweepline = new TreeMap<Integer, Integer>();

		int area = 0;

		int lastx = 0;
		for (int i=0;i<nrand;i++) {
			Rand r = randen[i];

			// Current line contrib
			int nrect = 0;
			int len = 0;
			int lasty = 0;
			for (Map.Entry e : sweepline.entrySet()) {
				int k = (Integer)e.getKey();
				int v = (Integer)e.getValue();
				if (nrect > 0)
					len += k-lasty;
				lasty = k;

				nrect += v;
			}
			asrt(nrect==0);

			area += len * (r.x-lastx);
			lastx = r.x;


			// Update sweepline
			boolean begin = r.begin == null;

			if (sweepline.get(r.y1) == null)
				sweepline.put(r.y1, 0);
			if (sweepline.get(r.y2) == null)
				sweepline.put(r.y2, 0);

			sweepline.put(r.y1, (int)sweepline.get(r.y1) + (begin ? 1 : -1));
			sweepline.put(r.y2, (int)sweepline.get(r.y2) + (begin ? -1 : 1));
		}

		System.out.println(area);
	}

	static void asrt(boolean cond)
	{
		if (!cond) throw new Error("Oops");
	}

}
