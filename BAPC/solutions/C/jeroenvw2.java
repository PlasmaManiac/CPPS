// @EXPECTED_RESULTS@: CORRECT
// Exact solution
import java.io.*;
import java.util.*;

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
		StringTokenizer st = new StringTokenizer(in.readLine());
		int[] nums = new int[4];
		for (int i=0;i<4;i++)
			nums[i] = Integer.parseInt(st.nextToken());

		List<Intermediate> ones = new LinkedList<Intermediate>();
		for (int i=0;i<4;i++)
			ones.add(new Intermediate(nums[i], 1,  1<<i));

		List<Intermediate> twos = new LinkedList<Intermediate>();
		List<Intermediate> threes = new LinkedList<Intermediate>();
		List<Intermediate> fours = new LinkedList<Intermediate>();

		combine(ones, ones, twos);
		combine(ones, twos, threes);
		combine(ones, threes, fours);
		combine(twos, twos, fours);

		for (Intermediate i : fours) {
			if (i.teller == 24 * i.noemer) {
				System.out.println("YES");
				return;
			}
		}

		System.out.println("NO");
	}

	static void combine(List<Intermediate> aa, List<Intermediate> bb, List<Intermediate> result)
	{
		for (Intermediate a : aa) for (Intermediate b : bb) {
			if ((a.which & b.which) != 0) continue;
			int which = a.which | b.which;
			int noemer = a.noemer * b.noemer;
			int tela = a.teller * b.noemer;
			int telb = b.teller * a.noemer;
			result.add(new Intermediate(tela + telb, noemer, which));
			result.add(new Intermediate(tela - telb, noemer, which));
			result.add(new Intermediate(telb - tela, noemer, which));
			result.add(new Intermediate(a.teller * b.teller, noemer, which));
			if (b.teller != 0)
				result.add(new Intermediate(a.teller * b.noemer, b.teller * a.noemer, which));
			if (a.teller != 0)
				result.add(new Intermediate(b.teller * a.noemer, a.teller * b.noemer, which));
		}
	}

	static class Intermediate
	{
		Intermediate(int teller, int noemer, int which)
		{this.teller = teller; this.noemer = noemer; this.which = which;}
	
		int teller, noemer;
		int which;
	}
}
