import java.util.ArrayList;

class l001{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        constructgraph();
    }

    class Edge{
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

    

    public static void constructgraph(){

        graph = new ArrayList[N];
        for(int i=0; i<N; i++){
            graph[i] = new ArrayList<Edge>();
        }
    }
}