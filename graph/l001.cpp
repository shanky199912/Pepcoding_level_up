#include<iostream>
#include<vector>
#include<queue>

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

    int vtx=-1;
    for(int i=0; i<graph[v1].size(); i++){

        Edge* e = graph[v1][i];
        
        if(e->v == v2){
            vtx = i;
            break;
        }
    }
    return vtx;
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

class AllsolutionPair{
public:
    int heavyW = 0; //largestpath
    string lps = "";
    int lightW = 1e7;//smallest path
    string sps = "";
    int ciel = 1e7;
    string cps = "";
    int floor = 0;
    string fps = "";
};
// find largest , smallest, ciel(smallest among larger than k), floor(largest among smaller than k) path 
//ciel - k se just bda path
//floor - k se just chota path.
int allSolution(int src, int dest, int w, vector<bool>& vis, string ans, AllsolutionPair &pair, int k){
    if(src == dest){
        //cout<<ans+to_string(dest)<<"@"<<w<<endl;
        if(w > pair.heavyW){
            pair.heavyW = w;
            pair.lps = ans + to_string(dest);
        }

        if(w < pair.lightW){
            pair.lightW = w;
            pair.sps = ans + to_string(dest);
        }

        if(w > k && w < pair.ciel){
            pair.ciel = w;
            pair.cps = ans + to_string(dest);
        }

        if(w < k && w > pair.floor){
            pair.floor = w;
            pair.fps = ans + to_string(dest);
        }

        return 1;
    }

    vis[src] = true;
    int count = 0;
    for(int i=0; i<graph[src].size(); i++){
        Edge* e = graph[src][i];
        if(!vis[e->v]){
            count += allSolution(e->v, dest, w + e->w, vis, ans + to_string(src), pair,k);
        }
    }
    vis[src] = false;
    return count;
}

int hamiltonianPath(int src, int osrc, vector<bool>& vis, int count, string ans){
    if(count == vis.size()-1){

        int idx = findEdge(src,osrc);
        if(idx != -1){
            cout<<"Cycle :"<<ans + to_string(src)<<endl;
        }else{
            cout<<"Path :"<<ans + to_string(src)<<endl;
        }
        return 1;
    }

    vis[src] = true;
    int cnt = 0;
    for(Edge* e: graph[src]){
        if(!vis[e->v]){
            cnt += hamiltonianPath(e->v, osrc, vis, count+1, ans + to_string(src));
        }
    }
    vis[src] = false;
    return cnt;
}

int dfs_components(int src , vector<bool> &vis){
    int count = 0;
    vis[src] = true;
    for(Edge* e:graph[src]){
        if(!vis[e->v])
            count += dfs_components(e->v, vis);
    }
    return count+1;
}

int getcomponents(){
    vector<bool> vis(N, false);

    int count = 0;
    int maxsize = 0;
    for(int i=0; i<N; i++){
        if(!vis[i]){
            count++;
            int cnt = dfs_components(i,vis);
            maxsize = max(cnt, maxsize);   
        }
    }
    //cout<<maxsize<<endl;
    return count;
}

void BFS_04(int src, vector<bool>& vis){

    queue<int> que;
    que.push(src);
    vis[src] = true;

    int level = 0;
    int cycle = 0;
    int dest = 6;

    while(que.size()!=0){
        int size = que.size();

        while(size-->0){
            int rvtx = que.front();
            que.pop();

            if(rvtx == dest){
                cout<<"dest:"<<level<<endl;
            }

            for(Edge* e: graph[rvtx]){
                if(!vis[e->v]){
                    que.push(e->v);
                    vis[e->v] = true;
                }
            }

        }
        level++;
    }
}


void contsructgraph(){

    addEdge(graph,0,1,10);
    addEdge(graph,1,2,10);
    addEdge(graph,0,3,10);
    addEdge(graph,2,3,40);
    // addEdge(graph,3,4,2);
    addEdge(graph,4,5,2);
    addEdge(graph,5,6,8);
    addEdge(graph,4,6,3);
    // addEdge(graph,2,5,2);

    display(graph);
}
void questions(){
    // removeEdge(3,4);
    // display(graph);
    // removeVtx(3);
    // display(graph);

    vector<bool> vis(N,false);
    //cout<<hasPath(0,6,vis)<<endl;
    //cout<<"--------"<<endl;
    cout<<printPath(0,6,0,vis,"")<<endl;
    cout<<"--------"<<endl;
    AllsolutionPair pair;
    // cout<<allSolution(0,6,0,vis,"",pair,20)<<endl;
    // cout<<"Largest-:"<<pair.lps<<"@"<<pair.heavyW<<endl;
    // cout<<"smallest-:"<<pair.sps<<"@"<<pair.lightW<<endl;
    // cout<<"ciel path-:"<<pair.cps<<"@"<<pair.ciel<<endl;
    // cout<<"floor path-:"<<pair.fps<<"@"<<pair.floor<<endl;

    //cout<<hamiltonianPath(2,2,vis,0,"")<<endl;
    cout<<getcomponents()<<endl;

}

int main(){
    contsructgraph();
    questions();
    return 0;
}