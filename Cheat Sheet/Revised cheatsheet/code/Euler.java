class Edge {boolean used; Edge back;...}
for (int i = 0; i < E; i++) {
    int a, b;//from input
    Edge e = new Edge(b);
    Edge f = new Edge(a);//If G undirected
    e.back=f; f.back=e;//Else f&e.back not
    a.adj.add(e); b.adj.add(f);//needed
}
LinkedList<Integer> L = new LinkedList();
L.add(start);
euler(start, L.listIterator(1));
return L;
void euler(int i,ListIterator<Integer> C){
    for(Edge e : V[i].adj) {
        if (e.used) continue;
        e.used=true;
        e.back.used=true;//If G undirected
        C.add(e.target);
        euler(e.target, cur);
    }
    C.previous();
}