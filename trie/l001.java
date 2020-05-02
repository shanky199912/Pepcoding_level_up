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

    public void insert(String word){

        Node curr = root;
        int n = word.length();
        for(int i=0; i<n; i++){
            int idx = word.charAt(i) -'a';
            if(curr.childs[idx] == null) curr.childs[idx] = new Node();

            curr = curr.childs[idx];
        }

        curr.wordEnd++;
    }

    // public boolean search(String word){
        
    //     Node curr = root;
    //     int n = word.length();
    //     for(int i=0; i<n; i++){
    //         char ch = word.charAt(i);
    //         if(ch == '.')continue;
    //         int idx = word.charAt(i) -'a';
    //         curr = curr.childs[idx];
    //         if(curr == null)return false;
            
    //     }
    //     return curr.wordEnd > 0;
    // }
    
    public boolean search_(Node node, int si, String word){

        if(si == word.length()){
            return node.wordEnd !=0;
        }
        boolean res = false;
        char ch = word.charAt(si);
        if(ch == '.'){

            for(int i=0; i<26; i++){
                if(node.childs[i] != null){

                    res = res || search_(node.childs[i], si+1, word);
                }
            }
        }
        else{
            int idx = word.charAt(si) - 'a';
            if(node.childs[idx] !=  null){
                res = res || search_(node.childs[idx], si+1, word);
            }
        }
        return res;
    }

    public boolean search(String word){
        
        return search_(root, 0, word);
    }

    public boolean startsWith(String word){
        Node curr = root;
        int n = word.length();
        for(int i=0; i<n; i++){
            int idx = word.charAt(i) -'a';
            curr = curr.childs[idx];
            if(curr == null)return false;
            
        }
        return true;
    }

}