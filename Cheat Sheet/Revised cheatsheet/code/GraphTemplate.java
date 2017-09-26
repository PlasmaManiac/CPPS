class Node {
    boolean visited;
    int dist = Integer.MAX_VALUE/2;
    ArrayList<Edge> adj = new ArrayList();
}
class Edge {
    int target,weight;
    Edge (int t, int w){ ... }
} //Read input/ create graph:
Node[] V = new Node[N];
for (int i = 0; i < N; i++) {
    V[i] = new Node();
} for (int i = 0; i < E; i++) {
    int a, b, w;//From input
    //Watch out which value is which
    //From a to b, having weight w
    V[a].adj.add(new Edge(b,w));
    //In case of undirected graph:
    V[b].adj.add(new Edge(a,w));
}