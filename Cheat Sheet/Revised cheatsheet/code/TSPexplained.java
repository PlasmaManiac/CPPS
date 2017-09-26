
class TSPexplained {

    int n = 1000;
    int[] A = new int[n];//Temp array
    int[] tour = new int[n]; //Best tour
    int[][] D = new int[n][n]; //D is an adjacency matrix for the nodes, where D[i][j] contains the distance from node i to j
    

    public static void main(String[] args) {
        new TSPexplained().run();
    }

    public void run() {
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i==j) D[i][j] = 0;
                else D[i][j]=Integer.MAX_VALUE/2;
            }
        }
        //Here's the point you fill D with all known distances
        
        for (int i = 0; i < n; i++) {
            tour[i] = i;
        }
        
        TSP(0, 0, Integer.MAX_VALUE / 2);
    }

    /**
     * Calculate the minimum length of a tour through all nodes by recursively building it, visiting each node exactly once
     * @param i refers to the number of nodes in the tour, initially 0
     * @param L equals the current length of the tour, initially 0
     * @param best refers to the best length of a tour found so far, initially 'infinity'
     * @return best length of a tour found so far
    */
    int TSP(int i, int L, int best) {
        if (i == n - 1 && (L + D[A[i]][1]) < best) { //Possible tour made, best one yet found
            best = L + D[A[i]][1]; //Update best length
            tour[i] = A[i]; //Put node A[i] in the tour
        } else if (i == n - 1) { //Possible tour found, some previous tour was better
        } else { //For all nodes j, with i<j<n, try node j as node i+1 in the tour
            for (int j = i + 1; j < n; j++) {
                int temp = A[j];//Swap A[i] with A[j]
                A[j] = A[i + 1];
                A[i + 1] = temp;
                int L2 = L + D[A[i]][A[i + 1]]; //Calculate new length of tour, with i+1 included
                if (L2 < best) { //Only recurse if better tour is possible (pruning)
                    int R = TSP(i + 1, L2, best);
                    if (R < best) { //If better tour is found
                        best = R; //Update length
                        tour[i] = A[i]; //Put node A[i] in the tour
                    }
                }
                A[i + 1] = A[j]; //Swap back
                A[j] = temp;
            }
        }
        return best;
    }
}
