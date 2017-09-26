// @EXPECTED_RESULTS@: WRONG-ANSWER
// -> Greedy heuristic
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
		int e = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(in.readLine());
		int[] setsizes = new int[n];
		for (int i=0;i<n;i++) setsizes[i] = Integer.parseInt(st.nextToken());

		// Greedy, smallest first
		Arrays.sort(setsizes);
		int converted = 0;
		for (int i=0;i<n;i++) {
			if (converted*2 >= e) break;

			converted += setsizes[i];
		}

		if (converted*2 >= e)
			System.out.println(converted);
		else
			System.out.println("FULL");
	}
}
