// @EXPECTED_RESULTS@: CORRECT
import java.io.*;
import java.util.*;

class jeroenvw
{
	static BufferedReader in;

	public static void main(String[] v) throws IOException
	{
		in = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(in.readLine());
		for (int i=0; i<N; i++) go();
	}

	static void go() throws IOException
	{
		StringTokenizer st = new StringTokenizer(in.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int start = Integer.parseInt(st.nextToken())-1;
		int end = Integer.parseInt(st.nextToken())-1;
		int s = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());

		int MAX = (int)1e9;

		int[][] dist = new int[n][n];
		for (int i=0;i<n;i++) for (int j=0;j<n;j++) 
			dist[i][j] = -1;
		int[][] expcontrol = new int[n][n];

		for (int i=0;i<m;i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken())-1;
			int b = Integer.parseInt(st.nextToken())-1;
			int c = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());

			if (a >= b || dist[a][b] != -1) throw new Error("wrong/duplicate edge");
			dist[a][b] = dist[b][a] = d;
			expcontrol[a][b] = expcontrol[b][a] = c;
		}

		// Mincost steeds 2 items van zelfde stad: kosten als je tot daar een
		// ticket hebt, dan kosten als je geen ticket hebt tot daar
		int[] mincost = new int[n*2];
		boolean[] done = new boolean[n*2];
		for (int i=0;i<n*2;i++) mincost[i] = MAX;
		mincost[start*2+1] = 0;
		while (true) {
			int themin = MAX;
			int theminidx= -1;
			for (int i=0;i<n*2;i++) {
				if (done[i]) continue;
				if (mincost[i] < themin) {
					themin = mincost[i];
					theminidx = i;
				}
			}

			if (theminidx < 0) throw new Error("Unreachable");

			//System.err.println("Doing " + theminidx + ", curcost = " + themin);
			done[theminidx] = true;
			if (theminidx/2 == end) {
				String res = "" + themin;
				if (themin >= 100)
					System.out.println(res.substring(0, res.length()-2) + "." + res.substring(res.length()-2));
				else if (themin >= 10)
					System.out.println("0." + res);
				else 
					System.out.println("0.0" + res);
				return;
			}

			int i = theminidx/2;
			for (int j=0;j<n;j++) {
				if (dist[i][j]<0) continue;

				// Pay case
				if (!done[j*2]) {
					boolean paidsofar = (theminidx & 1) == 0;
					mincost[j*2] = Math.min(mincost[j*2],
							themin + 100 * ((paidsofar?0:s) + dist[i][j]*p));
				}

				// No pay case
				if (!done[j*2+1])
					mincost[j*2+1] = Math.min(mincost[j*2+1],
							themin + expcontrol[i][j] * (y+dist[i][j]*p));
			}
		}
	}
}
