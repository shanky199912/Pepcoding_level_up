// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        // System.out.println("Hello World!");
        int[][] board = {{-1,-1,-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1,-1,-1}
                        };
     
        knightsTour(board, 0,0, 0);
        display(board);
    }
    
    public static void display(int[][] arr){
        for(int[] ar: arr){
            for(int ele: ar)
                System.out.print(ele + " ");
            System.out.println();
        }
    }
    
    static int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2}; 
    static int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1}; 
    
    public static boolean knightsTour(int[][] board, int sr, int sc, int steps){
        
        board[sr][sc] = steps;
        
        if(steps == 63){
            return true;
        }
        
        for(int d = 0; d < xMove.length; ++d){
            int r = sr + xMove[d];
            int c = sc + yMove[d];
            
            if(r >=0 && c >=0 && r < 8 && c < 8 && board[r][c] == -1){
                boolean ans = knightsTour(board, r ,c, steps + 1);
                if(ans)
                    return true;
            }
        }
        
        board[sr][sc] = -1;
        return false;
    }
}