public class questions{
    public class Node{

        int wordEnd;
        Node[] childs;

        Node(){
            this.wordEnd = 0;
            this.childs = new Node[2];
        }
    }

    Node root = null;

    public void insert(String word){

        Node curr = root;
        int n = word.length();
        for(int i=0; i<n; i++){
            int idx = word.charAt(i) -'0';
            if(curr.childs[idx] == null) curr.childs[idx] = new Node();

            curr = curr.childs[idx];
        }

        curr.wordEnd++;
    }


}