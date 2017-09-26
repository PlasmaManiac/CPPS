int[] A = new int[n];//Temp array
int[] tour = new int[n]; //Best tour
for (int i = 0; i < n; i++) tour[i] = i;
TSP(0, 0, Integer.MAX_VALUE/2);
int TSP(int i, int L, int best) {
    if (i==n-1 && (L+D[A[i]][1]) < best){
        best = L+D[A[i]][1];
        tour[i] = A[i];
    } else if (i == n-1){}
    else {
        for(int j = i + 1; j < n; j++) {
            int temp = A[j];
            A[j] = A[i+1];
            A[i+1] = temp;
            int L2 = L + D[A[i]][A[i+1]];
            if (L2 < best) {
                int R = TSP(i+1,L2,best);
                if (R<best) {
                    best = R;
                    tour[i] = A[i];
            }}
            A[i+1] = A[j]; //Swap back
            A[j] = temp;
    }}
    return best;
}