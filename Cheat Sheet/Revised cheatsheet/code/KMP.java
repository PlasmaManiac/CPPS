int[] PM = new int[m];//Parial Match Table
void kmpPreProcess() {
    int i = 0, j = -1;
    PM[0] = -1;
    while (i < m) {
        while (j >= 0 && pattern[i] != pattern[j]) {
            j = PM[j];
        }
        i++; j++;
        PM[i] = j;
}}
void kmpSearch() {
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && text[i] != pattern[j]) {
            j = PM[j];
        }
        i++; j++;
        if (j == m) {//Match at index i-j
            //Last char of pattern at i-1 
            solution.add(i-j);
            j =PM[j];
}}}