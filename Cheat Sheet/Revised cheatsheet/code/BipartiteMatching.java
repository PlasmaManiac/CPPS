class Node {
    int match=-1; boolean visited=false;
}
Node[] A,B;
int M = 0; // matching size/solution
for (int i = 0; i < p; i++) {
    for (Node u : A) {
        u.visited = false;
    }
    if (augment(i)) M++;
}
return M;
boolean augment(int i) {
    if (A[i].visited) return false;
    A[i].visited = true;
    for (Integer j: A[i].adj) {
        B[j].visited = true;
        if (B[j].match == -1 ||
                augment(B[j].match)) {
            B[j].match = i;
            return true;
    }}
    return false;
}