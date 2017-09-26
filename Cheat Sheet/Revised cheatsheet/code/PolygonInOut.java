int j = P.size()-1, c = 0;
for (int i = 0; i < P.size(); j = i++) {
    Point a = P.get(i), b = P.get(j);
    if (b.y <= q.y && q.y < a.y
            && cross(q, b, a) > 0) {
        c++;
    } if (a.y <= q.y && q.y < b.y
            && cross(q, b, a) < 0) {
        c--;
}}
return c;