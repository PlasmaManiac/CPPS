int[] dx ={-1,0,1,0};//Can be extended for
int[] dy ={0,1,0,-1};//diagonal adjacency 
Node[][] V;
void DFS(int x, int y) {
    V[x][y].visited = true;
    for (int i = 0; i < 4; i++) {
        if ((x+dx[i],y+dy[i]).inBounds()&&
                !(V[x][y].visited ||
                 V[x][y].obstacle)){
            DFS(x+dx[i],y+dy[i]);
}}}//Use i<8 to support diagonal adjacency