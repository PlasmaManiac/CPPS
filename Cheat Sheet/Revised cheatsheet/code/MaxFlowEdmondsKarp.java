int augment(int s, int t) {
    ArrayList<Integer> Q=new ArrayList();
    V[s].visited = true;
    V[s].flow = Integer.MAX_VALUE / 2; 
    V[t].flow = 0;
    Q.add(s);
    for (int i = 0; i < Q.size(); i++) {
        int u = Q.get(i);
        if (u == t) break;//
        for (Edge e: V[u].adj) {
            if (e.capacity - e.flow <= 0 
                ||V[e.target].visited) 
                    continue;
            V[e.target].flow = 
                Math.min(V[u].flow, 
                    e.capacity - e.flow);
            V[e.target].visited=true;
            V[e.target].parent=e.back;
            Q.add(e.target);
    }}
    return V[t].flow;
}
