class l001{

    public class Node{

        int wordEnd;
        Node[] childs;

        Node(){
            this.wordEnd = 0;
            this.childs = new Node[26];
        }
    }

    Node root = null;

    //leetcode-212============================================
    public List<String> findWords(char[][] board, String[] words) {

        int[][] dir = {{0,1},{-1,0},{1,0},{0,-1}};

        
    }
}