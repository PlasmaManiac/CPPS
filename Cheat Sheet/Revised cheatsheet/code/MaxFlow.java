class Node {
    Edge parent; int flow;
}
class Edge{
    int capacity, flow = 0; Edge back;
}
void main() {
    Edge e = new Edge(b, capacity);
    Edge f = new Edge(a,0);//0 if directed
                           //else capacity
    e.back = f; f.back = e;
    V[a].adj.add(e);
    V[b].adj.add(f);//also if directed
}
int totalFlow = 0;
while (true) {//Find an augmenting path
    for (int i = 0; i < N; i++) {
        V[i].visited = false; 
        V[i].parent = null;
    }
    flow = augment(s, t);
    if (flow == 0) break;
    totalFlow += flow;
    int x = t;
    while (x != s) {//update flow on path
        V[x].parent.flow -= flow; 
        V[x].parent.back.flow += flow;
        x = nodes[x].parent.target;
}}
return totalFlow;