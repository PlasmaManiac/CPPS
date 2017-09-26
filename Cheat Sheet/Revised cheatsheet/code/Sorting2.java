Item[] items;
Arrays.sort(items);
class Item implements Comparable<Item> {
    int price, reliability, coolfactor;
    public int compareTo(Item other) {
        //If a>other.b (when sorting in increasing order), return positive. If a==other.b, return 0. else, return negative.
        return other.price-price;//Same:
        if(price < other.price) return 1;
        if(price > other.price) return -1;
        return 0;
}}
//Sort in decreasing order based on item price