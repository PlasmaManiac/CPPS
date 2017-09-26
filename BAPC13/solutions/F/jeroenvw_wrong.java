// @EXPECTED_RESULTS@: WRONG-ANSWER
// -> Erroneously buy each section ticket individually
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
		int MAXEDGE = (int)1e7;

		int[][] edge = new int[n][n];
		for (int i=0;i<n;i++) for (int j=0;j<n;j++) 
			edge[i][j] = MAXEDGE;

		for (int i=0;i<m;i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken())-1;
			int b = Integer.parseInt(st.nextToken())-1;
			int c = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());

			int normal = s + d * p;
			int fine   = y + d * p;

			int exp_pay = 100*normal;
			int exp_nopay = c*fine;

			edge[a][b] = edge[b][a] = Math.min(exp_pay, exp_nopay);
		}

		// Nu lomp zoeken
		int[] mincost = new int[n];
		boolean[] done = new boolean[n];
		for (int i=0;i<n;i++) mincost[i] = MAX;
		mincost[start] = 0;
		while (true) {
			int damin = MAX;
			int daminidx= -1;
			for (int i=0;i<n;i++) {
				if (done[i]) continue;
				if (mincost[i] < damin) {
					damin = mincost[i];
					daminidx = i;
				}
			}

			done[daminidx] = true;
			if (daminidx == end) {
				String res = "" + damin;
				if (damin >= 100)
					System.out.println(res.substring(0, res.length()-2) + "." + res.substring(res.length()-2));
				else if (damin >= 10)
					System.out.println("0." + res);
				else 
					System.out.println("0.0" + res);
				return;
			}

			if (daminidx < 0) break;
			for (int j=0;j<n;j++) {
				if (done[j]) continue;
				mincost[j] = Math.min(mincost[j],
						mincost[daminidx] + edge[daminidx][j]);
			}
		}

	}
}
