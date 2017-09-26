// @EXPECTED_RESULTS@: WRONG-ANSWER
// -> Greedy heuristic
import java.io.*;
import java.util.*;

class jeroenvw_wrong2
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
		int e = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(in.readLine());
		int[] setsizes = new int[n];
		for (int i=0;i<n;i++) setsizes[i] = Integer.parseInt(st.nextToken());

		// Greedy: largest until it is possible with one more, then the best
		// fit
		Arrays.sort(setsizes);
		int converted = 0;
		for (int i=n-1;i>=0;i--) {
			int stillneeded = e - converted*2;
			if (2*setsizes[i] >= stillneeded) {
				// Almost there
				for (int j=0;j<=i;j++) {
					if (2*setsizes[j] >= stillneeded) {
						System.out.println(converted + setsizes[j]);
						return;
					}
				}
			}
			converted += setsizes[i];
		}

		System.out.println("FULL");
	}
}
