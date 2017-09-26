boolean[] P = new boolean[n+1];
Arrays.fill(P, true);
P[0] = false; P[1] = false;
for (int i = 2; i <= n; i++) {
    if (!P[i]) continue;
    for(int j=i*i; j<=n; j+=i) P[j]=false;
    primes.add(i);//List of primes <= N
}
return P;