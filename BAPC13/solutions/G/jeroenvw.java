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
		char[] txt = in.readLine().toCharArray();
		int N = txt.length;
		int[] counts = new int['Z'+1];

		for (int i=0;i<N;i++) {
			char c = txt[i];
			counts[c]++;
			if ((counts[c] % 4) == 3)
				if (i==N-1 || txt[i+1] != c) {
					System.out.println("FAKE");
					return;
				}
		}

		System.out.println("OK");
	}
}
