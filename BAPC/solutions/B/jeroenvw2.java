// @EXPECTED_RESULTS@: CORRECT
import java.io.*;
import java.util.*;

// Attention: int32-overflow in distance function if distance is more than sqrt(maxint)

class jeroenvw2
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
			double dist = Math.sqrt((xi-x)*(xi-x) + (yi-y)*(yi-y));
			r[i] = si / dist / dist;
		}

		// Idea: add 6*r_i to both sides of the equation to get:
		// 7*r_i > totalnoise

		double totalnoise = B;
		for (int i=0;i<n;i++)
			totalnoise += r[i];
		totalnoise *= 6;

		for (int i=0;i<n;i++) {
			if (7*r[i] > totalnoise) {
				System.out.println(i+1);
				return;
			}
		}
		System.out.println("NOISE");
	}
}
