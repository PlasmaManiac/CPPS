// @EXPECTED_RESULTS@: TIMELIMIT
// -> O(n^2) solution calculating every possible mic in O(n)
import java.io.*;
import java.util.*;

class jeroenvw_slow
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
		int n = Integer.parseInt(in.readLine());
		int B = Integer.parseInt(in.readLine());
		StringTokenizer st = new StringTokenizer(in.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		double[] r = new double[n];
		for (int i=0;i<n;i++) {
			st = new StringTokenizer(in.readLine());
			int xi = Integer.parseInt(st.nextToken());
			int yi = Integer.parseInt(st.nextToken());
			int si = Integer.parseInt(st.nextToken());
			double dist = Math.sqrt((double)(xi-x)*(xi-x) + (double)(yi-y)*(yi-y));
			r[i] = si / dist / dist;
		}

		// Recalulate every iteration, but maximum shortcutting
		for (int i=n-1;i>=0;i--) {
			double ownsound = r[i];
			double noise = B;
			// Also shortcut noise summing
			for (int j=0;j<n;j++) {
				if (i != j) {
					noise += r[j];
					if (6*noise > ownsound) break;
				}
			}
			if (ownsound > 6*noise) {
				// Find out the correct index
				for (int j=0;j<n;j++) {
					if (r[j] == r[i]) {
						System.out.println(j+1);
						return;
					}
				}
			}
		}
		System.out.println("NOISE");
	}
}
