/*
 * @EXPECTED_RESULTS@: CORRECT
 */
import java.util.*;
import java.io.*;

public class jeroenb {
	static int n, c, s;
	static int[] p;
	static LinkedList<Integer>[] outg;
	static boolean[][][] done, mem;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		while(tests-- > 0) {
			n = sc.nextInt();
			c = sc.nextInt();
			s = sc.nextInt();
			p = new int[n];
			outg = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				p[i] = sc.nextInt();
				outg[i] = new LinkedList<Integer>();
			}
			for(int i = 0; i < c; i++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				outg[a-1].add(b-1);
			}
			done = new boolean[n][2][2];
			mem = new boolean[n][2][2];
			if(canWin(s-1, 0, 0))
				System.out.println('0');
			else if(canWin(s-1, 0, 1))
				System.out.println('1');
			else
				System.out.println("This is not right..");
		}
	}

	public static boolean canWin(int i, int cur, int pl) {
		if(done[i][cur][pl]) return mem[i][cur][pl];
		done[i][cur][pl] = true;
		if(outg[i].size() == 0) {
			return mem[i][cur][pl] = cur == pl;
		} else {
			for(Integer next : outg[i]) {
				if(pl == p[i] && canWin(next, 1 - cur, pl))
					return mem[i][cur][pl] = true;
				if(pl != p[i] && canWin(next, 1 - cur, 1 - pl))
					return mem[i][cur][pl] = false;
			}
			return mem[i][cur][pl] = pl != p[i];
		}
	}
}