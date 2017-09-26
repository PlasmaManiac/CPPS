int[][] dp = new int[P+1][Q+1];
for (int i = 1; i <= P; i ++) {
    for (int j = 1; j <= Q; j ++) {
        if (A[i-1]==B[j-1]) {
            dp[i][j] = dp[i-1][j-1] + 1;
        } else {
            dp[i][j] =Math.max(dp[i][j-1],
                    dp[i-1][j]);
}}}
return dp[P][Q]; //Length of best solution
get(P,Q); //Retrieves actual sequence
ArrayList<Integer> get(int i, int j) {
    if (i == 0 || j == 0) {
        return new ArrayList<Integer>();
    } else if (A[i-1] == B[j-1]) {
        ArrayList<Integer> L=get(i-1,j-1);
        L.add(A[i-1]);
        return L;
    } else if (dp[i][j-1] > dp[i-1][j]) {
        return get(i,j-1);
    } else {
        return get(i-1,j);
}}