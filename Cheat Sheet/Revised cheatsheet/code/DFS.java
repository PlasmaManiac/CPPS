void DFS(int S) {
    V[S].visited = true;
    for (Edge edge : V[S].adj) {
        if (!(V[S].visited ||
                V[S].obstacle)) { 
            DFS(edge.target);
}}}