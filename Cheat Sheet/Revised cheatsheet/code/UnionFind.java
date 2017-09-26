int[] P=new int[n];int[] rank=new int[n];
int[] S=new int[n]; int numSets=n;
for(int i=0; i<n; i++) P[i] = i;
Arrays.fill(S,1);
int find(i) {
    if (P[i] == i) return i;
    else {
        int R = find(P[i]); P[i] = R;
        return R;
}}
boolean isSame(int i, int j) {
    return find(i) == find(j);
}
void union(int i, int j) {
    if(isSame(i, j)) return;
    numSets--; int x=find(i), y=find(j); 
    S[x] += S[y]; S[y] = S[x];
    if (rank[x] > rank[y]) P[y] = x;
    else P[x] = y;
    if (rank[x]==rank[y]) rank[y]++;
}