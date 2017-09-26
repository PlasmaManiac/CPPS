int[][] dp = new int[n+1][m+1];
for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        dp[i][j] = dp[i - 1][j];
        int val = items[i - 1].value;
        int W = items[i - 1].weight;
        if (W <= j) {
            dp[i][j] = Math.max(dp[i][j], 
                dp[i - 1][j - W] + val);
}}}
System.out.println(dp[n][m]);