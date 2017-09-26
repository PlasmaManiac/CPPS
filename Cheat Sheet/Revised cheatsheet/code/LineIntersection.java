Point intersection(Line l1, Line l2) {
    if (l1.isParallel(l2)) return null;
    Point a = l1.a, b = l1.b;
    Point c = l2.a, d = l2.b;
    double D = (a.x-b.x) * (c.y-d.y) 
          - (a.y-b.y) * (c.x-d.x);
    double A = a.x*b.y - a.y*b.x;
    double B = c.x*d.y - c.y*d.x;
    double x = (A * (c.x - d.x) 
          - (a.x - b.x) * B) / D;
    double y = (A * (c.y - d.y) 
          - (a.y - b.y) * B) / D;
    //Remove if, if l1 not line segment
    if ((x+EPS)<Math.min(a.x,b.x) 
            || (x-EPS)>Math.max(a.x,b.x)
            || (y+EPS)<Math.min(a.y,b.y) 
            || (y-EPS)>Math.max(a.y,b.y)){
        return null;//No intersection
    }
    //Remove if, if l2 not line segment
    if ((x+EPS)<Math.min(c.x,d.x) 
            || (x-EPS)>Math.max(c.x,d.x)
            || (y+EPS)<Math.min(c.y,d.y)
            || (y-EPS)>Math.max(c.y,d.y)){
        return null;//No intersection
    }
    return new Point(x, y);
}