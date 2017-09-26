void main() {
    Edge e = new Edge(b, capacity);
    Edge f = new Edge(a,0);
    e.cost = cost(a, b); f.cost = -e.cost;
    e.back = f; f.back = e;
    V[a].adj.add(e);
    V[b].adj.add(f);
}
int augment(int s, int t) {
    for (Node u : V) {
        u.cost = Integer.MAX_VALUE / 2;
    }
    V[s].flow = Integer.MAX_VALUE / 2;
    V[t].flow = 0;
    V[s].cost = 0.0;
    for (int k = 1; k < V.length; k++) {
        for (Node u : V) {
            for (Edge e : u.adj) {
                if (e.capacity-e.flow<=0){
                    continue;
                }
                int newC= u.cost+e.weight;
                Node v = V[e.target];
                if (newC < v.cost) {
                    v.parent = e.back;
                    v.cost = newC;
    }}}}
    int x = t;
    int flow = Integer.MAX_VALUE / 2;
    while (x != s) { //Find flow
        Edge e = V[x].parent;
        if (e == null) return 0;
        flow = Math.min(e.back.capacity 
                - e.back.flow, flow);
        x = e.target;
    }//update flow
    x = t;
    while (x != s) {
        V[x].flow += flow;
        x = V[x].parent.target;
    }
    return flow;
}