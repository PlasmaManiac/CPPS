/*
 * @EXPECTED_RESULTS@: WRONG-ANSWER
 * -> Wrongly assuming uniqueness of enc
 */
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

		HashMap<String,String> encToKey = new HashMap<String,String>();
		HashMap<String,Integer> plainkeyToIdx = new HashMap<String,Integer>();

		for (int i=0;i<N;i++) {
			encToKey.put(enc[i], key2[i]);
			plainkeyToIdx.put(key1[i], i);
		}

		String[] plain = new String[N];
		for (int i=0;i<N;i++) {
			// Set plain based on the lookups
			plain[ plainkeyToIdx.get(encToKey.get(enc[i]))] = enc[i];
		}
		for (int i=0;i<N;i++) {
			if (i>0) System.out.print(" ");
			System.out.print(plain[i]);
		}
		System.out.println();
	}
}
