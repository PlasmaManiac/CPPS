// @EXPECTED_RESULTS@: CORRECT
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class bas {
	
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
	static int readInt() throws NumberFormatException, IOException {
		return Integer.parseInt(in.readLine());
	}
	
	static int[] readInts() throws NumberFormatException, IOException {
		String[] strs = in.readLine().split(" ");
		int[] ints = new int[strs.length];
		for (int i=0;i<strs.length;i++)
			ints[i] = Integer.parseInt(strs[i]);
		return ints;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		int n = readInt();
		for (int i=0;i<n;i++)
			doShizzle();
	}

	private static void doShizzle() throws NumberFormatException, IOException {
		int[] input = readInts();
		int cityCount = input[0];
		int edgeCount = input[1];
		int start = input[2]-1;
		int end = input[3]-1;
		int startCost = input[4];
		int kmCost = input[5];
		int fineCost = input[6];
		
		Node[] node = new Node[cityCount];
		Node[] payednode = new Node[cityCount];
		
		for (int i=0; i<cityCount; i++) {
			node[i] = new Node();
			payednode[i] = new Node();
			addEdge(node[i],payednode[i],startCost);
			addEdge(payednode[i],node[i],0);
			
		}
		
		for (int i=0;i<edgeCount;i++) {
			input = readInts();
			addBiEdge(node[input[0]-1], node[input[1]-1], (input[2]*(fineCost+input[3]*kmCost))/100.0);
			addBiEdge(payednode[input[0]-1], payednode[input[1]-1], input[3]*kmCost);
		}
		
		PriorityQueue<QEntry> queue = new PriorityQueue<QEntry>();
		node[start].dist=0;
		node[start].done = true;
		queue.add(new QEntry(node[start]));
		
		while (!queue.isEmpty()) {
			Node poll = queue.poll().node;
			
			if (poll == node[end]) {
				System.out.printf("%.2f\n", node[end].dist);
				return;
			}
			
			poll.done = true;
			for (Edge edge : poll.edges) {
				Node target = edge.to;
				if (!target.done && poll.dist + edge.cost < target.dist) {
					target.dist = poll.dist + edge.cost;
					queue.add(new QEntry(target));
				}
			}
		}
		
		System.out.println("UNREACHABLE");
	}

	private static void addBiEdge(Node node, Node node2, double d) {
		addEdge(node,node2,d);
		addEdge(node2,node,d);
	}

	private static void addEdge(Node node, Node node2, double cost) {
		node.edges.add(new Edge(node, node2, cost));
	}

	static class Node {
		ArrayList<Edge> edges = new ArrayList<Edge>();
		double dist = Double.MAX_VALUE;
		boolean done = false;
	}
	
	static class QEntry implements Comparable<QEntry> {
		Node node;
		double dist;
		public QEntry(Node node) {
			this.node = node;
			this.dist = node.dist;
		}
		@Override
		public int compareTo(QEntry o) {
			return (int) Math.signum(this.dist - o.dist);
		}
		
	}
	
	static class Edge {
		Node from;
		Node to;
		double cost;
		public Edge(Node from, Node to, double cost) {
			super();
			this.from = from;
			this.to = to;
			this.cost = cost;
		}
		
	}
}
