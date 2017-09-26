class Node { boolean inTree = false; ...}
class NW implements Comparable<NW> {
   int i,w,p;//node index, weight, parent
   NW(int I, int W, int P) {...};
   public int compareTo(NW other) {
      return (w - other.w);
}}
ArrayList<NW> L = new ArrayList();
ArrayList<NW> L2 = new ArrayList();
PriorityQueue<NW> Q = new PriorityQueue();
for (int i = 0; i < N; i++) {
   Q.add(new NW(
      i, Integer.MAX_VALUE / 2, -1));
}
while (!Q.isEmpty()) {
   NW nw = Q.poll();
   int k = nw.i;
   if (V[k].inTree) continue;
   V[k].inTree = true;
   L.add(nw);
   for (Edge e: V[k].adj) {
      if (V[e.target].inTree) continue; 
      Q.add(new NW(e.target,e.weight,k));
}}
for(int i = 0; i < L.size(); i++) {
    if(L.get(i).p >= 0) L2.add(L.get(i));
}