class Node {
   Node[] C = new Node[26];//children
   Character ch;//last char of prefix
   Node P;//parent
   boolean used;//prefix in dictionary
   int nOC = 0;//number of children
   Node(Character c,boolean u,Node p){..}
   void insert(char[] W, int I) {
      if (C[W[I] - 'A'] == null) {
         nOC++;
         C[W[I]-'A'] = 
            new Node(W[I],true,this);
         if (I != W.length - 1) {
            C[W[I]-'A'].used=false;
            C[W[I]-'A'].insert(W,I+1);
         }
      } else if (I == W.length - 1) {
         C[W[I] - 'A'].used = true;
      } else {
         C[W[I] - 'A'].insert(W, I + 1);
   }}
   Node search(char[] W, int I) {
      if (I == W.length - 1) {
         return C[W[I]-'A'];
      } else if (C[W[I]-'A'] == null) {
         return null;
      } else {
         return C[W[I]-'A'].search(W,I+1);
   }}
   //Removes this subtree+nodes above if
   //they are redundant
   void trieCleanup() {
      if (P != null) {
         P.C[ch - 'A'] = null;
         P.nOC--;
         if (P.nOC == 0 && !P.used) {
            P.trieCleanup();
}}}}
void removePrefix(char[] W) {
   Node R = root.search(W, 0);
   if (R != null) {
      R.trieCleanup();
}}
void removeWord(char[] W) {
   Node R = root.search(W, 0);
   if (R == null) {
   } else if (R.nOC == 0) {
      R.trieCleanup();
   } else {
      R.used = false;
}}