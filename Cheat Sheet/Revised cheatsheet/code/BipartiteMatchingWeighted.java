class Node { int p = 0; }//potential
int[][] W = new int[M][M];//Global var
for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
        A[i].p = Math.max(A[i].p,W[i][j]);
    }
}
int S = 0;
while (S < M) {
    for (int i = 0; i < M; i++) {
        A[i].adj.clear();
        for (int j = 0; j < M; j++) {
            if (A[i].p+B[j].p==W[i][j]) {
                A[i].adj.add(j);
    }}}
    S = checkMatch();
}
int checkMatch() {
    for (int i = 0; i < M; i++) {
        A[i].match = -1; B[i].match = -1;
    }
    int S = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            A[j].visited = false;
        }
        if (augment(i)) S++;
    }
    for (int i = 0; i < M; i++) {
        if (B[i].match == -1) continue;
        A[B[i].match].match = i;
    }
    for (int j = 0; j < M; j++) {
        B[j].visited = false;
        A[j].visited = false;
    }
    for (int i = 0; i < M; i++) {
        if (A[i].match == -1) augment(i);
    }
    int X = M+1;
    for (int i = 0; i < M; i++) {
        if (!A[i].visited) continue;
        for (int j = 0; j < M; j++) {
            if (B[j].visited) continue;
            X = Math.min(X, A[i].p + B[j].p - W[i][j]);
    }}
    for (int i = 0; i < M; i++) {
        if (A[i].visited) A[i].p -= X;
        if (B[i].visited) B[i].p += X;
    }
    return S;
}