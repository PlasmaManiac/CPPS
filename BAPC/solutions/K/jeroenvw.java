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

	static int[] dx, dy;
	static {
		dx = new int[4];
		dx[0] = 1;
		dx[1] = -1;
		dx[2] = 0;
		dx[3] = 0;

		dy = new int[4];
		dy[0] = 0;
		dy[1] = 0;
		dy[2] = 1;
		dy[3] = -1;
	}

	static class T
	{
		public T(int x, int y) {this.x = x; this.y=y;}
		public int x, y;
	}

	static char[][] mymaze;
	static boolean[] myhaskey;

	static boolean can(int x, int y)
	{
		if (x<0 || y<0 || x>=mymaze.length || y >= mymaze[0].length)
			return false;
		char c = mymaze[x][y];
		if (c=='.' || c=='$' || ('a' <= c && c <= 'z')) return true;
		if ('A' <= c && c <= 'Z')
		{
			char key = (char)((char)(c - 'A') + 'a');
			if (myhaskey[key]) return true;
		}
		return false;
	}

	static void go() throws IOException
	{
		StringTokenizer st = new StringTokenizer(in.readLine());
		int h = Integer.parseInt(st.nextToken());
		int w = Integer.parseInt(st.nextToken());

		char[][] maze = new char[h][];

		for (int i=0;i<h;i++)
			maze[i] = in.readLine().toCharArray(); // Whoppa!

		char[] startkeys = in.readLine().toCharArray();
		boolean[] haskey = new boolean[128];
		for (int i=0;i<startkeys.length;i++)
			haskey[startkeys[i]] = true;

		mymaze = maze;
		myhaskey = haskey;

		int X = h;
		int Y = w;

outer:
		while (true) {
			LinkedList<T> todo = new LinkedList<T>();

			int docs = 0;

			boolean[][] done = new boolean[X][Y];

			for (int x=0;x<X;x++) {
				if (can(x, 0))   todo.add(new T(x, 0));
				if (can(x, Y-1)) todo.add(new T(x, Y-1));
			}
			for (int y=0;y<Y;y++) {
				if (can(0,   y)) todo.add(new T(0, y));
				if (can(X-1, y)) todo.add(new T(X-1, y));
			}

			while (!todo.isEmpty()) {
				T t = todo.pop();
				if (done[t.x][t.y]) continue;
				done[t.x][t.y] = true;

				char c = maze[t.x][t.y];
				if (c=='$') docs++;
				if ('a' <= c && c <= 'z' && !haskey[c])
				{
					haskey[c] = true;
					// more keys!
					continue outer;
				}

				for (int d=0;d<4;d++)
				{
					int nx = t.x+dx[d];
					int ny = t.y+dy[d];
					if (can(nx, ny)) {
						todo.add(new T(nx, ny));
					}
				}
			}

			System.out.println(""+docs);
			return;
		}
	}
}
