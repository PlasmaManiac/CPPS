BellmandFord(source);
for (int i = 0; i < N; i++) {
   for (Edge e: V[i].adj) {
      int newD=V[i].dist+e.weight;
      if (newD<V[e.target].dist){
         return true; //Neg weight cycle
}}}
return false; //No negative cycle found
