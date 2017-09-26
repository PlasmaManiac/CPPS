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
		StringTokenizer st = new StringTokenizer(in.readLine());
		int[] nums = new int[4];
		for (int i=0;i<4;i++)
			nums[i] = Integer.parseInt(st.nextToken());

		List<Intermediate> ones = new LinkedList<Intermediate>();
		for (int i=0;i<4;i++)
			ones.add(new Intermediate(nums[i], 1<<i));

		List<Intermediate> twos = new LinkedList<Intermediate>();
		List<Intermediate> threes = new LinkedList<Intermediate>();
		List<Intermediate> fours = new LinkedList<Intermediate>();

		combine(ones, ones, twos);
		combine(ones, twos, threes);
		combine(ones, threes, fours);
		combine(twos, twos, fours);

		for (Intermediate i : fours) {
			if (Math.abs(i.value - 24) < .1) {
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
			result.add(new Intermediate(a.value + b.value, which));
			result.add(new Intermediate(a.value - b.value, which));
			result.add(new Intermediate(b.value - a.value, which));
			result.add(new Intermediate(a.value * b.value, which));
			if (b.value != 0)
				result.add(new Intermediate(a.value / b.value, which));
			if (a.value != 0)
				result.add(new Intermediate(b.value / a.value, which));
		}
	}

	static class Intermediate
	{
		Intermediate(double value, int which) {this.value = value; this.which = which;}
	
		double value;
		int which;
	}
}
