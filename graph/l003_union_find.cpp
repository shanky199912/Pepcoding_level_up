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

vector<int> par;
vector<int> setSize;

int findPar(int vtx){

    if(par[vtx] == vtx) return vtx;
    return par[vtx] = findPar(par[vtx]);
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

void unionfind(){

}

void addEdge(vector<vector<Edge*>> &gp, int u, int v, int w){

    gp[u].push_back(new Edge(v,w));
    gp[v].push_back(new Edge(u,w));

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
    // addEdge(graph,2,5,2);

    display(graph);
}

void solve(){
    contsructgraph();
}

int main(){
    solve();
    return 0;
}