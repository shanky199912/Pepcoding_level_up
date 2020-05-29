import java.util.ArrayList;

class Leetcode{

    public static void main(String[] args) {
        solve();
    }

    public static void solve(){

        recursion();
        graph();
    }

    public static void recursion(){

    }

    public static void graph(){

    }

//  ||leetcode_question_47============================================
    public static List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        // List<Integer> mlist = new ArrayList<>();
        // for(int ele:nums){
        //     mlist.add(ele);
        // }
        return getPerm(nums,0, new ArrayList<Integer>(), new boolean[nums.length]);
    }
    
    public static List<List<Integer>> getPerm(int[] nums,int idx, ArrayList<Integer> list, boolean[] vis2){
        
        if(list.size() == nums.length){
            List<List<Integer>> base = new ArrayList<>();
            List<Integer> ll = new ArrayList<>();
            ll.addAll(list);
            base.add(ll);
            return base;
        }
        
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=idx; i<nums.length; i++){
            
            if(!vis2[i]){
                vis2[i] = true;
                list.add(nums[i]);
                List<List<Integer>> res = getPerm(nums,0,list, vis2);
                for(List<Integer> ls: res){
                    if(!ans.contains(ls))
                        ans.add(ls);
                }
                vis2[i] = false;
                list.remove(list.size()-1);
            }
        }
        
        return ans;
    }

//  ||leetcode_question_46============================================
    public List<List<Integer>> permute(int[] nums) {
        
        return getPerm(nums,0, new ArrayList<Integer>(), new boolean[nums.length]);
     }
     
     public List<List<Integer>> getPerm_02(int[] nums,int idx, ArrayList<Integer> list, boolean[] vis){
         
         //iska tree same as coin change permute with single coin jesa hai.
         if(list.size() == nums.length){
             List<List<Integer>> base = new ArrayList<>();
             List<Integer> ll = new ArrayList<>();
             ll.addAll(list);
             base.add(ll);
             return base;
         }
         
         List<List<Integer>> ans = new ArrayList<>();
         for(int i=idx; i<nums.length; i++){
             
             if(!vis[i]){
                 vis[i] = true;
                 list.add(nums[i]);
                 ans.addAll(getPerm_02(nums,0,list,vis));
                 vis[i] = false;
                 list.remove(list.size()-1);
             }
         }
         
         return ans;     
    }
    
// ||leetcode_question_40============================================
    public List<List<Integer>> combinationSum2(int[] coins, int tar) {
        if(coins.length == 0){
            List<List<Integer>> res = new ArrayList<>();
            return res;
        }
        Arrays.sort(coins);
        return getComb(coins, 0, tar , new ArrayList<Integer>());
    }
    
    public List<List<Integer>> getComb(int[] coins, int idx , int tar, ArrayList<Integer> list){
        
        if(tar == 0){
            List<List<Integer>> base = new ArrayList<>();
            List<Integer> ll = new ArrayList<>();
            ll.addAll(list);
            base.add(ll);
            return base;
        }
        
        List<List<Integer>> ans = new ArrayList<>();
        
        for(int i=idx; i<coins.length; i++){
            if(tar - coins[i] >=0){
                list.add(coins[i]);
                List<List<Integer>> res = getComb(coins,i+1,tar-coins[i],list);
                for(List<Integer> ls: res){
                    if(!ans.contains(ls))
                        ans.add(ls);
                }
                list.remove(list.size()-1);
            }
        }
        
        return ans;
    }
}