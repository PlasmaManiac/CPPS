ArrayList<Point> R = new ArrayList();
double D = dist(c1.c, c2.c);
if (D > c1.r+c2.r || D+Math.min(c1.r,c2.r)
        < Math.max(c1.r, c2.r)) return R;