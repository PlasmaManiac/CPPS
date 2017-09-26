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
		int s = Integer.parseInt(in.readLine());
		int n = Integer.parseInt(in.readLine());
		for (int i=0;i<n;i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int q = Integer.parseInt(st.nextToken());
			int p = Integer.parseInt(st.nextToken());

			s += q*p;
		}

		System.out.println(s);
	}
}
