class Node { int i=-1, l, c=-1; ...}
int index = 0, C = 0;
ArrayDeque<Integer> stack = 
        new ArrayDeque<Integer>();
for (int i = 0; i < N; i++) {
    if (V[i].i < 0) tarjan(i);
}
void tarjan(int i) {
    V[i].i = index++;
    V[i].l = V[i].i;
    stack.push(i);
    for (Edge e: V[i].adj) {
        if (V[e.target].i == -1) {
            tarjan(e.target);
            V[i].l = Math.min(
                V[i].l, V[e.target].l);
        } else if (V[e.target].c == -1) {
            V[i].low = Math.min(
                V[i].l, V[e.target].i);
    }}
    if (V[i].i == V[i].l) {//SCC found
        int j;
        do {
            j = stack.pop();
            V[j].c = C;
        } while(j != i);
        C++;
}}