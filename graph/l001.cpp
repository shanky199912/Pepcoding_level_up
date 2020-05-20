#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

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

string gscc_bfs(int src, vector<bool> &visited){

    queue<int> que;
    que.push(src);
    string comp ="";

    while(que.size()!=0){
        int rvtx = que.front(); que.pop();

        if(visited[rvtx]){
            continue;
        }
        visited[rvtx] = true;

        comp += to_string(rvtx);
        for(Edge* e: graph[rvtx]){
            if(!visited[e->v]){
                que.push(e->v);
            }
        }
    }
    return comp;
}

bool isConnected(){
    vector<bool> visited(N,false);
    int counter = 0;
    for(int i=0; i<N; i++){
        if(!visited[i]){
            //string ans = gscc_bfs(i,visited);
            int ans = dfs_components(i,visited);
            counter++;

            if(counter ==2)return false;
        }
    }
    return true;
}

vector<string> gcc(){
    vector<bool> visited(N,false);
    vector<string> ans;
    int counter = 0;
    for(int i=0; i<N; i++){
        if(!visited[i]){
            counter++;
            string comp = gscc_bfs(i,visited);
            ans.push_back(comp);
        }
    }
    cout<<counter<<endl;
    return ans;
}

bool isCyclic_bfs(int src, vector<bool>& vis){
    queue<int> que;
    que.push(src);
    //bfs ka 5th method lagaya h -> cycle vala
    while(que.size()!=0){
        int size = que.size();

        while(size-- >0){
            int rvtx = que.front(); que.pop();
            if(vis[rvtx]){
                return true;
            }
            vis[rvtx] = true;
            for(Edge* e: graph[rvtx])
                if(!vis[e->v]) que.push(e->v);
        }
    }
    return false;
}
bool isCyclic(){
    vector<bool> vis(N,false);
    bool ans = false;
    for(int i=0; i<N; i++){
        if(!vis[i]){
            ans = ans || isCyclic_bfs(i, vis);
        }
    }
    return ans;
}
//1st method where we use queue of type pair. pair stores two values int and string. 
void BFS_01(int src, vector<bool> &vis){
    queue<pair<int,string>> que;
    que.push({src, to_string(src) + ""});

    int dest = 6;

    while(que.size()!=0){

        pair<int,string> rvtx = que.front(); que.pop();

        if(vis[rvtx.first]){ //cycle hai?
            cout<<"Cycle: "<<rvtx.second<<endl;
            continue;
        }

        if(rvtx.first == dest){
            cout<<"destination: "<<rvtx.second<<endl;
        }

        vis[rvtx.first] = true;

        for(Edge* e: graph[rvtx.first]){

            if(!vis[e->v]){
                que.push({e->v, rvtx.second + to_string(e->v)});
            }
        }
    }
}

//2nd method where we make a pair class instead of using pair (usually c++ has pair but java doesnt, so make pair class in java)
void BFS_02(){
    //In java
    // delemeter vala h jisme null dalte h queue me 
    // aur jahan null hota h vahan pe level ka count bda lete.
}

void BFS_03(){
    //In java
    // delemeter vala h jisme null dalte h queue me 
    // yahan pair class me ek level name ka variable rkh lete aur usse bda lete jab bhi null mile.
}

void BFS_04(){
 // 2 QUEUE USE KRNE VALA METHOD.
}

void BFS_05(int src, vector<bool> &vis){

    queue<int> que;
    que.push(src);

    int level = 0;
    int cycle = 0;
    int dest = 6;

    while(que.size()!=0){
        int size = que.size();

        while(size-- >0){
            int rvtx = que.front(); que.pop();

            if(vis[rvtx]){ //cycle
                cout << "Cycle No. " + to_string(cycle) + ": " << rvtx << endl;
                cycle++;
                continue;
            }

            if(rvtx == dest){
                cout<<"dest:"<<level<<endl;
            }

            vis[rvtx] = true;
            for(Edge* e: graph[rvtx]){

                if(!vis[e->v]){
                    que.push(e->v);
                }
            }

        }
        level++;
    }
}

void BFS_06(int src, vector<bool> &vis){

    queue<int> que;
    que.push(src);
    vis[src] = true;

    int level = 0;
    int dest = 6;

    while(que.size() != 0){
        int size = que.size();

        while(size-- >0){
            int rvtx = que.front();
            que.pop();

            if(rvtx == dest){
                cout << "dest:" << level << endl;
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

bool isBipartiteBfs_02(int src, vector<int>& vis){
    
    queue<pair<int,int>> que; //int-src, int-level; 
    que.push({src,0});

    while(que.size()!=0){
        pair<int,int> vtx = que.front(); que.pop();

        if(vis[vtx.first] != 0){
            //do some work.
            if(vis[vtx.first]%2 != vtx.second%2)
                return false;
        }
        vis[vtx.first] = vtx.second;

        for(Edge* e: graph[vtx.first])
            if(vis[e->v] == 0)
                que.push({e->v, vtx.second + 1});
    }
    return true;
}

bool isBipartite_02(){
    vector<int> vis(N, 0);
    for(int i=0; i<N; i++){
        if(vis[i]==0){
            bool ans = isBipartiteBfs_02(i, vis);
            if(ans==false)
                return false;
        }
    }
    return true;
}

bool isBipartiteBfs(int src, vector<int> &vis){

    queue<pair<int,int>> que; //int -> src, int-> color(0,1,-1)
    que.push({src, 0});

    int cycle = 0;

    while(que.size()!=0){
        int size = que.size();
        while (size-- > 0)
        {
            pair<int, int> rvtx = que.front();
            que.pop();

            if (vis[rvtx.first] != -1) // already visited(cycle).
            {   cycle++;
                if (vis[rvtx.first] != rvtx.second) // check for conflict.
                    return false;
            }

            vis[rvtx.first] = rvtx.second;
            for (Edge* e : graph[rvtx.first])
            {
                if (vis[e->v] == -1)
                    que.push({e->v, (rvtx.second + 1) % 2}); 
            }
        }
    }
}
void isBipartite(){

    vector<int> vis(N,-1); // -1 ->unvisited 0 ->red 1 -> green
    for(int i=0; i<N; i++){
        if(vis[i]==-1){
            cout<<isBipartiteBfs(i,vis)<<endl;
        }
    }
}

vector<int> par;
vector<int> setSize;

int findPar(int vtx){
    if(par[vtx] == vtx)
        return vtx;
    return par[vtx] = findPar(par[vtx]); //Path Compression -> overall parent nikal rhe h.
}

void mergeSet(int l1, int l2){
    if(setSize[l1] < setSize[l2]){

        par[l1] = l2;
        setSize[l2] += setSize[l1];
    }
    else{
        par[l2] = l1;
        setSize[l1] += setSize[l2];
    }
}

// void kruskalsAlgo(vector<vector<int>>& arr){

//     vector<vector<Edge*>> Kgraph(arr.size(), vector<Edge*>());
    
//     for(vector<int> &ar: arr){

//         int u = arr[0];
//         int v = ar[1];

//         int p1 = findPar(u);
//         int p2 = findPar(v);

//         if(p1 != p2){
//             mergeSet(p1, p2);
//             addEdge()
//         }
//     }
// }

class dpair{
    public:
        int src;
        int parent;
        int w;
        int wsf;

        dpair(int src, int parent, int w, int wsf){
            this-> src = src;
            this->parent = parent;
            this->w= w;
            this->wsf = wsf;
        }
};

struct Dcomp{
    public:
        bool operator()(dpair &p1, dpair &p2){
            return p1.wsf > p2.wsf;  //default behavior (this - other) - max.
            // return p2.wsf > p1.wsf;
        }
};

void dijikstraAlgo(int src){

    vector<vector<Edge*>> dkgraph(N, vector<Edge*>());

    priority_queue<dpair, vector<dpair>, Dcomp> pq;
    vector<bool> vis(N, false);
    pq.push(dpair(src, -1, 0, 0));

    while(pq.size() !=0){
        int size = pq.size();
        while(size-- >0){
            dpair vtx = pq.top(); pq.pop();

            if(vis[vtx.src])
                continue;

            if(vtx.parent != -1)
                addEdge(dkgraph, vtx.src, vtx.parent, vtx.w);

            vis[vtx.src] = true;

            for(Edge* e: graph[vtx.src]){
                if(!vis[e->v])
                    pq.push(dpair(e->v, vtx.src, e->w, vtx.wsf + e->w));
            }
        }
    }

    display(dkgraph);
}

class ppair{
    public:
        int src;
        int parent;
        int w;

        ppair(int src, int parent, int w){
            this->src = src;
            this->parent  = parent;
            this->w = w;
        }
};

struct Pcomp{
    public:
        bool operator()(ppair &p1, ppair &p2){
            return p1.w > p2.w; 
        }
};

void PrimsAlgo(int src){

    vector<vector<Edge *>> Pgraph(N, vector<Edge *>());

    priority_queue<ppair, vector<ppair>, Pcomp> pq;
    pq.push(ppair(src, -1, 0));
    vector<bool> vis(N, false);

    while(pq.size() != 0){
        int size = pq.size();
        while(size-- >0){
            ppair rvtx = pq.top();
            pq.pop();

            if(vis[rvtx.src])
                continue;
            
            if(rvtx.parent != -1)
                addEdge(Pgraph, rvtx.src, rvtx.parent, rvtx.w);
            
            vis[rvtx.src] = true;

            for(Edge * e : graph[rvtx.src])
                if(!vis[e->v])
                    pq.push(ppair(e->v, rvtx.src, e->w));
        }
    }
    display(Pgraph);
}
void contsructgraph(){

    addEdge(graph,0,1,20);
    addEdge(graph,1,2,20);
    addEdge(graph,0,3,10);
    addEdge(graph,2,3,40);
    addEdge(graph,3,4,2);
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
    //cout<<printPath(0,6,0,vis,"")<<endl;
    // cout<<"--------"<<endl;
    // AllsolutionPair pair;
    // cout<<allSolution(0,6,0,vis,"",pair,20)<<endl;
    // cout<<"Largest-:"<<pair.lps<<"@"<<pair.heavyW<<endl;
    // cout<<"smallest-:"<<pair.sps<<"@"<<pair.lightW<<endl;
    // cout<<"ciel path-:"<<pair.cps<<"@"<<pair.ciel<<endl;
    // cout<<"floor path-:"<<pair.fps<<"@"<<pair.floor<<endl;

    //cout<<hamiltonianPath(2,2,vis,0,"")<<endl;
    //cout<<getcomponents()<<endl;
    
    // BFS_05(0,vis);
    // BFS_04(0, vis);
    // cout<<(boolalpha)<<isConnected()<<endl;
    // vector<string> ans = gcc();
    // for(string val: ans){
    //     cout<<val<<" ";
    // }
    // cout<<endl;
    //cout<<(boolalpha)<<isBipartite_02()<<endl;

    dijikstraAlgo(2);
    PrimsAlgo(2);
    PrimsAlgo(6);
}

int main(){
    contsructgraph();
    questions();
    return 0;
}