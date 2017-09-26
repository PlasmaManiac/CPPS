/*
 * @EXPECTED_RESULTS@: CORRECT
 */
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
		int N = Integer.parseInt(in.readLine());

		StringTokenizer st = new StringTokenizer(in.readLine());
		String[] key1 = new String[N];
		for (int i=0;i<N;i++) key1[i] = st.nextToken();

		st = new StringTokenizer(in.readLine());
		String[] key2 = new String[N];
		for (int i=0;i<N;i++) key2[i] = st.nextToken();

		st = new StringTokenizer(in.readLine());
		String[] enc = new String[N];
		for (int i=0;i<N;i++) enc[i] = st.nextToken();

		String[] plain = new String[N];
		for (int i=0;i<N;i++) {
			// To know plain[i], we need to know for which j, key1[i] == key2[j]
			for (int j=0;j<N;j++)
				if (key1[i].equals(key2[j]))
					plain[i] = enc[j];
		}

		for (int i=0;i<N;i++) {
			if (i>0) System.out.print(" ");
			System.out.print(plain[i]);
		}
		System.out.println();
	}
}
