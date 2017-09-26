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
		int n = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int s = Integer.parseInt(st.nextToken())-1;
		int[] p = new int[n];
		for (int i=0;i<n;i++)
			p[i] = Integer.parseInt(in.readLine());

		int[] outdegree = new int[n];

		ArrayList<Integer>[] inEdges = new ArrayList[n];
		for (int i=0;i<n;i++)
			inEdges[i] = new ArrayList<Integer>();

		for (int i=0;i<c;i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken())-1;
			int b = Integer.parseInt(st.nextToken())-1;

			outdegree[a]++;
			inEdges[b].add(a);
		}

		// if <odd|even> moves are done, can the player controlling the node win?
		boolean[] odd_canwin = new boolean[n];
		boolean[] evn_canwin = new boolean[n];

		// Queue of nodes that have no unprocessed outlinks
		LinkedList<Integer> queue = new LinkedList<Integer>();
		for (int i=0;i<n;i++) {
			if (outdegree[i] == 0) {
				// Node has no outlinks at all
				evn_canwin[i] = p[i] == 0;
				odd_canwin[i] = p[i] == 1;
				queue.add(i);
			}
		}

		while (!queue.isEmpty()) {
			int target = queue.poll();
			asrt(outdegree[target] == 0);

			if (s == target) {
				if (evn_canwin[s])
					System.out.println(p[s]);
				else
					System.out.println(1-p[s]);
				return;
			}

			for (Integer source : inEdges[target]) {
				if (evn_canwin[target] && p[target] == p[source])
					odd_canwin[source] = true;
				if (odd_canwin[target] && p[target] == p[source])
					evn_canwin[source] = true;

				if (!evn_canwin[target] && p[target] != p[source])
					odd_canwin[source] = true;
				if (!odd_canwin[target] && p[target] != p[source])
					evn_canwin[source] = true;

				if (--outdegree[source] == 0)
					queue.add(source);
			}
		}
	}

	static void asrt(boolean cond)
	{
		if (!cond) throw new Error("Oops");
	}
}
