int[][] dp = new int[M+1][N+1];
for (int i = 1; i <= M; i++) {
   dp[i][0] = dp[i - 1][0] + dC(A[i-1]);
} for (int i = 1; i <= N; i++) {
   dp[0][i] = dp[0][i - 1] + iC(B[i-1]);
} for (int i = 1; i <= M; i ++) {
   for (int j = 1; j <= N; j ++) {
      if (A[i-1]==B[j-1]) {
         dp[i][j] = dp[i-1][j-1];
      } else {
         dp[i][j] = Math.min(dp[i-1][j-1]
            + sC(A[i-1], B[j-1]),
            dp[i-1][j] + dC(A[i-1]));
         dp[i][j] = Math.min(dp[i][j],
            dp[i][j-1] + iC(B[j-1]));
}}}
return dp[M][N]; //Length of best solution