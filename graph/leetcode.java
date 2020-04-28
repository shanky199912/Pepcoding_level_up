import java.util.*;

class leetcode{
    
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
}