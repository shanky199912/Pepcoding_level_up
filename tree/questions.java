class questions{
    public static void main(String[] args) {
        
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        ArrayList<TreeNode> first = rootToNodePath(root, p.val, path);
        ArrayList<TreeNode> second = rootToNodePath(root, q.val, path);

        for(Node n : )


    }

    public static ArrayList<TreeNode> rootToNodePath(TreeNode root, int data){

        ArrayList<TreeNode> path = new ArrayList<>();
        rootToNodePath_(root, data, path);
        return path;
        
    }

    public static boolean rootToNodePath_(TreeNode node, int data, ArrayList<Node> list){
        if(node == null){
            return false;
        }

        if(node.val == data){
            list.add(node);
            return true;
        }

        boolean res = rootToNodePath_(node.left, data, list) || rootToNodePath_(node.right, data, list);
        if(res) list.add(node);
        
        return res;
    }
}