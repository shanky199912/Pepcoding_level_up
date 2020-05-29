//hackerEarth- https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/mr-president/
#include<iostream>
#include<vector>
#include<algorithm>
 
#define lli long long int
using namespace std;
 
vector<int> par;
 
int findPar(int vtx){
 
    if(par[vtx] == vtx) return vtx;
    return par[vtx] = findPar(par[vtx]);
}
 
int mrPresident(){
 
    lli n,m,k;
    cin>> n >> m >> k;
 
    vector<vector<int>> graph, kruskalGraph;
 
    while(m--){
 
        int u, v, w;
        cin>> u>> v >> w;
 
        vector<int> ar = {u,v,w};
        graph.push_back(ar);
    }
 
	sort(graph.begin(), graph.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });
 
    for(int i=0; i<=n; i++){
        par.push_back(i);
    }
 
    lli MstCost = 0;
    for(vector<int> gp: graph){
 
        int p1 = findPar(gp[0]);
        int p2 = findPar(gp[1]);
 
        if(p1 != p2){
            par[p1] = p2;
			kruskalGraph.push_back(gp);
            MstCost += gp[2];
           
        }
    }
 
    int component = 0;
    for(int i=1; i<=n; i++) if(par[i] == i && ++component > 1 ) return -1;
 
    int roads = 0;
    for(int i= kruskalGraph.size()-1; i>=0; i--){
 
        if(MstCost <= k){
            break;
        }
        MstCost = MstCost - kruskalGraph[i][2] + 1;
        roads++;
    }
 
    return MstCost <= k ? roads : -1;
}
 
//fast input output.
auto SpeedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
 
int main(){
	cout<<mrPresident();
	return 0;
}