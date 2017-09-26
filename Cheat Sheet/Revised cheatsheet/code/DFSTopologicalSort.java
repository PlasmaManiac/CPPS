class Node{int in; ...}//Nr incoming edges
ArrayList<Node> order = new ArrayList();
for(int i = 0; i < N; i++) {
    if (V[i].in == 0) DFS(i);
}
return order;
void DFS(int S) {
    V[S].in = -1;
    order.add(S);
    for (Edge edge : V[S].adj) {
        if (--V[edge.target].in == 0) {
            DFS(edge.target);
}}}