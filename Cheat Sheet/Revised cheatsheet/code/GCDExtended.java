int c, x = 0, y = 1;
void ExtendedEuclid(int a, int b) {
    if (a == 0) c = b;
    else {
        ExtendedEuclid(b % a, a);
        int temp = x;
        x = y - x * (b / a);
        y = temp;
}}