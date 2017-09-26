int[] BIT = new int[SIZE];
void add(int i, int val) {
    while (i < SIZE) {
        BIT[i] += val;
        i += (i & -i);
}}
int sum(int i, int j) {
    return sum(j) - sum(i - 1);
}
void set(int i, int val) {
    add(i, val - sum(i, i));
}
int sum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}