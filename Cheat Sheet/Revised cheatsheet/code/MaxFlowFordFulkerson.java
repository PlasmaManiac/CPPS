int augment(int i, int t) {
    if (V[i].visited) return 0;
    V[i].visited = true;
    if (i == t) return Integer.MAX_VALUE;
    for (Edge e : V[i].adj) {
        if(e.capacity-e.flow<=0) continue;
        int f = augment(e.target, t);
        if (f > 0) {//e.target in path 
            f = Math.min(f, 
                e.capacity - e.flow);
            V[e.target].parent=e.back;
            return f;
    }}
    return 0; // no flow to t found   
}