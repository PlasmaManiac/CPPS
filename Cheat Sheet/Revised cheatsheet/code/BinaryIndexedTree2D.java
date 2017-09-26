int[][] BIT = new int[SIZE][SIZE];
void add(int x, int y, int val) {
    while (x < SIZE) {
        addY(x, y, val);
        x += (x & -x);
}}
void addY(int x, int y, int val) {
    while (y < SIZE) {
        BIT[x][y] += val;
        y += (y & -y);
}}
int sum(int x1, int y1, int x2, int y2) {
    return (sum(x2, y2) + sum(x1-1, y1-1) 
        - sum(x1-1, y2) - sum(x2, y1-1));
}
void set(int x, int y, int val) {
    add(x, y, val - sum(x, y, x, y));
}
int sum(int x, int y) {
    int sum = 0;
    while (x > 0) {
        sum += sumY(x, y);
        x -= (x & -x);
    }
    return sum;
}
int sumY(int x, int y) {
    int sum = 0;
    while (y > 0) {
        sum += BIT[x][y];
        y -= (y & -y);
    }
    return sum;
}