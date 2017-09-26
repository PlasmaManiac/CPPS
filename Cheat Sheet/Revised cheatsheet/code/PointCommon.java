double angle(Point a, Point o, Point b) {
    Point oa = new Point(o, a);
    Point ob = new Point(o, b);
    double A = oa.x*ob.x + oa.y*ob.y;
    double B = oa.x*oa.x + oa.y*oa.y;
    double C = ob.x*ob.x + ob.y*ob.y;
    return Math.acos(A / Math.sqrt(B*C));
}
double ccwAngle(Point a, Point o, Point b) {
    double A = angle(a, o, b);
    if (cross(0, a, b) > 0) {
        A = (-A) + (2 * Math.PI);
}}
double cross(Point p, Point q, Point r) {
    Point pq = new Point(p, q);
    Point pr = new Point(p, r);
    return (pq.x * pr.y - pq.y * pr.x);
}
double dot(Point p, Point q) {
    return (q.x*p.x + q.y*p.y);
}
void rotate(Point p, double angle) {
    angle = Math.toRadians(angle);
    double xNew = p.x*Math.cos(angle)
            - p.y*Math.sin(angle);
    double yNew = p.x*Math.sin(angle)
            + p.y*Math.cos(angle);
    p.x = xNew; p.y = yNew;
}
void scale(Point p, double factor) {
    p.x *= factor; p.y *= factor;
}
void translate(Point p,double X,double Y){
        p.x += X; p.y += Y;
}