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




}