int[] dp = new int[n+1];//answer at dp[n]
int[] T = new int[n + 1];
ArrayList<Integer> R = new ArrayList();
for (int i = 1; i <= n; i++) {
    dp[i] = Integer.MAX_VALUE / 2;
    for (int j : coins) {
        if(j<=i && (dp[i-j]+1)< dp[i]) {
            dp[i] = dp[i-j] + 1; T[i]=j;
}}}
return dp[n];//Number of coins needed
while(n > 0) {
    R.add(T[n]); n -= dp[n];
}
return R;//List of coins used