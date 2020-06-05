class l002BST{

    public static void main(String[] args){
        solve();
    }

    public static class Node{
        int data = 0;
        Node left = null;
        Node right = null;

        Node(int data){
            this.data = data;
        }

        Node(){
        }
    }

    //we have to construct our tree same way like a binary search.
    public static Node constructBST(int[] arr, int si, int ei){
        if(si > ei){
            return null;
        }

        int mid =  (si + ei) >> 1;  // => (si + ei)/2;
        Node node = new Node(arr[mid]);
        node.left = constructBST(arr, si, mid-1);
        node.right = constructBST(arr, mid+1, ei);

        return node;
    }

    public static void display(Node root){
        if(root == null) return;

        String str = "";
        str += (root.left != null ? root.left.data : ".");
        str+= " <= " + root.data + " => ";
        str += (root.right != null ? root.right.data : ".");
        System.out.println(str);

        display(root.left);
        display(root.right);
    }

    public static int size(Node root){
        if(root == null) return 0;
        return size(root.left) + size(root.right) + 1;
    }


    public static void set1(Node root){
        display(root);
    }

    public static void solve(){
        //sorted array of course -> if not given a sorted array then we have to sort it.
        int[] arr = {10,20,30,40,50,60,70,80,90,100,110,120,130};
        int si = 0;
        int ei = arr.length -1;
        Node root = constructBST(arr, si, ei);
        set1(root);
    }
}