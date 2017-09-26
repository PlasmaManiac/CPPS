int p = 0, r = N - 1;
while (p<=r) {
    int q = (p + r) / 2;
    if (A[q] == key) return q;
    else if (...) p=q+1;//if key.index>q
    else r = q - 1; 
}
return -1;