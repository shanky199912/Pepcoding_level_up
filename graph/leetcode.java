import java.util.*;

class leetcode{
    
     //number of distinct islands
    static string calldfs(int r, int c, int n, int m, int[][] board){

        board[r][c] = 2;
        String s = "";
        if(r-1>=0 && board[r][c]==1){
            s = s +"t";
            s = s + calldfs(r-1,c,n,m, board);
            s = s +"b";
        }
        if(c-1>=0 && board[r][c]==1){
            s = s +"l";
            s += calldfs(r,c-1,n,m, board);
            s = s + "b";
        }
        if(r+1<n && board[r][c]==1){
            s = s +"d";
            s +=calldfs(r+1,c,n,m,board);
            s = s + "b";
        }
        if(c+1<m && board[r][c]==1){
            s = s +"r";
            s += calldfs(r,c+1,n,m, board);
            s = s + "b";
        }

        return s;
    }
    
    static int distinctIslands(int[][] board){

        int n = board.length;
        int m = board[0].length;

        ArrayList<String> list = new ArrayList<>();
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(board[i][j] == 1){

                    String str = calldfs(i, j,n,m, board);
                    
                    for(String rr: list){
                        if(!list.contains(str)){
                            list.add(str);
                        }
                    }
                }
            }
        }

        return list.size();
    }
    
    //1091=========================================
    public int shortestPathBinaryMatrix(int[][] grid) {
        
        int n = grid.length;
        if(n==0)return 0;
        
        int m = grid[0].length;
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        
        if(n==1 && grid[0][0]==0)return 1;
        
        int[][] dir = {{-1, -1}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {1, 1}}; 
        
        LinkedList<Integer> que = new LinkedList<>();
        que.addLast(0);
        grid[0][0] = 1;
        
        int level =1;
        while(que.size()!=0){
            int size = que.size();
            while(size-- >0){
                int vtx = que.removeFirst();
                
                //1d to 2d conver
                int r = vtx/m;
                int c = vtx%m;
                
                if(r == n-1 && c == m-1)return level;
                
                for(int d=0; d<8; d++){
                    
                    int x = r + dir[d][0];
                    int y = c + dir[d][1];
                    
                    if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0){
                        que.addLast(x*m + y); //2d to 1d conver
                        grid[x][y] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }

    //286===========================================
    public void wallsAndGates(int[][] rooms) {
        
        int n = rooms.length;
        if(n == 0)return;

        int m = rooms[0].length;

        int[][] dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}}; 
        
        LinkedList<Integer> que = new LinkedList<>();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(rooms[i][j] == 0){
                    que.addLast(i*m + j);
                }
            }
        }

        int level = 1;
        while(que.size()!=0){
            int size = que.size();
            while(size-- >0){
                int vtx = que.removeFirst();

                int r = vtx/m;
                int c = vtx%m;

                for(int d=0; d<4; d++){
                    int x = r + dir[d][0];
                    int y = c + dir[d][1];

                    if(x>=0 && x<n && y>=0 && y<m && rooms[x][y]==2147483647){
                        que.addLast(x*m + y);
                        rooms[x][y] = level;
                    }
                }
            }
            level++;
        }
    }

    //329 ============================================
    public int longestIncreasingPath(int[][] board) {
        
        if(board.length==0 || board[0].length==0) return 0;
        
        int n = board.length;
        int m = board[0].length;
        
        int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int[][] indegree = new int[n][m];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int d=0; d<4; d++){
                    
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];
                    
                    if(x>=0 && x<n && y>=0 && y<m && board[x][y] > board[i][j]){
                        indegree[x][y]++;
                    }
                        
                }
            }
        }
        
        LinkedList<Integer> que = new LinkedList<>();
        
        for(int i=0; i<n ;i++){
            for(int j=0; j<m; j++){
                if(indegree[i][j] == 0)
                    que.addLast(i*m + j);
            }
        }
        
        int length = 0;
        
        while(que.size()!=0){
            int size = que.size();
            
            while(size-- >0){
                int vtx = que.removeFirst();
                
                int i = vtx/m;
                int j = vtx%m;
                
                for(int d =0; d<4; d++){
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];
                    
                    if(x>=0 && x<n && y>=0 && y<m && board[x][y] > board[i][j] && --indegree[x][y]==0){
                        que.addLast(x*m + y);
                    }
                }
                
            }
            length++;
        }
        return length;
    }

    //leetcode-839==================================================
    int[] par;
    
    public int findPar(int vtx){

        if(par[vtx] == vtx) return vtx;
        return par[vtx] = findPar(par[vtx]);
    }

    public boolean isSimilar(String P, String Q){

        int count = 0;
        for(int i=0; i<P.length(); i++){

            if(P.charAt(i) != Q.charAt(i) && ++count >2)
                return false;
        }
        return true;
    }

    public int numSimilarGroups(String[] A) {

        int n = A.length;
        par = new int[n];
        for(int i=0; i<n; i++) //O(N)
            par[i] = i;

        //int groups = n;
        for(int i=0; i<n; i++){
            for(int j= i+1; j<n; j++){ //O(N2)

                if(isSimilar(A[i],A[j])){ //O(W) - W =  word length
                    int p1 = findPar(i); //O(4) - findPar at max takes O(4) time
                    int p2 = findPar(j); // as the height of tree can be at max 4.

                    if(p1 != p2){
                        par[p2] = p1;
                        //groups--;
                    }
                }
            }
        }
        
        int groups = 0;
        for(int i=0; i<n; i++){
            if(par[i] == i) groups++;
        }
        return groups;
    }

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        
        ArrayList<int[]>[] graph = new ArrayList[n];
        for(int i=0; i<n; i++){
            graph[i] = new ArrayList<int[]>();
        }
        
        for(int[] ar: flights){
            graph[ar[0]].add(new int[]{ar[1],ar[2]});
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((int[] a, int[] b)->{
            return a[0]- b[0];
        });

        boolean[] vis = new boolean[n];
        pq.add(new int[]{0,src,0}); //weigth, vertex, stop
        int min = (int)1e7;

        while(pq.size()!=0){
            int size = pq.size();
            while(size-- >0){
                int[] vtx = pq.poll();

                if(vtx[1] == dst){
                    if(vtx[0] < min){
                        min = vtx[0];
                    }
                }

                vis[vtx[1]] = true;

                if(vtx[2] > K)
                    continue;

                for(int[] e : graph[vtx[1]]){
                    if(!vis[e[0]]){
                        pq.add(new int[]{vtx[0] + e[1], e[0], vtx[2] + 1});
                    }
                }
            }
        }

        if(min == (int)1e7)return -1;
        else return min;
    }

    //number of distinct islands
}