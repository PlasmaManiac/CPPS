// @EXPECTED_RESULTS@: WRONG-ANSWER
// -> Check every fourth occurence whether it was directly after a 3rd, i.e. miss premetare end-of-string
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
		char[] txt = in.readLine().toCharArray();
		int N = txt.length;
		int[] counts = new int['Z'+1];

		for (int i=0;i<N;i++) {
			char c = txt[i];
			counts[c]++;
			if ((counts[c] % 4) == 0)
				if (i>0 && txt[i-1] != c) {
					System.out.println("FAKE");
					return;
				}
		}

		System.out.println("OK");
	}
}
