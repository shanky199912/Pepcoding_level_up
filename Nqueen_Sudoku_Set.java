import java.util.ArrayList;

class  Nqueen_Sudoku_Set{
    public static void main(String[] args){

        solve();
    }

//-----COIN CHANGE SET----------------------------

    static int coin_permute_infinte(int[] coins, int target,  String asf){
        if(target == 0){
            System.out.println(asf);
            return 1;
        }

        int count = 0;

        for(int i=0;i<coins.length;i++){
            if(target - coins[i] >=0){
                count += coin_permute_infinte(coins, target - coins[i], asf + coins[i]);
            }
        }

        return count;
    }

    
    static int coin_comb_infinte(int[] coins, int target, int ci, String asf){
        if(target == 0){
            System.out.println(asf);
            return 1;
        }

        int count = 0;

        for(int i = ci ; i < coins.length ; i++){
            if(target - coins[i] >=0){
                count += coin_comb_infinte(coins, target - coins[i], i,  asf + coins[i]);
            }
        }

        return count;
    }

    static int coin_comb_with_oneCoin(int[] coins, int target, int ci, String asf){
        if(target == 0){
            System.out.println(asf);
            return 1;
        }

        int count = 0;
        for(int i = ci+1; i<coins.length;i++){
            if(target-coins[i] >=0){
                count += coin_comb_with_oneCoin(coins, target-coins[i], i, asf + coins[i]);
            }
        }

        return count;
    }

    static int coin_permute_with_oneCoin(int[] coins, int target, String asf , boolean[] vis){
        if(target == 0){
            System.out.println(asf);
            return 1;
        }

        int count = 0;
        for(int i = 0; i<coins.length;i++){
            if(vis[i] == false){
                vis[i] = true;
                if(target-coins[i] >=0){
                    count += coin_permute_with_oneCoin(coins, target-coins[i], asf + coins[i], vis);
                }
                vis[i] = false;
            }
        }

        return count;
    }

    static int coin_comb_with_oneCoin_02(int[] coins, int target, int idx, String asf){
        if(target == 0 || idx == coins.length){
           if(target == 0){
               System.out.println(asf);
               return 1;
           }
           return 0;
        }


        int count= 0;
        if(target-coins[idx]>=0){
            count +=coin_comb_with_oneCoin_02(coins,target-coins[idx],idx+1,asf+coins[idx]); 
        }
        count += coin_comb_with_oneCoin_02(coins,target,idx+1,asf);

        return count;
    }

    static int coin_comb_with_infiniteCoin_02(int[] coins, int target, int idx, String asf){
        if(target == 0 || idx == coins.length){
           if(target == 0){
               System.out.println(asf);
               return 1;
           }
           return 0;
        }


        int count= 0;
        if(target-coins[idx]>=0){
            count +=coin_comb_with_infiniteCoin_02(coins,target-coins[idx],idx,asf+coins[idx]); 
        }
        count += coin_comb_with_infiniteCoin_02(coins,target,idx+1,asf);

        return count;
    }

    static int coin_permute_with_infiniteCoin_02(int[] coins, int target, int idx, String asf){
        if(target == 0 || idx == coins.length){
           if(target == 0){
               System.out.println(asf);
               return 1;
           }
           return 0;
        }


        int count= 0;
        if(target-coins[idx]>=0){
            count +=coin_permute_with_infiniteCoin_02(coins, target-coins[idx], 0, asf+coins[idx]); 
        }
        count += coin_permute_with_infiniteCoin_02(coins,target,idx+1,asf);

        return count;
    }

    static int coin_permute_with_oneCoin_02(int[] coins, int target, int idx, String asf, boolean[] vis){
        if(target == 0 || idx == coins.length){
           if(target == 0){
               System.out.println(asf);
               return 1;
           }
           return 0;
        }


        int count= 0;
        if(vis[idx] == false){
            vis[idx] = true;
            if(target-coins[idx]>=0){
                count +=coin_permute_with_oneCoin_02(coins, target-coins[idx], 0, asf+coins[idx], vis); 
            }
            vis[idx] = false;
        }
        count += coin_permute_with_oneCoin_02(coins,target,idx+1,asf, vis);

        return count;
    }

    static int queen_in_boxes_permute_01(int[] boxes, int cq, int tq,  String asf, boolean[] vis){

        if(cq ==  tq){
            System.out.println(asf);
            return 1;
        }

        int count = 0;

        for(int i=0;i<boxes.length;i++){
            if(vis[i] == false){
                vis[i] = true;
                count += queen_in_boxes_permute_01(boxes, cq +1 , tq, asf + "b" + i + "q" + cq +" ", vis);
                vis[i] = false;
            }
        }
        return count;
    }

    static int queen_in_boxes_combine_01(int len, int cq, int tq, int cidx, String asf){

        if(cq ==  tq){
            System.out.println(asf);
            return 1;
        }

        int count = 0;

        for(int i=cidx + 1 ; i < len;i++){
                count += queen_in_boxes_combine_01(len, cq +1 , tq, i, asf + "b" + i + "q" + cq +" ");
        }
        return count;
    }

//-----NQUEEN SET--------------------------

    public static boolean isQueenSafe(boolean[][] board, int row, int col){

        int[][] dir = {{0,-1},{-1,-1},{-1,0},{-1,1}};

        for(int d=0; d<dir.length;d++){

            for(int rad=1; rad<=board.length; rad++){

                int r = row + rad*dir[d][0];
                int c = col + rad*dir[d][1];

                if(r>=0 && c>=0 && r<board.length && c<board[0].length){
                    if(board[r][c])
                        return false;
                }
                else
                    break;
            }
        }
        return true;
    }

    public static int nqueen_01(boolean[][] board, int tq, int cqpi, String asf){

        if(tq == 0){
            System.out.println(asf);
            return 1;
        }

        int count = 0;

        for(int b = cqpi + 1; b<board.length * board[0].length; b++){

            int row = b/board.length;
            int col = b%board.length;

            if(isQueenSafe(board, row, col)){
                board[row][col] = true;
                count+= nqueen_01(board, tq-1, b, asf + "(" + row + "," + col + ")");
                board[row][col] = false;
            }
        }
        return count;
    }

    static boolean[] rowA = new boolean[n];
    static boolean[] colA = new boolean[n];
    static boolean[] diag = new boolean[n+m-1];
    static boolean[] adiag = new boolean[n+m-1];

    public static int nqueen_02(int n, int m, int tq, int cqpi, String asf){

        if(tq == 0){
            System.out.println(asf);
            return 1;
        }

        int count = 0;

        for(int b = cqpi + 1; b < n * m; b++){

            int row = b/m;
            int col = b%m;

            if(!rowA[row] && !colA[col] && !diag[row-col + m-1] && !adiag[row + col]){

                rowA[row] = true;
                colA[col] = true;
                diag[row-col+m-1]= true;
                adiag[row+col] = true;

                count+= nqueen_02(n, m, tq-1, b, asf + "(" + row + "," + col + ")");

                rowA[row] = false;
                colA[col] = false;
                diag[row-col+m-1]= false;
                adiag[row+col] = false;
            }
        }
        return count;
    }
    
    static int row_ = 0;
    static int col_ = 0;
    static int diag_ =0;
    static int adiag_ =0;

    public static int nqueen_03(int n, int m, int tq, int cqpi, String asf){

        if(tq == 0){
            System.out.println(asf);
            return 1;
        }

        int count = 0;

        for(int b = cqpi + 1; b < n * m; b++){

            int row = b/m;
            int col = b%m;

            //maskX = (1<<row) 
            //maskY = (1<<col)
            if(((row_ & (1<<row))==0) && ((col_ & (1<<col))==0) && ((diag_ & (1<<row-col+m-1))==0) &&  ((adiag_ & (1<<row+col))==0) ){

                //we can also use ^ operator instead of | , coz from if we are getting the false.
                // so agar pehle se false ho to xor opeartor use kr skte hai.
                row_ |= (1<<row);
                col_ |= (1<<col);
                diag_ |= (1<<row-col+m-1);
                adiag_ |= (1<<row+col);

                count+= nqueen_03(n, m, tq-1, b, asf + "(" + row + "," + col + ")");

                row_ &= ~(1<<row);
                col_ &= ~(1<<col);
                diag_ &= ~(1<<row-col+m-1);
                adiag_ &= ~(1<<row+col);

            }
        }
        return count;
    }
    

//-------Sudoku-Set-----------------------------

    public static boolean isSafeToPlaceNumber(int[][] board, int row, int col, int num){

        //row ka check
        for(int i=0;i<board[0].length;i++){
            if(board[row][i] == num)
                return false;
        }   
    
        //col ka check
        for(int j=0;j<board.length;j++){
            if(board[j][col] == num)
                return false;
        }
    
        //sub matrix ka check
        int x = (row/3)*3; // 2,5 = 2/3 =0 && 5/3=1 => 0*3 , 1*3 = (0,3);
        int y = (col/3)*3;

        for(int i=0;i<3;i++){
            for(int j = 0;j<3;j++){
                if(board[x+i][y+j] == num)
                    return false;
            }
        }

        return true;
    }

    public static int sudoku_01(int[][] board, int idx){

        if(idx == board.length * board.length){
            display(board);
            return 1;
        }

        int count = 0;
        int row = idx/board.length;
        int col = idx%board.length;

        if(board[row][col] == 0){
            for(int num=1;num<=9;num++){
                if(isSafeToPlaceNumber(board, row, col, num)){
                    board[row][col] = num;
                    count += sudoku_01(board, idx+1);
                    board[row][col] = 0;
                }
            }
        }
        else
            count+= sudoku_01(board, idx+1);

        return count;
    }

    public static boolean sudoku_01_ek_hi_ans(int[][] board, int idx){

        if(idx == board.length * board.length){
            display(board);
            return true;
        }

        boolean res = false;
        int row = idx/board.length;
        int col = idx%board.length;

        if(board[row][col] == 0){
            for(int num=1;num<=9;num++){
                if(isSafeToPlaceNumber(board, row, col, num)){
                    board[row][col] = num;
                    res = res || sudoku_01_ek_hi_ans(board, idx+1);
                    board[row][col] = 0;
                }
            }
        }
        else
            res= res ||sudoku_01_ek_hi_ans(board, idx+1);

        return res;
    }

    static int[] rowA_;
    static int[] colA_;
    static int[][] mat_;

    public static boolean sudoku_03(int[][] board, int idx, ArrayList<Integer> calls){

        if(idx == calls.size()){
            display(board);
            return true;
        }

        boolean res = false;
        int row = calls.get(idx)/board.length;
        int col = calls.get(idx)%board.length;

        if(board[row][col] == 0){
            for(int num=1;num<=9;num++){
                int mask = (1<<num);

                if((rowA_[row] & mask)==0 && (colA_[col] & mask)==0 && (mat_[row/3][col/3] & mask) == 0){

                    board[row][col] = num;
                    rowA_[row] ^= mask;
                    colA_[col] ^= mask;
                    mat_[row/3][col/3] ^= mask;

                    res = res || sudoku_03(board, idx+1, calls);

                    board[row][col] = 0;
                    rowA_[row] ^= mask;
                    colA_[col] ^= mask;
                    mat_[row/3][col/3] ^= mask;
                }
            }
        }
        else
            res= res || sudoku_03(board, idx+1, calls);

        return res;
    }

    public static void display(int[][] arr){

        for(int[] ar:arr){
            for(int ele:ar){
                System.out.print(ele + " ");
            }

            System.out.println();
        }
    }

    public static void SudokuSet(){
        
        int board[][] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}
        };  

        rowA_ = new int[9];
        colA_ = new int[9];
        mat_ = new int[3][3];
                
        ArrayList<Integer> calls = new ArrayList<>();
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == 0){
                    calls.add(i*9 + j);// 2d to 1d array conversion.
                } 
                else{
                    int mask = (1<<board[i][j]);
                    if((rowA_[i] & mask)==0 && (colA_[j] & mask)==0 && (mat_[i/3][j/3] & mask) == 0){
                        rowA_[i] ^= mask;
                        colA_[j] ^= mask;
                        mat_[i/3][j/3] ^= mask;
                    }
                }
            }
        }
        // System.out.println(sudoku_01(board, 0));
        // System.out.println("-----");
        // System.out.println(sudoku_01_ek_hi_ans(board,0));

        System.out.println(sudoku_03(board, 0, calls));

    }

    public static void coinchangeSet(){

    }

    public static void NqueenSet(){

    }

    public static void solve(){
        coinchangeSet();
        NqueenSet();
        SudokuSet();
    }
}