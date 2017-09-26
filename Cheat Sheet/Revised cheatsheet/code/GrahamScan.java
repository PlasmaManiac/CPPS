if (P.size() <= 3) return P;
int low = 0;
for (int i = 1; i < P.size(); i++) {
    if (P.get(i).y < P.get(low).y) low=i;
}
Collections.swap(P, 0, low);
Point base = new Point(
        P.get(0).x + 1, P.get(0).y);
P.get(0).angle = 0;
for (int i = 1; i < P.size(); i++) {
    P.get(0).angle = ccwAngle(
            base, P.get(0), P.get(i));
}
Collections.sort(P);//Sort on angle
ArrayList<Point> R = new ArrayList();
R.add(P.get(0)); R.add(P.get(1));
int j = 1;
for (int i = 2; i < P.size(); i++) {
    while (cross(R.get(j-1), R.get(j), 
            R.get(i) < 0) < 0) { 
        R.remove(j--);
    }
    R.add(P.get(i));
    j = i;
}
return R;