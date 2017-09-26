int C = 0; //Number of components
for(int i = 0; i < N; i++){
    if(!V[i].visited) DFS(i, C++);
}
void DFS (int S, int c) {
    V[S].visited = true;
    V[S].component = c;
    for (Edge e : V[S].adj) {
        if(!V[e.target].visited) {
            DFS(e.target,c);
}}}