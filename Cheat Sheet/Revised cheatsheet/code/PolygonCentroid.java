P.add(P.get(0));//1st point added to end
double cX = 0.0, cY = 0.0, area = 0.0;
for (int i = 0; i < P.size()-1; i++) {
    Point p = P.get(i), q = P.get(i+1);
    area += p.x*q.y - q.x*p.y;
    cX += (p.x+q.x) * (p.y*q.x - p.x*q.y);
    cY += (p.y+q.y) * (p.y*q.x - p.x*q.y);
}
area = Math.abs(area) * 3;
cX /= area;
cY /= area;
return new Point(cX, cY);