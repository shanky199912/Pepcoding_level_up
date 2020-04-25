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

//leetcode -1091
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

int main(){

}