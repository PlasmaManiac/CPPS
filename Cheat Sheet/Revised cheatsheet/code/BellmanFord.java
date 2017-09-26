V[S].dist = 0;
for (int k = 1; k < N; k++) {
   for (int i = 0; i < N; i++) {
      for (Edge e: V[i].adj) {
         int newD=V[i].dist+e.weight;
         if (newD < V[e.target].dist){
            V[e.target].dist = newD;
            V[e.target].parent = i;
}}}}