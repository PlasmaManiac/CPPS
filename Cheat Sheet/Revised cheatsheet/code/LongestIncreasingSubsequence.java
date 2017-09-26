int[] T = new int[n], R = new int[n];
Arrays.fill(R, -1);
int length = 0;
ArrayList<Integer> ans = new ArrayList();
for (int i=1; i < n; i++) {
    if (A[T[0]] > A[i]) { 
        T[0] = i;
    } else if(A[T[length]] < A[i]) { 
        T[++length] = i;
        R[T[length]] = T[length - 1];
    } else {
        int j = search(length, A[i]);   
        if (j < 0) continue;
        T[j] = i;
        R[T[j]] = T[j - 1];
}}
int i = T[length];
while(i >= 0) {
    ans.add(A[i]); i = R[i];  
}
Collections.reverse(ans);
return ans;
int search (int E, int v){
    int S = 0, L = E, M;
    while(S <= E){
        M = (S + E) / 2;
        if(M<L&&A[T[M]]<v&&v<=A[T[M+1]]){
            return M + 1;
        } else if(A[T[M]] < v){
            S = M + 1;
        } else {
            E = M-1;
    }}
    return -1;
}