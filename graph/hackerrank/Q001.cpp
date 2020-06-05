//HackerRank- https://www.hackerrank.com/contests/pepcoding-scholarstest-3june2020/challenges/vouchingconnections
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool callBFS(int src, vector<int>& vis, vector<pair<vector<int>,vector<int>>>& graph){
    queue<pair<int,int>> que;
    que.push({src, -1});
    
    while(que.size() != 0){
        int size = que.size();
        while(size-- > 0){
            pair<int,int> rvtx = que.front(); que.pop();
            
            if(vis[rvtx.first] != -1){
                if(vis[rvtx.first] != rvtx.second) return false;
                else
                    continue;
            }
            
            vis[rvtx.first] = rvtx.second;
            for(int e : graph[src].first){ //infected vala
                que.push({e, 0});
            }
            
            for(int e : graph[src].second){ //Not infected vala
                que.push({e, 1});
            }
        }
    }
    
    return true;
}

void solveCovid19(){
    int n;
    cin >> n;
    int t = 0;
    vector<pair<vector<int>,vector<int>>> graph(n, pair<vector<int>,vector<int>>());
    
    while(t++ < n){
        int p, q;
        int u, v;
        cin >> p >> q;
        
        for(int j=0; j<p; j++){
            cin >> u;
            graph[t].first.push_back(u);
        }
        
        for(int k=0; k<q; k++){
            cin >> v;
            graph[t].second.push_back(v);
        }
    }
    
    vector<int> vis(n, -1);
    
    for(int i=0; i<n; i++){
        if(vis[i] == -1){
            
            bool res = callBFS(i, vis, graph);
            
            if(res == false){
               cout << res << endl;
               return;
            }
        }
    }
    
    cout << true <<endl;
    return;
}

auto SpeedUp = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int main(){
    solveCovid19();
    return 0;
}