if (P.size() < 3) return false;
P.add(P.get(0)); P.add(P.get(1));
boolean CCW = cross(P.get(0), P.get(1), 
      P.get(2)) > 0;
for(int i = 1, i < P.size()-2; i++) {
    if (CCW ^ cross(P.get(i), P.get(i+1), 
          P.get(i+2)) > 0) {
        return false;
}}
return true;