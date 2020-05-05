import java.util.ArrayList;
import java.util.LinkedList;

class l001{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        constructgraph();
    }

    static class Edge{
        int v = 0;
        int w = 0;

        Edge(int v, int w){
            this.v = v;
            this.w = w;
        }
    }

    static int N = 7;
    static ArrayList<Edge>[] graph;

    public static void addEdge(ArrayList<Edge>[] gp, int u, int v, int w){

        gp[u].add(new Edge(v,w));
        gp[v].add(new Edge(u,w));
    }

    public static void display(ArrayList<Edge>[] gp){
        for(int i=0; i<N; i++){
            System.out.print(i+" -> ");
            for(Edge e: graph[i]){
                System.out.print("(" + e.v + "," + e.w + ")" + ", ");
            }
            System.out.println();
        }

        System.out.println();
    }

    public static int findEdge(int v1, int v2){

        int vtx = -1;
        for(int i=0; i<graph[v1].size(); i++){

            Edge e = graph[v1].get(i);
            if(e.v == v2){
                vtx = i;
                break;
            }
        }

        return vtx;
    }

    public static void removeEdge(int u, int v){

        int idx = findEdge(u, v);
        int idx2 = findEdge(v, u);

        graph[u].remove(idx);
        graph[v].remove(idx2);
    }

    public static void removeVtx(int vtx){

        while(graph[vtx].size()!=0){

            Edge e = graph[vtx].get(graph[vtx].size()-1);
            removeEdge(vtx, e.v);
        }
    }

    public static boolean hasPath(int src, int dest, boolean[] vis){

        if(src == dest) return true;

        vis[src] = true;
        boolean ans = false;
        for(Edge e: graph[src]){
            if(!vis[e.v]){
                ans = ans || hasPath(e.v, dest, vis);
            }
        }
        return ans;
    }

    public static int printPath(int src, int dest, int w, boolean[] vis, String ans){

        if(src == dest){
            System.out.println(ans + src + "@" + w);
            return 1;
        }

        vis[src] = true;
        int count = 0;
        for(Edge e: graph[src]){
            if(!vis[e.v]){
                count += printPath(e.v, dest, w + e.w, vis, ans + src + " ");
            }
        }
        vis[src] = false;
        return count;
    }

    static class Pair{
        int largeW = 0;
        String lps = "";
        int smallW = (int)1e7;
        String sps = "";
        int ciel = (int)1e7;
        String cps = "";
        int floor = 0;
        String fps = "";
    }

    public static void allSolution(int src, int dest, int w, boolean[] vis, String ans, Pair pair, int K){

        if(src == dest){
            // System.out.println(ans + src + "@" + w);
            //largest path
            if(w > pair.largeW){
                pair.largeW = w;
                pair.lps = ans + src;
            }
            // smallest path.
            if(w < pair.smallW){
                pair.smallW = w; 
                pair.sps = ans + src;
            }            
            //ciel path -> largest valon me se sabse chota.
            if(w > K && w < pair.ciel){
                pair.ciel = w;
                pair.cps = ans + src;
            }
            // floor path -> smallest valon me se sabse bda.
            if(w < K && w > pair.floor){
                pair.floor = w;
                pair.fps = ans + src;
            }
            return ;
        }

        vis[src] = true;
        for(Edge e: graph[src]){
            if(!vis[e.v]){
                allSolution(e.v, dest, w + e.w, vis, ans + src + " ",pair,K);
            }
        }
        vis[src] = false;
        return ;
    }

    static class Pair{
        int vtx;
        String  psf;
        int level;

        Pair(int vtx, String psf){
            this.vtx = vtx;
            this.psf = psf;
        }

        Pair(int vtx, String psf, int level){
            this.vtx = vtx;
            this.psf = psf;
            this.level = level;
        }
    }

    static void BFS_01(int src, boolean[] vis){
        LinkedList<Pair> que = new LinkedList<>();
        que.addLast(new Pair(src,  src + ""));

        int level =0;
        int desti = 4;

        while(que.size()!=0){

            Pair rvtx = que.removeFirst();

            if(vis[rvtx.vtx]){
				System.out.println("Cycle: " + rvtx.psf);
				continue;
			}

			if(rvtx.vtx==desti){
				System.out.println("destinantion: " + rvtx.psf);
			}
			
			vis[rvtx.vtx]=true;

            for(Edge e:graph[rvtx.vtx]){
                if(!vis[e.v]){
                    que.addLast(new Pair(e.v, rvtx.psf + e.v));
                }
            }
        }
    }

    // static void BFS_02(int src, boolean[] vis){
    //     LinkedList<Pair> que = new LinkedList<>();
    //     que.addLast(new Pair(src, ""));
    //     que.addLast(null);

    //     int level =0;
    //     int dest = 6;

    //     while(que.size()!=0){

    //         Pair rvtx = que.removeFirst();

    //         if(vis[rvtx.vtx]){
	// 			System.out.println("Cycle: " + rvtx.psf);
	// 			continue;
	// 		}

	// 		if(rvtx.vtx==desti){
	// 			System.out.println("destinantion: " + rvtx.psf + " -> " + level);
	// 		}
			
	// 		vis[rvtx.vtx]=true;

    //         for(Edge e:graph[rvtx.vtx]){
    //             if(!vis[e.v]){
    //                 que.addLast(new Pair(e.v, rvtx.psf));
    //             }
    //         }

    //         if(que.getFirst()==null){
	// 			level++;
	// 			que.removeFirst();
	// 			que.addLast(null);
	// 		}
    //     }
    // }

    // static void BSF_03(int src, boolean[] vis){

    //     LinkedList<Pair> que = new LinkedList<>();
    //     que.addLast(new Pair(src, src+" "));
    //     que.addLast(null);

    //     int dest = 6;
        
    //     while(que.size()!=0){
    //         Pair rvtx = que.removeFirst();

    //         if(vis[rvtx.vtx]){
    //             System.out.println("Cycle: "+ rvtx.psf);
    //             continue;
    //         }

    //         if(rvtx.vtx == dest){
    //             System.out.println("destination: " + rvtx.psf + "->" + rvtx.level);
    //         }

    //         vis[rvtx.vtx] = true;

    //         for(Edge e: graph[rvtx.vtx]){
    //             if(!vis[rvtx.vtx])
    //                 que.addLast(new Pair(e.v, rvtx.psf + e.v, rvtx.level+1));
    //         }

    //     }
    // }

    // static class Pair{
    //     int s;
    //     int color;
        
    //     Pair(int src, int color){
    //         this.s = src;
    //         this.color = color;
    //     }
    // }
    
    // public static boolean isBipartite_bfs(int[][] graph, int src, int[] vis){
        
    //     LinkedList<Pair> que = new LinkedList<>();
    //     que.addLast(new Pair(src, 0));
        
    //     while(que.size()!=0){
    //         int size = que.size();
            
    //         while(size-- >0){
    //             Pair vtx = que.removeFirst();
                
    //             if(vis[vtx.s] != 0){
                    
    //                 if(vis[vtx.s]%2 != vtx.color%2)
    //                     return false;
    //             }
                
    //             vis[vtx.s] = vtx.color;
                
    //             // int i = vtx.s/graph[0].length;
    //             // int j = vtx.s%graph[0].length;
                
    //             for(int e : graph[vtx.s]){
    //                 // int nbr = e * graph[0].length + j;
    //                 if(vis[e] == 0)
    //                     que.addLast(new Pair(e, vtx.color + 1));
    //             }
    //         }
    //     }
    //     return true;
    // }
    
    //another method - bipartite using int[]..
    public static boolean isBipartite_bfs_02(ArrayList<Edge>[] graph, int src, int[] vis){
        
        LinkedList<int[]> que = new LinkedList<>();
        que.addLast(new int[]{src, 0});
        
        while(que.size()!=0){
            int size = que.size();
            
            while(size-- >0){
                int[] vtx = que.removeFirst();
                
                if(vis[vtx[0]] != 0){
                    
                    if(vis[vtx[0]]%2 != vtx[1]%2)
                        return false;
                }
                
                vis[vtx[0]] = vtx[1];
                
                // int i = vtx.s/graph[0].length;
                // int j = vtx.s%graph[0].length;
                
                for(Edge e : graph[vtx[0]]){
                    // int nbr = e * graph[0].length + j;
                    if(vis[e.v] == 0)
                        que.addLast(new int[]{e.v, vtx[1] + 1});
                }
            }
        }
        return true;
    }

    public static boolean isBipartite(ArrayList<Edge>[] graph) {
        
        int n = graph.length;
        if(n == 0) return true;
        
        int m = graph[0].size();
        
        int[] vis = new int[n];
        
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                boolean ans = isBipartite_bfs_02(graph, i, vis);
                if(!ans)return false;
            }
        }
        return true;
    }

    public static void constructgraph(){

        graph = new ArrayList[N];
        for(int i=0; i<N; i++){
            graph[i] = new ArrayList<Edge>();
        }

        addEdge(graph, 0, 1, 10);
        addEdge(graph, 1, 2, 10);
        addEdge(graph, 2, 3, 40);
        addEdge(graph, 0, 3, 10);
        addEdge(graph, 3, 4, 2);
        addEdge(graph, 4, 5, 6);
        addEdge(graph, 4, 6, 8);
        addEdge(graph, 5, 6, 3);

        display(graph);

        // removeEdge(3, 4);
        // display(graph);

        // removeVtx(3);
        // display(graph);

        boolean[] vis = new boolean[N];
        BFS_01(0, vis);
        // System.out.println(hasPath(0, 6, vis));
        // System.out.println(printPath(0,6,0, vis,""));
        // System.out.println("---------------------");
        // Pair pair = new Pair();
        // allSolution(0,6,0, vis,"",pair,20);
        // System.out.println("Largest-:"+pair.lps+"@"+pair.largeW);
        // System.out.println("smallest-:"+pair.sps+"@"+pair.smallW);
        // System.out.println("ciel path-:"+pair.cps+"@"+pair.ciel);
        // System.out.println("floor path-:"+pair.fps+"@"+pair.floor);

        //System.out.println(isBipartite(graph));

    }
}