#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// class Pair{
// public:
//     int v = 0;
//     int w = 0;

//     Pair(int v, int w){
//         this->v = v;
//         this->w = w;
//     }
// }

int N = 7;
vector<vector<int>> graph(N, vector<int>());

void display(vector<vector<int>> &gp){

    for(int i=0; i<N; i++){
        cout<<i<<"->";
        for(int e: gp[i]){
            cout<<e<<",";
        }
        cout<<endl;
    }

    cout<<endl;
}

void topologicalsort_dfs(int src, vector<bool>& vis, vector<int>& ans){

    vis[src] = true;

    for(int e : graph[src])
        if(!vis[e])
            topologicalsort_dfs(e, vis, ans);
    
    ans.push_back(src);
}

void topologicalsort(){
    vector<bool> vis(N, false);
    vector<int> ans;

    for(int i=0; i<N; i++){
        if(!vis[i])
            topologicalsort_dfs(i, vis, ans);
    }

    for(int i=ans.size()-1; i>=0; i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

void kahnsAlgo(){
    vector<int> indegree(N, 0);
    for(int i=0; i<N; i++){
        for(int e: graph[i])
            indegree[e]++;
    }

    queue<int> que;
    for(int i=0; i<N; i++){
        if(indegree[i] == 0)
            que.push(i);
    }

    vector<int> ans;

    while(que.size()!=0){
        int size = que.size();
        while(size-- >0){
            int vtx = que.front(); que.pop();
            
            ans.push_back(vtx);

            for(int e: graph[vtx])
                if(--indegree[e] == 0)
                    que.push(e);
        }
    }

    if(ans.size() != N) cout<<"Cycle"<<endl;
    else
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
}

void constructgraph(){
    
    graph[0].push_back(1);
    graph[0].push_back(3);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(5);
    graph[3].push_back(4);
    graph[5].push_back(4);
    graph[5].push_back(6);
    graph[4].push_back(6);

    display(graph);
    topologicalsort();
    kahnsAlgo();
}

void solve(){
    constructgraph();
}

int main(){
    solve();
    return 0;
}