class Node {int parent; ... }
class ND implements Comparable<ND> {
    int index, dist;
    ND(int i, int t) { ... }
    public int compareTo(ND other) {
        return (dist - other.dist);
}} //ND = NodeDistance
PriorityQueue<ND> Q = new PriorityQueue(); 
V[S].dist = 0;
Q.add(new ND(S, 0));
while(!Q.isEmpty()) {
    ND nd = Q.poll();
    int u = nd.index;
    int d = nd.dist;
    if (V[u].dist < d) continue;
    for (Edge edge : V[u].adj) {
        int newD = d + edge.weight;
        int v = edge.target;
        if (newD < V[v].dist) {
            V[v].dist = newD;
            V[v].parent = u;
            Q.add(new ND(v, newD));
}}}//Nodes now contain distance + parent