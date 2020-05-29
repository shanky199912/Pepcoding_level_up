import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class question{
    public class TreeNode {
       int val;
       TreeNode left;
       TreeNode right;
       TreeNode(int x) { val = x; }
    }

    //Leetcode: 863.=======================================================
    public boolean rootToNodePath_(TreeNode root,int data,ArrayList<TreeNode> path){
       if(root==null) return false;
       if(root.val==data){
           path.add(root);
           return true;
       }
 
       boolean res = rootToNodePath_(root.left,data,path) || rootToNodePath_(root.right,data,path);
      if(res) path.add(root);
       return res;
     }

    public void kDown(TreeNode root,int level,TreeNode blockNode,List<Integer> ans){
       if(root==null || root==blockNode) return;

       if(level==0){
         ans.add(root.val);
         return;  
       }

       kDown(root.left,level-1,blockNode,ans);
       kDown(root.right,level-1,blockNode,ans);

    }

   public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
       ArrayList<TreeNode> path=new ArrayList<>();
       rootToNodePath_(root,target.val,path);

       TreeNode blockNode=null;
       List<Integer> ans=new ArrayList<>();
       for(int i=0;i<path.size();i++){
           if(K-i<0) break;
           kDown(path.get(i),K-i,blockNode,ans);
           blockNode=path.get(i);
       }  
       return ans;
   }     
   
    public List<Integer> distanceK_02(TreeNode root, TreeNode target, int K) {
        List<Integer> ans=new ArrayList<>();
        distanceK_02_(root, target, K, ans);
        return ans;
    }
    
    public int distanceK_02_(TreeNode root, TreeNode target, int K, List<Integer> ans) {
        if(root == null) return -1;

        if(root.val == target){
            kDown(root, K, null, ans);
            return 1;
        } 

        int leftD = distanceK_02_(root.left, target, K);
        if(leftD != -1){
            if(K- leftD >= 0){
                kDown(root, K-leftD, root.left, ans);
            }
            return leftD + 1;
        }

        int rightD = distanceK_02_(root.right, target, K);
        if(rightD != -1){
            if(K- rightD >= 0){
                kDown(root, K-rightD, root.right, ans);
            }
            return rightD + 1;
        }

        return -1;
    } 

    //leetcode 112 ================================================
    public boolean hasPathSum(TreeNode root, int sum) {
        
        if(root == null) return false;
        if(root.left == null && root.right == null && sum-root.val == 0) return true;
        return hasPathSum(root.left, sum-root.val) || hasPathSum(root.right, sum-root.val);
    }

    //leetcode -113 ================================================
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
    
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> smallAns = new ArrayList<>();
        pathSum_(root,sum, smallAns, res); 
        return res;
    }   
    
    public void pathSum_(TreeNode root, int sum, List<Integer> smallAns, List<List<Integer>> res){
        if(root == null) return;

        //condtn to check leaf node.
        if(root.left == null && root.right == null && sum-root.val == 0){
            List<Integer> base = new ArrayList<>(smallAns); //copy constructor
            base.add(root.val);
            res.add(base);
            return;
        }

        smallAns.add(root.val);
        pathSum_(root.left, sum-root.val, smallAns, res);   
        pathSum_(root.right, sum-root.val, smallAns, res);
        smallAns.remove(smallAns.size()-1);     
        
        return;
    }

    //gfg- https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/

    static int max_leafToleafSum;
    public static int maxPathSum(Node root) {
        max_leafToleafSum = (int)-1e8;
        leafToleafPath(root);
        return max_leafToleafSum;
    }
    
    public static int leafToleafPath(Node root){
        if(root == null) return 0;
        
        int leftnodetoleaf = leafToleafPath(root.left);
        int rightnodetoleaf = leafToleafPath(root.right);
        
        if(root.left != null && root.right != null){
            max_leafToleafSum = Math.max(max_leafToleafSum, 
            leftnodetoleaf+rightnodetoleaf+root.data);
            return Math.max(leftnodetoleaf,rightnodetoleaf) + root.data;
        }
        
        return (root.left == null ? rightnodetoleaf:leftnodetoleaf) + root.data;
    }

    //leetcode - 987 ============================================
    int leftMinvalue = 0;
    int rightMaxvalue = 0;

    public void width(TreeNode node, int lev){
        if(node == null) return;

        leftMinvalue = Math.min(leftMinvalue, lev);
        rightMaxvalue = Math.max(rightMaxvalue, lev);

        width(node.left, lev-1);
        width(node.right, lev+1);
    }

    // public class pairVO implements Comparable<pairVO>{
    //     TreeNode node;
    //     int vl = 0;

    //     public pairVO(TreeNode node, int vl){
    //         this.vl = vl;
    //         this.node = node;
    //     }

    //     @Override
    //     public int compareTo(pairVO o){
    //         //default behaviour of our priority queue. (this-other);
    //         if(this.vl == o.vl) return this.node.val - o.node.val;
    //         return this.vl - o.vl;
    //     }
    // }

    // public List<List<Integer>> verticalTraversal(TreeNode root) {
    //     List<List<Integer>> ans = new ArrayList<>();
    //     if(root == null) return ans;
        
    //     width(root, 0);
    //     int n = rightMaxvalue - leftMinvalue + 1;
    //     for(int i=0; i<n; i++){
    //         ans.add(new ArrayList<>());
    //     }
        
    //     PriorityQueue<pairVO> pq = new PriorityQueue<>();
    //     PriorityQueue<pairVO> cq = new PriorityQueue<>();

    //     //initialize the root node with positive value of leftMinValue..
    //     pq.add(new pairVO(root, -leftMinvalue));

    //     while(pq.size() != 0){
    //         int size = pq.size();
    //         while(size-- >0){
    //             pairVO rnode = pq.poll();
    //             ans.get(rnode.vl).add(rnode.node.val);
                
    //             if(rnode.node.left != null) cq.add(new pairVO(rnode.node.left, rnode.vl-1));
    //             if(rnode.node.right != null) cq.add(new pairVO(rnode.node.right, rnode.vl+1));
    //         }

    //         //swap the queues.
    //         PriorityQueue<pairVO> temp = pq;
    //         pq = cq;
    //         cq = temp;
    //     }

    //     return ans;
    // }

    public class pairVO implements Comparable<pairVO>{
        TreeNode node;
        int vl = 0;
        int h = 0;

        public pairVO(TreeNode node, int vl, int h){
            this.vl = vl;
            this.node = node;
            this.h = h;
        }

        @Override
        public int compareTo(pairVO o){
            //default behaviour of our priority queue. (this-other);
            if(this.vl == o.vl){
                if(this.h == o.h) return this.node.val - o.node.val;
                return this.h - o.h;
            }
            if(this.h == o.h){
                
            }
            return this.vl - o.vl;
        }
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;
        
        width(root, 0);
        int n = rightMaxvalue - leftMinvalue + 1;
        for(int i=0; i<n; i++){
            ans.add(new ArrayList<>());
        }
        
        PriorityQueue<pairVO> pq = new PriorityQueue<>();
        PriorityQueue<pairVO> cq = new PriorityQueue<>();

        //initialize the root node with positive value of leftMinValue..
        pq.add(new pairVO(root, -leftMinvalue, 0));

        while(pq.size() != 0){
            int size = pq.size();
            while(size-- >0){
                pairVO rnode = pq.poll();
                ans.get(rnode.vl).add(rnode.node.val);
                
                if(rnode.node.left != null) cq.add(new pairVO(rnode.node.left, rnode.vl-1, rnode.h + 1));
                if(rnode.node.right != null) cq.add(new pairVO(rnode.node.right, rnode.vl+1, rnode.h + 1));
            }

            //swap the queues.
            PriorityQueue<pairVO> temp = pq;
            pq = cq;
            cq = temp;
        }

        return ans;
    }
}