import java.util.*;

public class Code{
    public static void main(String[] args) {

        solve();
    }

    static void solve(){
        //floodfill_tree();
        permutation_combination();
    }

    static void floodfill_tree(){
        // int ans = printPath_height(0, 0, 3, 3, board);
        // System.out.println(ans);

        // Pair ans1 = printPath_Smallest(0, 0, 3, 3, board);
        // System.out.println(ans1.str + "->"+ ans1.len);
    }

    static void permutation_combination(){
        // System.out.println(coin_permute_infinte(new int[]{2,3,5,7}, 10, ""));
        // System.out.println("----------");
        // System.out.println(coin_comb_infinte(new int[]{2,3,5,7}, 10,0, ""));
        // System.out.println("-----------");
        // System.out.println(coin_comb_with_oneCoin(new int[]{2,3,5,7}, 10,-1, ""));
        // System.out.println("-----------");
        // System.out.println(coin_permute_with_oneCoin(new int[]{2,3,5,7}, 10, "", new boolean[4]));

        // System.out.println(coin_comb_with_infiniteCoin_02(new int[]{2,3,5,7}, 10, 0, ""));
        // System.out.println("----------");
        // System.out.println(coin_comb_with_oneCoin_02(new int[]{2,3,5,7}, 10,0, ""));
        // System.out.println("-----------");
        // System.out.println(coin_permute_with_infiniteCoin_02(new int[]{2,3,5,7}, 10,0, ""));
        // System.out.println("-----------");
        // System.out.println(coin_permute_with_oneCoin_02(new int[]{2,3,5,7}, 10, 0, "", new boolean[4]));

        System.out.println(queen_in_boxes_permute_01(new int[5], 0, 3, "", new boolean[5]));
        System.out.println(queen_in_boxes_combine_01(5, 0, 3, -1, ""));
    }

    static int[][]  dir = { {-1,0},{1,0},{0,1},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
    static String[] dirN = {"U","D","R","L","N","S","E","W"};

    public static int printPath_height(int sr, int sc, int er, int ec, int[][] board){
        if(sr == er && sc == ec){
            return 0;
        }

        board[sr][sc] = 2;
        int maxH = 0;
        for(int d=0;d<dir.length;d++){

            int r = sr + dir[d][0];
            int c = sc + dir[d][1];

            if(r>=0 && c>=0 && r<board.length && c<board[0].length && board[r][c] == 0){
                int recH = printPath_height(r, c, er, ec, board);
                maxH = Math.max(recH, maxH);
            }
        }

        board[sr][sc] = 0;
        return maxH+1;
    }

    static class Pair{
        int len = 0;
        String str ="";

        Pair(int len, String str){
            this.len = len;
            this.str = str;
        }
    }

    public static Pair printPath_Largest(int sr, int sc, int er, int ec, int[][] board){
        if(sr == er && sc == ec){
            return new Pair(0,"");
        }

        board[sr][sc] = 2;
        Pair mypair = new Pair(0,"");

        for(int d=0;d<dir.length;d++){

            int r = sr + dir[d][0];
            int c = sc + dir[d][1];

            if(r>=0 && c>=0 && r<board.length && c<board[0].length && board[r][c] == 0){
                Pair recpair= printPath_Largest(r, c, er, ec, board);
                
                if(recpair.len+1> mypair.len){
                    mypair.len = recpair.len + 1;
                    mypair.str = recpair.str + dirN[d];
                }
            }
        }

        board[sr][sc] = 0;
        return mypair;
    }

    public static Pair printPath_Smallest(int sr, int sc, int er, int ec, int[][] board){
        if(sr == er && sc == ec){
            return new Pair(0,"");
        }

        board[sr][sc] = 2;
        Pair mypair = new Pair((int)1e7 , "");

        for(int d=0;d<dir.length;d++){

            int r = sr + dir[d][0];
            int c = sc + dir[d][1];

            if(r>=0 && c>=0 && r<board.length && c<board[0].length && board[r][c] == 0){
                Pair recpair= printPath_Smallest(r, c, er, ec, board);
                
                if(recpair.len+1 < mypair.len){
                    mypair.len = recpair.len + 1;
                    mypair.str = recpair.str + dirN[d];
                }
            }
        }

        board[sr][sc] = 0;
        return mypair;
    }

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
}