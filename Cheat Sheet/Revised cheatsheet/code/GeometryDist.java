double dist(Point p, Point q) {
    if (p.equals(q)) return 0.0;
    return Math.sqrt((q.x-p.x) * (q.x-p.x)
            + (q.y-p.y) * (q.y-p.y));
}
double dist(Point p, Line l) {
    Point ap = new Point(l.a, p);
    Point ab = new Point(l.a, l.b);
    double u = ap.x*ab.x + ap.y*ab.y;
    u /= (ab.x*ab.x + ab.y*ab.y);
    //Remove if's, if l not linesegment
    if (u < 0.0) return dist(p, l.a); 
    if (u > 1.0) return dist(p, l.b); 
    ab.x *= u; ab.y *= u;
    ab.x += l.a.x; ab.y += l.a.y;
    return dist(p, ab);
}
double dist(Point p, Circle c) {
    return Math.max(0, dist(p, c.c)-c.r);
}
double dist(Circle c, Line l) {
    return Math.max(0, dist(c.c, l)-c.r);
}
double dist(Circle c1, Circle c2) {
    return Math.max(0, 
        dist(c1.c, c2.c) - c1.r - c2.r);
}