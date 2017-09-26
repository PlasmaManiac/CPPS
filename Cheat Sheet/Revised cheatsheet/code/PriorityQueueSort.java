PriorityQueue<Type> Q=new PriorityQueue();
class Type implements Comparable<Type> {
   @Override
   public int compareTo(Type o) {
      return -1;//if this comes before o
      return 0;//if it doesn't matter
      return 1;//if o comes before this      
}}