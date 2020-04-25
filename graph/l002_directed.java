import java.util.ArrayList;
import java.util.LinkedList;

class l002_directed{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        constructgraph();
    }

    static int N = 8;
    static ArrayList<Integer>[] graph;

    public static void display(ArrayList<Integer>[] gp){
        for(int i=0; i<N; i++){
            System.out.print(i+" -> ");
            for(Integer e: gp[i]){
                System.out.print(e + ",");
            }
            System.out.println();
        }

        System.out.println();
    }

    public static void topological_dfs(int src, boolean[] vis, ArrayList<Integer> list){

        vis[src] = true;

        for(Integer e: graph[src]){
            
            if(!vis[e]){
                topological_dfs(e,vis,list);
            }
        }

        list.add(src);
    }

    public static void topologicalSort(){
        boolean[] vis = new boolean[N];
        ArrayList<Integer> list = new ArrayList<>();

        for(int i=0; i<N; i++){
            if(!vis[i]){
                topological_dfs(i,vis,list);
            }
        }

        for(int i=list.size()-1; i>=0 ; i--) System.out.print(list.get(i) + " ");
    }

    public static void kahnsAlgo(){

        int[] indegree = new int[N];

        for(int i=0; i<N ; i++){
            for(Integer e: graph[i])
                indegree[e]++;
        }

        LinkedList<Integer> que = new LinkedList<>();
        
        for(int i=0; i<N ; i++){
            if(indegree[i] == 0){
                que.addLast(i);
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        while(que.size()!=0){
            int size = que.size();

            while(size-- >0){
                int rvtx = que.removeFirst();
                ans.add(rvtx);

                for(Integer e: graph[rvtx]){
                    if(--indegree[e]==0){
                        que.addLast(e);
                    }
                }

            }
        }

        if(ans.size()!=N)System.out.println("Cycle");
        else{
            System.out.println(ans);
        }
    }

    public static void constructgraph(){

        graph = new ArrayList[N];
        for(int i=0; i<N; i++){
            graph[i] = new ArrayList<Integer>();
        }

        graph[7].add(5);
        graph[7].add(6);
        graph[5].add(2);
        graph[5].add(4);
        graph[6].add(4);
        graph[6].add(3);
        graph[3].add(1);
        graph[2].add(1);
        graph[1].add(0);

        // graph[7].add(5);
        // graph[7].add(6);
        // graph[5].add(2);
        // graph[5].add(4);
        // graph[6].add(4);
        // graph[6].add(3);
        // graph[3].add(1);
        // graph[2].add(1);

        display(graph);

        topologicalSort();
        System.out.println();
        kahnsAlgo();
    }

}