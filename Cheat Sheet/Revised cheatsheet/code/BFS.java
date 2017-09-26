class Node { int dist = -1; ... }
ArrayDeque<Integer> Q = new ArrayDeque(N);
V[S].dist = 0;
Q.add(S);
while(!Q.isEmpty()) {
    int u = Q.poll();
    for(Edge e : V[u].adj) {
        if (V[e.target].dist>=0) continue;
        V[e.target].dist = V[u].dist + 1;
        Q.add(e.target);
}}