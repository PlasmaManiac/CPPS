class Line {
    Point p, q;
    Line(Point P, Point Q) { p=P; q=Q; }
    double dist(Point p) { 
        return p.dist(this); 
    }
    Point intersection(Line l) {
        if (isParallel(l)) return null;
        double d=(p.x-q.x) * (l.p.y-l.q.y) 
              - (p.y-q.y) * (l.p.x-l.q.x);
        double A=p.x*q.y - p.y*q.x;
        double B=l.p.x*l.q.y -l.p.y*l.q.x;
        double x=(A*(l.p.x - l.q.x) 
              - (p.x - q.x)*B) / d;
        double y=(A*(l.p.y - l.q.y) 
              - (p.y - q.y)*B) / d;
        //Remove this if, if this
        //line is not a line segment
        if (x < Math.min(p.x,q.x) 
              || x>Math.max(p.x,q.x)
              || y<Math.min(p.y,q.y) 
              || y>Math.max(p.y,q.y)) {
            return null;//No intersection
        }
        //Remove if, if l not line segment
        if (x<Math.min(l.p.x,l.q.x) 
              || x>Math.max(l.p.x,l.q.x)
              || y<Math.min(l.p.y,l.q.y)
              || y>Math.max(l.p.y,l.q.y)) {
            return null;//No intersection
        }
        return new Point(x, y);
    }
    boolean isParallel(Line l) {
        double d=(p.x-q.x) * (l.p.y-l.q.y)
              - (p.y-q.y) * (l.p.x-l.q.x);
        return (Math.abs(d) < EPS);
}}