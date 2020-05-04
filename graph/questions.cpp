#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
bool isSafe(int r, int c, int m, int n, vector<vector<char>>& board){
    if(r<0 || c<0 || r>=n || c>= m || board[r][c] != 'O'){
        return false;
    }
    return true;
}

void surroundregions_dfs_02(int r, int c, int n , int m, vector<vector<char>>& board){

    board[r][c] = '#';

    for(int d =0; d<dir.size(); d++){

        int row = r + dir[d][0];
        int col = c + dir[d][1];

        if(isSafe(row,col,m,n,board)){
            surroundregions_dfs_02(row,col,n,m,board);
        }
    }
    return;
}
//leetcode-130=============================================
void surroundregions_dfs(int r, int c, int n, int m, vector<vector<char>>& board){

    if(board[r][c] != 'O') return;

    //mark
    board[r][c] = '#';
    if(r-1>=0){
        surroundregions_dfs(r-1,c,n,m, board);
    }
    if(c-1>=0){
        surroundregions_dfs(r,c-1,n,m, board);
    }
    if(r+1<n){
        surroundregions_dfs(r+1,c,n,m, board);
    }
    if(c+1<m){
        surroundregions_dfs(r,c+1,n,m, board);
    }
}

void solve(vector<vector<char>>& board){

    if(board.size() == 0) return;

    int n = board.size();
    int m = board[0].size();

    for(int i=0; i<n; i++){
        if(board[i][0] == 'O'){
            surroundregions_dfs(i, 0, n, m ,board);
        }

        if(board[i][m-1] == 'O'){
            surroundregions_dfs(i, m-1, n, m, board);
        }
    }

    
    for(int i=0; i<m; i++){
        if(board[0][i] == 'O'){
            surroundregions_dfs(0, i, n, m ,board);
        }

        if(board[n-1][i] == 'O'){
            surroundregions_dfs(n-1, i, n, m, board);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == '#'){
                board[i][j] = 'O';
            }
            else if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
    }
}

//leetcode-200=============================================
void dfs_islands(int r, int c, int n, int m, vector<vector<char>>& board){

    if(board[r][c] != '1') return;

    //mark
    board[r][c] = '2';
    if(r-1>=0){
        dfs_islands(r-1,c,n,m, board);
    }
    if(c-1>=0){
        dfs_islands(r,c-1,n,m, board);
    }
    if(r+1<n){
        dfs_islands(r+1,c,n,m, board);
    }
    if(c+1<m){
        dfs_islands(r,c+1,n,m, board);
    }
}

int numIslands(vector<vector<char>>& board){

    if(board.size() == 0) return;

    int count = 0;
    int n = board.size();
    int m = board[0].size();

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size();j++){
            if(board[i][j] == '1'){
                count++;
                dfs_islands(i,j,n,m,board);
            }
        }
    }

    return count;
}

//leetcode-695=============================================
int dfs_maxArea(int r, int c, int n, int m, vector<vector<int>>& board){

    if(board[r][c] != 1) return 0;

    //mark
    board[r][c] = 2;
    int count = 0;
    if(r-1>=0){
        count += dfs_maxArea(r-1,c,n,m, board);
    }
    if(c-1>=0){
        count += dfs_maxArea(r,c-1,n,m, board);
    }
    if(r+1<n){
        count += dfs_maxArea(r+1,c,n,m, board);
    }
    if(c+1<m){
        count += dfs_maxArea(r,c+1,n,m, board);
    }

    return count+1;
}

int maxAreaOfIsland(vector<vector<int>>& board){

    if(board.size() == 0) return 0;

    int n = board.size();
    int m = board[0].size();
    int maxsize = 0;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size();j++){
            if(board[i][j] == 1){
                
                int count = dfs_maxArea(i,j,n,m,board);
                maxsize = max(count, maxsize);
            }
        }
    }

    return maxsize;
}

//leetcode-463=================================

int islandPerimeter(vector<vector<int>>& board){

    if(board.size() == 0){
        return 0;
    }

    int n = board.size();
    int m = board[0].size();

    int count_ones = 0;
    int count_regions = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(board[i][j] == 1){
                count_ones++;

                if(j+1 <m && board[i][j+1] == 1){
                    count_regions++;
                }

                if(i+1<n && board[i+1][j] == 1){
                    count_regions++;
                }
            }
        }
    }

    return (4 * count_ones - 2 * count_regions);
}

//leetcode -1091=============================================================
int shortestPathBinaryMatrix(vector<vector<int>>& board) {
    int n = board.size();
    int m = board[0].size();

    if (n == 0)
        return -1;
    
    if (m == 0)
        return -1;

    if (board[0][0] == 1 || board[n - 1][m - 1] == 1)
        return -1;
    
    queue<int> que;
    int dirA[8][2] = {{-1, -1}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {1, 1}};
    que.push(0);
    board[0][0] = 1;

    int level = 1;
    while(que.size()!=0){

        int size = que.size();

        while(size-- >0){

            int rvtx = que.front();
            que.pop();

            int r = rvtx/m;
            int c = rvtx%m;

            for(int d=0; d<8; d++){
                int x = r + dirA[d][0];
                int y = c + dirA[d][1];

                if (r == n - 1 && c == m - 1)
                    return level;

                if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 0)
                {
                    que.push((x * m + y));
                    board[x][y] = 1;
                }
            }
        }
        level++;
    } 

    return -1;
}

//leetcode -286=================================================
int wallsandgate(vector<vector<int>>& board){

    int n = board.size();
    int m = board[0].size();

    if (n == 0)
        return -1;
    
    if (m == 0)
        return -1;

    if (board[0][0] == 1 || board[n - 1][m - 1] == 1)
        return -1;
    
    queue<int> que;
    int dirA[8][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0)
                que.push((i * m + j));

    int level = 1;
    while(que.size()!=0){

        int size = que.size();

        while(size-- >0){

            int rvtx = que.front();
            que.pop();

            int r = rvtx/m;
            int c = rvtx%m;

            for(int d=0; d<4; d++){
                int x = r + dirA[d][0];
                int y = c + dirA[d][1];

                if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 2147483647)
                {
                    que.push((x * m + y));
                    board[x][y] = level;
                }
            }
        }
        level++;
    } 

    return -1;
}

//leetcode -994=============================================
int orangesRotting(vector<vector<int>> &board) {
    
    int n = board.size();
    int m = board[0].size();

    if (board.size() == 0 || board[0].size() == 0)
        return-1;
        
        queue<int> que;
        int dirA[8][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 2)
                    que.push((i * m + j));

        int level = 0;
        while(que.size()!=0){

            int size = que.size();

            while(size-- >0){

                int rvtx = que.front();
                que.pop();

                int r = rvtx/m;
                int c = rvtx%m;

                for(int d=0; d<4; d++){
                    int x = r + dirA[d][0];
                    int y = c + dirA[d][1];

                    if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 1)
                    {
                        que.push((x * m + y));
                        board[x][y] = 2;
                    }
                }
            }
            level++;
        } 

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 1)
                    return -1;


    return (level==0)?0:level-1;
}

//leetcode -207=======================================================
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
    vector<vector<int>> graph(numCourses, vector<int>());
    for(vector<int> ar[] : prerequisites)
        graph[ar[0]].push_back(ar[1]);

    return kahnsAlgo(graph, numCourses);

}

bool kahnsAlgo(vector<vector<int>>& graph, int N){

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

    if(ans.size()!= N) return false;
    else
        return true;
}

//leetcode-210=======================================================
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
    if(prerequisites.size() == 0) return {};

    vector<vector<int>> graph(numCourses, vector<int>());
    for(vector<int> ar : prerequisites)
        graph[ar[0]].push_back(ar[1]);

    vector<int> ans;
    kahnsAlgo2(graph, numCourses, ans);
    
    if(ans.size() != numCourses) return {};

    vector<int> list;
    for(int i= ans.size()-1; i>=0; i--) list.push_back(ans[i]);
    return list;
}

void kahnsAlgo2(vector<vector<int>>& graph, int N, vector<int>& ans){

    vector<int> indegree(N, 0);
    for(int i=0; i<N; i++){
        for(int e: graph[i])
            indegree[e]++;
    }

    queue<int> que;
    for(int i=0; i<N; i++)
        if(indegree[i] == 0)
            que.push(i);

    while(que.size()!=0){
        int size = que.size();
        while(size-- >0){
            int vtx = que.front();  que.pop();

            ans.push_back(vtx);

            for(int e: graph[vtx])
                if(--indegree[e] == 0)
                    que.push(e);
        }
    }
}

int longestIncreasingPath(vector<vector<int>>& matrix) {

    if(matrix.size() == 0 || matrix[0].size() == 0) return 0;

    int n = matrix.size();
    int m = matrix[0].size();

    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> indegree(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int d=0; d<4; d++){

                int x = i + dir[d][0];
                int y = j + dirp[d][1];

                if(x>=0 && x<n && y>=0 && y<m && matrix[x][y] > matrix[i][j])
                    indegree[x][y]++;
            }
        }
    }

    queue<int> que;

    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            if(indegree[i][j] == 0)
                que.push(i*m + j); //2d to 1d.
        }
    }

    int level = 0;
    while(que.size()! = 0){
        int size = que.size();
        while(size-- >0){
            int vtx = que.front();  que.pop();

            int r = vtx/m;
            int y = vtx%m;

            for(int d =0; d<4; d++){
                int x = r + dir[d][0];
                int y = c + dir[d][1];

                if(x>=0 && x<n && y>=0 && y<m && matrix[x][y] > matrix[i][j] && --indegree[x][y] == 0)
                    que.push(x*m + y);
            }
        }
        level++;
    }

    return level;
}

//leetcode-546============================================
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
    if(matrix.size() == 0 || matrix[0].size()==0) return matrix;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        queue<int> que;
        int dir[4][2] = {{0,1},{-1,0},{1,0},{0,-1}};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0)
                    que.push(i*m + j);
            }
        }

    int level = 1;
    while(que.size()!=0){
            int size = que.size();
            while(size-- >0){
                int vtx = que.front(); que.pop();

                int r = vtx/m;
                int c = vtx%m;
                
                for(int d=0; d<4; d++){
                    int x = r + dir[d][0];
                    int y = c + dir[d][1];

                    if(x>=0 && y>=0 && x<n && y<m && matrix[x][y] == 1 && !vis[x][y]){
                        que.push(x*m + y);
                        matrix[x][y] = level;
                        vis[x][y] = true;
                    }
                }
        }
        level++;
    }

    return matrix;     
}

//leetcode -815-bus routes=========================================

int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {

    int n = routes.size();
    int m = routes[0].size();

    vector<int> arr;
    unordered_map<int,vector<int>> map;

    for(int i=0; i<n; i++){
        arr.push_back(i);
        for(int j=0; j<m; j++){
            map.insert(routes[i][j], arr.push_back(i));
        }
    }

    vector<bool> bus(n, false);
    vector<vector<bool>> stops(n, vector<bool>(m, false));

    queue<int> que;
    que.push(S);

    int length = 0;

    while(que.size()!=0){
        int size = que.size();

        while(size-- >0){
            int vtx = que.front(); que.pop();

            if(vtx == T){
                return length;
            }

            stops[vtx] = true;
            bus[map[vtx]] = true;
        }
    }

}

//leetcode-787==================================================
class Edge{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w){
        this->v = v;
        this->w = w;
    }
};

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    
    vector<vector<Edge*>> graph(n, vector<Edge*>());
    for(vector<int> ar: flights){
        addEdge(ar, graph);
    }

    vector<bool> vis(n,false);
    bfs(src, graph, vis);
}

void bfs()

void addEdge(vector<int>& ar, vector<vector<Edge*>> &graph){
    graph[ar[0]].push_back(new Edge(ar[1], ar[2]));
}

//leetcode-684============================================================
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

vector<int> findRedundantConnection(vector<vector<int>>& edges) {

    for(int i=0; i<=edges.size(); i++){  // <=edges.size because humne index 0 se liya hai and question me edges 1 se hai..
        par.push_back(i);
        setSize.push_back(1);
    }

    for(vector<int>& ar : edges){

        int u = ar[0];
        int v = ar[1];

        int p1 = findPar(u);
        int p2 = findPar(v);

        if(p1 != p2){
            mergeSet(p1,p2);
        }
        else{
            return ar;
        }
    }
    return {};
}

//leetcode-547========================================================
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

int findCircleNum(vector<vector<int>>& board) {

    if(board.size() == 0) return 0;

    int n = board.size();
    int m = board[0].size();

    for(int i=0; i<n; i++){

        par.push_back(i);
        setSize.push_back(1);
    }

    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(board[i][j] == 1){

                int p1= findPar(i);
                int p2= findPar(j);

                if(p1 != p2){
                    mergeSet(p1, p2);
                }
                else{
                    if(setSize[p2] == n)
                        return 1;
                    else
                        count++;
                }
            }

        }
    }
}

int main(){

}