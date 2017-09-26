int[][] dist = new int[N][N];
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        dist[i][j] = Integer.MAX_VALUE/2;
        if (i == j) dist[i][j] = 0;
}}
for (int u = 0; u < N; u++) {
    for (Edge e : nodes[u].adj) {
        dist[u][e.target] = e.weight;
}}//Assume: only 1 edge from u to e.target
for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = Math.min(
                dist[i][j], dist[i][k]
                + dist[k][j]);
}}}