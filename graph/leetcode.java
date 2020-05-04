import java.util.*;

class leetcode{
    
    static string calldfs(int r, int c, int n, int m,int[][] board){

        if(board[r][c]!=1) return "";

        board[r][c] = 2;
        String s = "";
        if(r-1>=0){
            s = s +"t";
            s = s + calldfs(r-1,c,n,m, board);
            s = s +"t";
        }
        if(c-1>=0){
            s = s +"l";
            s += calldfs(r,c-1,n,m,str+"l", board);
        }
        if(r+1<n){
            s = s +"d";
            s +=calldfs(r+1,c,n,m,str+"d", board);
        }
        if(c+1<m){
            s = s +"r";
            s += calldfs(r,c+1,n,m,str+"r", board);
        }

        return s;
    }
    
    static void distinctIslands(int[][] board){

        int n = board.length;
        int m = board[0].length;

        ArrayList<String> list = new ArrayList<>();
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){

                if(board[i][j] == 1){

                    String str = calldfs(i, j,n,m, "",board);
                    
                    for(String rr: list){
                        if(!list.contains(str))
                            list.add(str);
                    }
                }
            }
        }
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
}