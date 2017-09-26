P.add(P.get(0));//1st point added to end
double area = 0.0;
for (int i = 0; i < P.size()-1; i++) {
    Point p = P.get(i), q = P.get(i+1);
    area += p.x*q.y - q.x*p.y;
}
area = Math.abs(area) * 0.5;
return area;