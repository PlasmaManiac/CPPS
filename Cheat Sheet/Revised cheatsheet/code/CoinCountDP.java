long[] dp = new long[n + 1];
dp[0] = 1L;
for (int i = 0; i < coins.length; i++) {
    for (int j = coins[i]; j<=n; j++){
        dp[j] += dp[j - coins[i]];
}}
dp[0] = 0L;//Problem dependant
return dp;