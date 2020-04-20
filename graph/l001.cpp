#include<iostream>
#include<vector>

using namespace std;

class Edge{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w){
        this->v = v;
        this->w = w;

    }
};

int N = 7;
vector<vector<Edge*>> graph(N,vector<Edge*>());

void addEdge(vector<vector<Edge*>> &gp, int u, int v, int w){

    gp[u].push_back(new Edge(v,w));
    gp[v].push_back(new Edge(u,w));

}

int findEdge(int v1 , int v2){

    int i=0;
    for(i=0; i<graph[v1].size(); i++){

        Edge* e = graph[v1][i];
        
        if(e->v == v2){
            break;
        }
    }
    return i;
}

void removeEdge(int u, int v){
    
    int idx1 = findEdge(u,v);
    int idx2 = findEdge(v,u);

    graph[u].erase(graph[u].begin() + idx1);
    graph[v].erase(graph[v].begin() + idx2);
}

void removeVtx(int vtx){

    while(graph[vtx].size()!=0){

        //Edge* e = graph[vtx][graph[vtx].size()-1];
        Edge* e = graph[vtx].back();
        removeEdge(vtx, e->v);
    }
}

void display(vector<vector<Edge*>> &gp){

    for(int i=0; i<N; i++){
        cout<<i<<"->";
        for(Edge* e: gp[i]){
            cout<<"("<<e->v<<","<<e->w<<")"<<",";
        }
        cout<<endl;
    }

    cout<<endl;
}

// Questions===================================

//flow of dfs -> 1.mark kro   then
//-------------> 2.nbrs nikalo vtx ke and call lgao.
bool hasPath(int src , int dest, vector<bool>& vis){

    if(src == dest){
        return true;
    }

    vis[src] = true;
    bool ans = false;
    for(int i=0; i<graph[src].size(); i++){
        Edge* e = graph[src][i];
        if(!vis[e->v]){
            ans = ans || hasPath(e->v , dest, vis);
        }
    }
    return ans;
}

int printPath(int src, int dest, int w, vector<bool>& vis, string ans){
    if(src == dest){
        cout<<ans+to_string(dest)<<"@"<<w<<endl;
        return 1;
    }

    vis[src] = true;
    int count = 0;
    for(int i=0; i<graph[src].size(); i++){
        Edge* e = graph[src][i];
        if(!vis[e->v]){
            count += printPath(e->v, dest, w + e->w, vis, ans + to_string(src));
        }
    }
    vis[src] = false;
    return count;
}



void contsructgraph(){

    addEdge(graph,0,1,10);
    addEdge(graph,1,2,10);
    addEdge(graph,0,3,10);
    addEdge(graph,2,3,40);
    addEdge(graph,3,4,2);
    addEdge(graph,4,5,2);
    addEdge(graph,5,6,8);
    addEdge(graph,4,6,3);

    display(graph);
}
void questions(){
    // removeEdge(3,4);
    // display(graph);
    // removeVtx(3);
    // display(graph);
    
    vector<bool> vis(N,false);
    //cout<<hasPath(0,6,vis)<<endl;
    cout<<"--------"<<endl;
    cout<<printPath(0,6,0,vis,"")<<endl;
}

int main(){
    contsructgraph();
    questions();
    return 0;
}