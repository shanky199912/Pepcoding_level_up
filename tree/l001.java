import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Arrays;

public class l001{

    public static void main(String[] args){
        solve();
    }

   public static class Node{
       int data;  
       Node left=null;   // Node* left=nullptr;   
       Node right=null;  // Node* right=nullptr;

       Node(int data){
           this.data=data;
       } 
       
       Node(){
       }
   }

   static int idx=0;
   public static Node constructTree(int[] arr){
      if(idx >= arr.length || arr[idx]==-1) {
        idx++;  
        return null;
      }

      Node node=new Node(arr[idx++]);   // Node* node=new Node(arr[idx++]);
      node.left=constructTree(arr);
      node.right=constructTree(arr);
      
      return node;
   }

   public static void display(Node node){
       if(node==null) return;

       String str="";
       str += ((node.left!=null)?node.left.data:".");
       str+=  " <- " + node.data + " -> ";
       str += ((node.right!=null)?node.right.data:".");
       System.out.println(str);

       display(node.left);
       display(node.right);

   }

   //Basic.================================================================

   public static int size(Node node){
     if(node==null) return 0;
     return (size(node.left) + size(node.right) + 1);
   }

   
   public static int height(Node node){
    if(node==null) return -1; // return -1, height w.r.t edge, return 0, height w.r.t node.
    return Math.max(height(node.left), height(node.right)) + 1;
   }

   public static int Maximum(Node node){
    if(node==null) return (int)-1e8;  // java: Integer.MIN_VALUE, c++: INT_MIN; 
    return Math.max(Math.max(Maximum(node.left), Maximum(node.right)),node.data);  // max(leftSubtree,rightSubtree,myself);
   }

   
   public static int Minimum(Node node){
    if(node==null) return (int)1e8;  // java: Integer.MAX_VALUE, c++: INT_MAX; 
    return Math.min(Math.min(Minimum(node.left), Minimum(node.right)),node.data);
   }

   public static int Minimum_02(Node node){
       int min_=node.data;
       
       if(node.left!=null) min_=Math.min(min_,Minimum_02(node.left));
       if(node.right!=null) min_=Math.min(min_,Minimum_02(node.right));
       
       return min_;
   }

   public static boolean find(Node node,int data){
       if(node==null) return false;
       
       if(node.data==data) return true;
       return find(node.left,data) || find(node.right,data);
   }

   //Traversal.============================================================

    public static void preOrder(Node node){
         if(node==null) return;

         System.out.print(node.data+ " ");
         preOrder(node.left);
         preOrder(node.right);
    }

    
    public static void inOrder(Node node){
        if(node==null) return;

        inOrder(node.left);
        System.out.print(node.data+ " ");
        inOrder(node.right);
   }

    public static void postOrder(Node node){
        if(node==null) return;

        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.data+ " ");
    }

    public static boolean rootToNodePath_(Node node, int data, ArrayList<Node> list){
        if(node == null){
            return false;
        }

        if(node.data == data){
            list.add(node);
            return true;
        }

        boolean res = rootToNodePath_(node.left, data, list) || rootToNodePath_(node.right, data, list);
        if(res) list.add(node);
        
        return res;
    }

    public static void rootToNodePath(Node root, int data){

        ArrayList<Node> path = new ArrayList<>();
        rootToNodePath_(root, data, path);
        for(Node n: path){
            System.out.print(n.data + "->");
        }
        
    }

    public static ArrayList<Node> rootToNodePath_02(Node root,int data){
        
        if(root==null){
            return new ArrayList<>();
        }
        
        if(root.data==data){
            ArrayList<Node> base=new ArrayList<>();
            base.add(root);
            return base;
        }
  
        ArrayList<Node> left=rootToNodePath_02(root.left,data);
        if(left.size()!=0){
            left.add(root);
            return left;
        }
   
        ArrayList<Node> right=rootToNodePath_02(root.right,data);
        if(right.size()!=0){
            right.add(root);
            return right;
        }
        
        return new ArrayList<>();
    }

    public Node lowestCommonAncestor(Node root, int p, int q) {
        ArrayList<Node> path1=new ArrayList<>();
        ArrayList<Node> path2=new ArrayList<>();
        
        rootToNodePath_(root,p,path1);
        rootToNodePath_(root,q,path2);

        Node prev=null;
        int i=path1.size()-1;
        int j=path2.size()-1;
        
        while(i>=0 && j>=0){
          if(path1.get(i).data!=path2.get(j).data) break;
          
          prev=path1.get(i);
          i--;
          j--;
        }

        return prev;
    }

    static Node LCA = null;
    public static boolean lowestCommonAncestor_02(Node root, int p, int q){

        if(root == null) return false;

        boolean selfNode = false;
        if(root.data == p || root.data == q){
            selfNode = true;
        }

        boolean leftNode = lowestCommonAncestor_02(root.left, p, q);
        if(LCA != null) return true;

        boolean rightNode = lowestCommonAncestor_02(root.right, p, q);
        if(LCA != null) return true;

        if((selfNode && leftNode) || (selfNode && rightNode) || (leftNode && rightNode)){
            LCA = root;
        }

        return selfNode || leftNode || rightNode ;
    }

    public static void kDown(Node root,int level,Node blockNode){
        if(root==null || root==blockNode) return;
 
        if(level==0){
          System.out.print(root.data + " ");
          return;  
        }
 
        kDown(root.left,level-1,blockNode);
        kDown(root.right,level-1,blockNode);
 
     }
 
     public static void allNodeKAway(Node root, int target, int K) {
         ArrayList<Node> path=new ArrayList<>();
         rootToNodePath_(root,target,path);
 
         Node blockNode=null;
         for(int i=0;i<path.size();i++){
             if(K-i<0) break;
             kDown(path.get(i),K-i,blockNode);
             blockNode=path.get(i);
         }
     }
     
     public static int allNodeKAway_02_(Node root, int target, int K) {
          if(root==null) return -1;
 
          if(root.data == target){
             kDown(root,K,null);
             return 1;
          }
 
          int leftdistance=allNodeKAway_02_(root.left,target,K);
          if(leftdistance!=-1){
             if(K-leftdistance >= 0) kDown(root,K-leftdistance,root.left);
             return leftdistance+1;
          }
          
          int rightdistance=allNodeKAway_02_(root.right,target,K);
           if(rightdistance!=-1){
             if(K-rightdistance >= 0) kDown(root,K-rightdistance,root.right);
             return rightdistance+1;
         }
 
         return -1;
     
     }
 
     public static void kDown(Node root,int level){
         if(root==null) return;
  
         if(level==0){
           System.out.print(root.data + " ");
           return;  
         }
  
         kDown(root.left,level-1);
         kDown(root.right,level-1);
  
      }
 
     public static int allNodeKAway_03_(Node root, int target, int K) {
        if(root==null) return -1;
 
        if(root.data == target){
            kDown(root,K,null);
            return 1;
        }
 
        int leftdistance=allNodeKAway_03_(root.left,target,K);
        if(leftdistance!=-1){
            if(K-leftdistance == 0)  
               System.out.print(root.data + " ");
            else
               kDown(root.right,K-leftdistance-1);
            return leftdistance+1;
        }
         
        int rightdistance=allNodeKAway_03_(root.right,target,K);
        if(rightdistance!=-1){
            if(K-rightdistance == 0)
                System.out.print(root.data + " ");
            else
                kDown(root.left,K-rightdistance-1);
            return rightdistance+1;
        }
 
        return -1;
    
    }
 
    public static int diameter_01(Node node){
        if(node==null) return 0;
 
        int ld=diameter_01(node.left);
        int rd=diameter_01(node.right);
 
        int lh=height(node.left);
        int rh=height(node.right);
 
        int myDia = lh + rh + 2;
        return Math.max(Math.max(ld,rd), myDia);
    }
 
    public static class diaPair{
        int dia=0;
        int hei=0;
 
        diaPair(int dia,int hei){
            this.dia=dia;
            this.hei=hei;
        }
    }
 
    public static diaPair diameter_02(Node node){
        if(node==null) return new diaPair(0,-1) ;
    
        diaPair lr=diameter_02(node.left); // left result
        diaPair rr=diameter_02(node.right); // right result
    
        diaPair myRes=new diaPair(0,-1);
        myRes.dia = Math.max(Math.max(lr.dia,rr.dia), (lr.hei+rr.hei+2));
        myRes.hei = Math.max(lr.hei,rr.hei)+1;
        
        return myRes;
    }
 
    static int diameter=0;
    public static int diameter_03(Node node){
        if(node==null) return -1 ;
    
        int lh = diameter_03(node.left); // left height
        int rh =diameter_03(node.right); // right height
        
        diameter=Math.max(diameter,lh+rh+2);
        return Math.max(lh,rh)+1;
    }

     //LevelOrder_series.=========================================================

    public static void levelOrder_00(Node node){
        LinkedList<Node> pQue=new LinkedList<>(); // addLast and removeFirst.
        pQue.addLast(node);

        while(pQue.size()!=0){
            Node rnode=pQue.removeFirst();
            System.out.print(rnode.data+ " ");
            if(rnode.left!=null) pQue.addLast(rnode.left);
            if(rnode.right!=null) pQue.addLast(rnode.right);
        }
    }

    public static void levelOrder_01(Node node){
        LinkedList<Node> pQue=new LinkedList<>(); // addLast and removeFirst.
        LinkedList<Node> cQue=new LinkedList<>(); // addLast and removeFirst.

        pQue.addLast(node);
        int count=0;
        System.out.print("Level: " + count + " -> ");
        
        while(pQue.size()!=0){
            Node rnode=pQue.removeFirst();
            System.out.print(rnode.data+ " ");
            if(rnode.left!=null) cQue.addLast(rnode.left);
            if(rnode.right!=null) cQue.addLast(rnode.right);

            if(pQue.size()==0){
                LinkedList<Node> temp=pQue;
                pQue=cQue;
                cQue=temp;
                count++;      
                System.out.print("\nLevel: " + count + " -> ");
            }
        }
    }

    public static void levelOrder_02(Node node){
        LinkedList<Node> que =new LinkedList<>(); // addLast and removeFirst.
        que.addLast(node);
        que.addLast(null);

        int count = 0;
        System.out.print("Level: " + count + " -> ");

        while(que.size()!=1){
            Node rnode=que.removeFirst();
            System.out.print(rnode.data+ " ");
            if(rnode.left!=null) que.addLast(rnode.left);
            if(rnode.right!=null) que.addLast(rnode.right);

            if(que.getFirst() == null){
                que.removeFirst();
                que.addLast(null);
                count++;
                System.out.print("\nLevel: " + count + " -> ");
            }
        }
    }

    public static void levelOrder_03(Node node){
        LinkedList<Node> que =new LinkedList<>(); // addLast and removeFirst.
        que.addLast(node);

        int count = 0;
        while(que.size()!=0){
            System.out.print("Level: " + count + " -> ");
            count++;
            int size = que.size();
            while(size-- >0){
                Node rnode=que.removeFirst();
                System.out.print(rnode.data+ " ");
                if(rnode.left!=null) que.addLast(rnode.left);
                if(rnode.right!=null) que.addLast(rnode.right);
            }
            System.out.println();
        }
    }

    //view ========================================
    public static void leftView(Node node){ // jo sbse pehele a rha h que me(at a level).
        LinkedList<Node> que =new LinkedList<>(); // addLast and removeFirst.
        que.addLast(node);

        while(que.size()!=0){
            int size = que.size();
            System.out.print(que.getFirst().data + " ");
            while(size-- >0){
                Node rnode=que.removeFirst();
                if(rnode.left!=null) que.addLast(rnode.left);
                if(rnode.right!=null) que.addLast(rnode.right);
            }
        }
    }

    public static void rightView(Node node){ // jo sbse end me h que me (at each level).
        LinkedList<Node> que =new LinkedList<>(); // addLast and removeFirst.
        que.addLast(node);

        while(que.size()!=0){
            int size = que.size();
            Node prev = null;
            while(size-- >0){
                Node rnode=que.removeFirst();
                if(rnode.left!=null) que.addLast(rnode.left);
                if(rnode.right!=null) que.addLast(rnode.right);
                prev = rnode;
            }
            System.out.print(prev.data + " ");
        }
    }

    static int leftMinvalue = 0;
    static int rightMaxvalue = 0;

    public static void width(Node node, int lev){
        if(node == null) return;

        leftMinvalue = Math.min(leftMinvalue, lev);
        rightMaxvalue = Math.max(rightMaxvalue, lev);

        width(node.left, lev-1);
        width(node.right, lev+1);
    }

    public static class pairVO{
        Node node;
        int vl = 0;

        public pairVO(Node node, int vl){
            this.vl = vl;
            this.node = node;
        }
    }

    public static void verticalOrder(Node root){
        width(root, 0);
        int n = rightMaxvalue - leftMinvalue + 1;
        ArrayList<Integer>[] list = new ArrayList[n];
        for(int i=0; i<n; i++){
            list[i] = new ArrayList<Integer>();
        }

        LinkedList<pairVO> que = new LinkedList<>();
        que.addLast(new pairVO(root, -leftMinvalue));

        while(que.size()!=0){
            int size = que.size();
            while(size-- >0){
                pairVO rnode = que.removeFirst();
                list[rnode.vl].add(rnode.node.data);
                if(rnode.node.left != null) que.addLast(new pairVO(rnode.node.left, rnode.vl -1));
                if(rnode.node.right != null) que.addLast(new pairVO(rnode.node.right, rnode.vl + 1));
            }
        }

        for(ArrayList<Integer> ar: list){
            System.out.println(ar);
        }
        System.out.println();
    }

    public static void verticalOrderSum(Node root){
        width(root, 0);
        int n = rightMaxvalue - leftMinvalue + 1;
        int[] arr = new int[n];

        LinkedList<pairVO> que = new LinkedList<>();
        que.addLast(new pairVO(root, -leftMinvalue));

        while(que.size()!=0){
            int size = que.size();
            while(size-- >0){
                pairVO rnode = que.removeFirst();
                arr[rnode.vl] += rnode.node.data;
                if(rnode.node.left != null) que.addLast(new pairVO(rnode.node.left, rnode.vl -1));
                if(rnode.node.right != null) que.addLast(new pairVO(rnode.node.right, rnode.vl + 1));
            }
        }

        for(int ar: arr){
            System.out.println(ar);
        }
        System.out.println();
    }

    public static void bottomOrder(Node node){
        width(node, 0);
        int n = rightMaxvalue - leftMinvalue + 1;
        int[] arr = new int[n];

        LinkedList<pairVO> que = new LinkedList<>();
        que.addLast(new pairVO(node, -leftMinvalue));

        while(que.size() != 0){
            int size = que.size();
            while(size-- >0){
                pairVO rnode = que.removeFirst();
                arr[rnode.vl] = rnode.node.data;
                if(rnode.node.left != null) que.addLast(new pairVO(rnode.node.left, rnode.vl-1));
                if(rnode.node.right != null) que.addLast(new pairVO(rnode.node.right, rnode.vl+1));
            }
        }

        for(int ar: arr){
            System.out.println(ar);
        }
        System.out.println();
    }

    public static void TopOrder(Node node){
        width(node, 0);
        int n = rightMaxvalue - leftMinvalue + 1;
        int[] arr = new int[n];
        Arrays.fill(arr, (int)-1e8);

        LinkedList<pairVO> que = new LinkedList<>();
        que.addLast(new pairVO(node, -leftMinvalue));

        while(que.size() != 0){
            int size = que.size();
            while(size-- >0){
                pairVO rnode = que.removeFirst();
                if(arr[rnode.vl] == (int)-1e8){
                    arr[rnode.vl] = rnode.node.data;
                }
                if(rnode.node.left != null) que.addLast(new pairVO(rnode.node.left, rnode.vl -1));
                if(rnode.node.right != null) que.addLast(new pairVO(rnode.node.right, rnode.vl +1));
            }
        }
        for(int ar: arr){
            System.out.println(ar);
        }
        System.out.println();
    }

    static int leftMinvalueD = 0;
    public static void widthDiag(Node node, int lev){
        if(node == null) return;

        leftMinvalue = Math.min(leftMinvalue, lev);

        width(node.left, lev-1);
        width(node.right, lev+0);
    }

    public static void diagonalView(Node node){
        widthDiag(node, 0);
        int n = -leftMinvalue + 1;
        ArrayList<Integer>[] list = new ArrayList[n];
        for(int i=0; i<n; i++){
            list[i] = new ArrayList<Integer>();
        }

        LinkedList<pairVO> que = new LinkedList<>();
        que.addLast(new pairVO(node, -leftMinvalue));

        while(que.size() != 0){
            int size = que.size();
            while(size-- >0){
                pairVO rnode = que.removeFirst();
                list[rnode.vl].add(rnode.node.data);
                if(rnode.node.left != null) que.addLast(new pairVO(rnode.node.left, rnode.vl-1));
                if(rnode.node.right != null) que.addLast(new pairVO(rnode.node.right, rnode.vl+0));
            }
        }

        for(ArrayList<Integer> ar: list){
            System.out.println(ar);
        }
        System.out.println();
    }

    public static void diagonalSum(Node node){
        widthDiag(node, 0);
        int n = -leftMinvalue + 1;
        int[] arr = new int[n];

        LinkedList<pairVO> que = new LinkedList<>();
        que.addLast(new pairVO(node, -leftMinvalue));

        while(que.size() != 0){
            int size = que.size();
            while(size-- >0){
                pairVO rnode = que.removeFirst();
                arr[rnode.vl] += rnode.node.data;
                if(rnode.node.left != null) que.addLast(new pairVO(rnode.node.left, rnode.vl-1));
                if(rnode.node.right != null) que.addLast(new pairVO(rnode.node.right, rnode.vl+0));
            }
        }

        for(int ar: arr){
            System.out.println(ar);
        }
        System.out.println();
    }

    static Node head = null;
    static Node prev = null;
    public static void binaryTreeToDll(Node node){
        if(node == null) return;

        binaryTreeToDll(node.left);

        if(head == null){
            head = node;
        }
        else{
            prev.right = node;
            node.left = prev;
        }

        prev = node;

        binaryTreeToDll(node.right);
    }

    static Node headl = null;
    static Node prevl = null;
    public static void linearize(Node node){
        if(node == null) return;

        linearize(node.left);
        if(head == null){
            head = node;
        }
        linearize(node.right);
    }

    public static void set2(Node node){
        binaryTreeToDll(node);
        while(head != null){
            System.out.print(head.data + " ");
            head = head.right;
        }

    }

    //yeh mera ek all solution hai jisme ki humne size , height , find and preddecssor and successor sab kr rkha hai.
    public static class allSolution{
        int height = 0;
        int size=0;
        boolean find=false;
 
        Node pred=null;
        Node succ=null;
        Node prev=null;
    }
    
    //agar abb hume kisi ka bhi preddess and suuccs pucha jayega to bss hum yeh dekhenge ki kis order me pucha hai.
    //agar inorder ka pucha hai to inorder me code kr denge else preorder ya postorder me respectively.
    public static void allSol(Node node,int data,int level,allSolution pair){
        if(node==null) return;
        pair.size++;
        pair.height=Math.max(pair.height,level);
        pair.find= pair.find || node.data==data;
        
        if(node.data==data && pair.pred==null) pair.pred = pair.prev; //predecessor
        if(pair.prev!=null && pair.prev.data == data && pair.succ==null) pair.succ=node; //succesor
        pair.prev=node;

        allSol(node.left,data,level+1,pair);
        allSol(node.right,data,level+1,pair);
    }

    public static void inorderSuccessor_Predecessor(Node node, int data, allSolution pair){
        if(node == null) return;
        
        inorderSuccessor_Predecessor(node.left, data, pair);
        //here we will do our work -> kyunki inorder pucha tha issliye.
        //predecessor ka kaam 
        if(node.data == data && pair.pred == null) pair.pred = pair.prev;
        //successor ka kaam kese krein yeh dekhte hai..
        if(pair.prev != null && pair.prev.data == data && pair.succ == null) pair.succ = node;
        pair.prev = node;

        inorderSuccessor_Predecessor(node.right, data,pair);
    }

    

    public static void view(Node root){
        // leftView(root);
        // System.out.println();
        // rightView(root);
        // verticalOrder(root);
        // verticalOrderSum(root);
        // bottomOrder(root);
        // TopOrder(root);
        diagonalView(root);
        diagonalSum(root);
    }
    
    public static void levelOrder(Node root){
        // levelOrder_00(root);
        // levelOrder_01(root);
        // levelOrder_02(root);
        levelOrder_03(root);
    }

    public static void set1(Node root, int data){
        rootToNodePath(root, data);
        lowestCommonAncestor_02(root, 20,30);
        if(LCA != null)
            System.out.println(-1);
        System.out.println("lca :" + LCA.data);
    }

    public static void solve(){
       int[] arr={10,20,40,-1,-1,50,80,-1,-1,90,-1,-1,30,60,100,-1,-1,-1,70,110,-1,-1,120,-1,-1};
        //    int[] arr = {11,6,4,-1,5,-1,-1,8,-1,10,-1,-1,19,17,-1,-1,43,31,-1,-1,49,-1,-1};
        //    int[] arr={10,20};
       Node root=constructTree(arr);
       display(root);
        // levelOrder(root);
        // view(root);
        // set2(root);
        allSolution pair = new allSolution();
        allSol(root,50,0,pair);
        if(pair.pred != null) System.out.println(pair.pred.data);
        if(pair.succ != null) System.out.println(pair.succ.data);
        preOrder(root);
        // set1(root, 100);
    }
}