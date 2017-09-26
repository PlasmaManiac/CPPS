double EPS = Math.pow(10, -8);
class Point implements Comparable<Point> {
    double x, y;
    Point() { this(0.0, 0.0); }
    Point(Point p) { this(p.x, p.y);}
    Point(double X, double Y) {x=X; y=Y;}
    Point(Point p, Point q){
        this(q.x-p.x,q.y-p.y);
    }
    boolean equals(Point p) {
        return ((Math.abs(x-p.x) < EPS) && 
                (Math.abs(y-p.y) < EPS));
    }
    public int compareTo(Point p) {
        if (equals(p)) {
            return 0;
        } else if (Math.abs(x-p.x) < EPS){
           return (int)Math.signum(y-p.y);
        } else {
           return (int)Math.signum(x-p.x);
}}}
class Line {
    Point a, b;
    Line(Point A, Point B) { a=A; b=B; }
    boolean isParallel(Line l) {
        double d=(a.x-b.x) * (l.a.y-l.b.y)
              - (a.y-b.y) * (l.a.x-l.b.x);
        return (Math.abs(d) < EPS);
}}
class Circle {
    Point c;//Center
    double r;//Radius
    Circle(Point C, double R){ c=C; r=R; }
}