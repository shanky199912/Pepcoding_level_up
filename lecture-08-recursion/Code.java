import java.util.HashSet;
public class Code{
    public static void main(String[] args){

        solve();
    }

    public static void solve(){
        //wordbreak();
        //crypto();
        //crossword();
        magnets();
    }

    static HashSet<String> map = new HashSet<>();

    public static void wordbreak(){
        String[] dic = {"i","like","ilike","sam","sung","samsung","and","man","go","mango"};
        for(String str:dic){
            map.add(str);
        }

        String str = "ilikesamsungandmango";
        System.out.println(wordbreak_(str,""));
    }

    public static int wordbreak_(String str, String ans){

        if(str.length() == 0){
            System.out.println(ans);
            return 1;
        }
        
        int count = 0;
        for(int i=1; i<=str.length(); i++){
            //find the prefix
            String prefix = str.substring(0,i);

            if(map.contains(prefix)){
                String ros = str.substring(i);
                count += wordbreak_(ros, ans + prefix + "-");
            }
        }
        return count;
    }

    public static void crypto(){

    }

    public static void crossword(){

        char[][] board = {{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
        {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
        {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
        {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
        {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
        {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

        String[] words = {"agra", "norway", "england", "gwalior"};

        System.out.println(crossword_(board, words, 0));
    }

    public static boolean canPlaceWordV(char[][] board, int i, int j, String word){

        for(int r=0; r<word.length(); r++){
            char cb = board[i+r][j];
            char cw = word.charAt(r);

            if(cb != '-' && cb != cw)
                return false;
        }
        //check for exact fit
        if(i-1>=0 && board[i-1][j] != '+')
            return false;

        if((i+word.length()) < board.length && board[i+word.length()][j] != '+')
            return false;

        return true;
    }

    public static boolean[] placeWordV(char[][] board, int i, int j, String word){

        boolean vis[] = new boolean[word.length()];

        for(int r = 0; r<word.length(); r++){
            if(board[i+r][j] == '-'){
                board[i+r][j] = word.charAt(r);
                vis[r] = true;
            }
        }
        return vis;
    }
    
    public static void unplaceWordV(char[][] board, String word, int i,  int j, boolean[] vis){

        for(int r =0; r < word.length(); r++){
            if(vis[r] == true){
                board[i+r][j] = '-';
            }
        }
    }

    public static boolean canPlaceWordH(char[][] board, int i, int j, String word){

        for(int c=0; c<word.length(); c++){
            char cb = board[i][j+c];
            char cw = word.charAt(c);

            if(cb != '-' && cb != cw)
                return false;
        }
        //check for exact fit
        if(j-1>=0 && board[i][j-1] != '+')
            return false;

        if(j+word.length() < board.length && board[i][j+word.length()] != '+')
            return false;

        return true;
    }

    public static boolean[] placeWordH(char[][] board, int i, int j, String word){

        boolean vis[] = new boolean[word.length()];

        for(int c = 0; c<word.length(); c++){
            if(board[i][j+c] == '-'){
                board[i][j+c] = word.charAt(c);
                vis[c] = true;
            }
        }
        return vis;
    }

    public static void unplaceWordH(char[][] board, String word, int i,  int j, boolean[] vis){

        for(int c =0; c<word.length(); c++){
            if(vis[c] == true){
                board[i][j+c] = '-';
            }
        }
    }

    public static int crossword_(char[][] board, String[] words, int idx){

        if(idx == words.length){
            for(char[] ar: board){
                for(char ch: ar){
                    System.out.print(ch+" ");
                }
                System.out.println();
            }
            System.out.println();
            return 1;
        }

        int count = 0;
        String word = words[idx];
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[0].length; j++){

                //Vertical call
                if(canPlaceWordV(board, i, j, word) == true){
                    boolean[] vis = placeWordV(board, i, j, word);
                    count += crossword_(board, words, idx+1);
                    unplaceWordV(board, word, i, j, vis);
                }

                //Horizontal call
                if(canPlaceWordH(board, i, j, word) == true){
                    boolean[] vis = placeWordH(board, i, j, word);
                    count += crossword_(board, words, idx+1);
                    unplaceWordH(board,word, i, j, vis);
                }
            }
        }
        return count;
    }

    static int[] left;
    static int[] right;
    static int[] top;
    static int[] bottom;

    public static void magnets(){

        char[][] board = {
                            {'h','h','h','h','v','v'},
                            {'h','h','h','h','v','v'},
                            {'v','v','v','v','h','h'},
                            {'v','v','v','v','v','v'},
                            {'h','h','h','h','v','v'}
        };

        left = new int[]{2,3,0,0,0};
        top = new int[]{1,0,0,2,1,0};
        right = new int[]{0,0,0,1,0};
        bottom = new int[]{2,0,0,2,0,3};

        System.out.println(magnets_(board, 0));
    }

    static boolean canPlacePatternH(char[][] board, int i, int j, String pat){

        if(j-1>=0 && board[i][j-1] == pat.charAt(0))
            return false;
        if(i-1>=0 && board[i-1][j] == pat.charAt(0))
            return false;
        
        if(i-1>=0 && j+1 < board[0].length && board[i-1][j+1] == pat.charAt(1))
            return false;
        if(j+2 < board[0].length && board[i][j+2] == pat.charAt(1))
            return false;
        
        return true;
    }

    static boolean canPlacePatternV(char[][] board, int i, int j, String pat){

        if(j-1>=0 && board[i][j-1] == pat.charAt(0))
            return false;
        if(i-1>=0 && board[i-1][j] == pat.charAt(0))
            return false;
        
        if(j+1 < board[0].length && board[i][j+1] == pat.charAt(1))
            return false;
        
        return true;
    }

    static int magnets_(char[][] board, int idx){

        int n = board.length;
        int m = board[0].length;

        if(idx == m * n ){
            //array left and right check krne h
            for(int i=0; i<n; i++){
                int pcount = 0;
                int mcount = 0;
                for(int j=0; j<m; j++){
                    if(board[i][j] == '+'){
                        pcount++;
                    }
                    else if(board[i][j] == '-')
                        mcount++;
                }

                if(pcount != left[i] && left[i]!=0){
                    return 0;
                }
                else if(mcount != right[i] && right[i]!=0){
                    return 0;
                }
            }

            //array top and bottom check krne h
            for(int j=0; j<m; j++){
                int pcount = 0;
                int mcount = 0;
                for(int i=0; i<n; i++){
                    if(board[i][j] == '+'){
                        pcount++;
                    }
                    else if(board[i][j] == '-')
                        mcount++;
                }

                if(pcount != top[j] && top[j]!=0){
                    return 0;
                }
                else if(mcount != bottom[j] && bottom[j]!=0){
                    return 0;
                }
            }
            display(board);
            return 1;
        }

        int r = idx / m;
        int c = idx % m;

        int count = 0;

        if(board[r][c] == 'h'){
            //o1 (+-)
            if(canPlacePatternH(board, r, c, "+-") == true){
                
                board[r][c] = '+';
                board[r][c+1] = '-';
                count += magnets_(board, idx+1);
                board[r][c] = 'h';
                board[r][c+1] = 'h';
            }

            //o2 (-+)
            if(canPlacePatternH(board, r, c, "-+") == true){
                
                board[r][c] = '-';
                board[r][c+1] = '+';
                count += magnets_(board, idx+1);
                board[r][c] = 'h';
                board[r][c+1] = 'h';
            }

            //o3 (**)
            board[r][c] = '*';
            board[r][c+1] = '*';
            count += magnets_(board, idx+1);
            board[r][c] = 'h';
            board[r][c+1] = 'h';
        }
        else if(board[r][c] == 'v'){
             //o1 (+-)
             if(canPlacePatternV(board, r, c, "+-") == true){
                
                board[r][c] = '+';
                board[r+1][c] = '-';
                count += magnets_(board, idx+1);
                board[r][c] = 'v';
                board[r+1][c] = 'v';
            }

            //o2 (-+)
            if(canPlacePatternV(board, r, c, "-+") == true){
                
                board[r][c] = '-';
                board[r+1][c] = '+';
                count += magnets_(board, idx+1);
                board[r][c] = 'v';
                board[r+1][c] = 'v';
            }

            //o3 (**)
            board[r][c] = '*';
            board[r+1][c] = '*';
            count += magnets_(board, idx+1);
            board[r][c] = 'v';
            board[r+1][c] = 'v';
        }
        else{
            count += magnets_(board, idx+1);
        }

        return count;
    }

    static void display(char[][] board){
        for(char[] ar: board){
            for(char ch: ar){
                System.out.print(ch + " ");
            }
            System.out.println();
        }
    }


}