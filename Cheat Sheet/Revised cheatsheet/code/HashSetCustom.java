HashSet<VeryProblemSuchScareSoWow> set;
class VeryProblemSuchScareSoWow {
   Key key; Values v1, v2;
   @Override
   public int hashCode() { 
      return key.hashCode(); 
   }@Override
   public boolean equals(Object o) {
      boolean a = v1 == ((
         VeryProblemSuchScareSoWow) o).v1;
      a = a && v2 == ((
         VeryProblemSuchScareSoWow) o).v2;
      return a; //True if equal
}}