String[] a = {"cow","cat","monkey","pig","hi"};
Arrays.sort(a,new Comparator<String>() {
    public int compare(String s1, String s2) {
        //If s1 > s2 (when sorting in increasing order), return positive. If s1==s2, return 0. else, return negative.
            return(s1.length()-s2.length());
}});
//Sort in increasing order based on length
//Out: hi, cow, cat, pig, monkey