#include <iostream>
#include <vector>
#include<climits>
using namespace std;

bool isValid( vector<vector<int>> &board, int sr, int sc){
    if(sr<0 || sc<0 || sc>=board[0].size() || sr>=board.size() || board[sr][sc] ==2 || board[sr][sc] == 0){
        return false;
    }
    return true;
}

vector<vector<int>> dir = { {-1,0},{1,0},{0,1},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
vector<string> dirN = {"U","D","R","L","N","S","E","W"};
//vector<vector<int>> dir = { {-1,0},{1,0},{0,1},{0,-1}};

int flood_fill_01(int sr, int sc, int er, int ec, vector<vector<int>> &board, string asf , int max, string lp, string sp){
    //base case
    if(sr == er && sc == ec){
        cout<<asf<<endl;
        int m = asf.length();
        if(m > max){
            max = m;
            lp = asf;
        }
        return 1;
    }
    
    board[sr][sc] = 2;
    int count = 0;

    for(int d=0;d<dir.size();d++){

        int r = sr +  dir[d][0];
        int c = sc +  dir[d][1];

        if(isValid(board,r,c)){
            count += flood_fill_01(r, c, er, ec, board, asf + dirN[d], max, lp, sp);
        }
    }

    board[sr][sc] = 1;
    return count;

}

int flood_fill_02(int sr, int sc, int er, int ec, int rad, vector<vector<int>> &board, string asf){
    //base case
    if(sr == er && sc == ec){
        cout<<asf<<endl;
        return 1;
    }
    
    board[sr][sc] = 2;
    int count = 0;

    for(int d=0;d<dir.size();d++){
        for(int mag = 1; mag<=rad; mag++){

            int r = sr + mag * dir[d][0];
            int c = sc + mag * dir[d][1];

            if(isValid(board,r,c)){
                count += flood_fill_02(r, c, er, ec, rad, board, asf + dirN[d] + to_string(mag));
            }
        }
    }

    board[sr][sc] = 1;
    return count;

}

int flood_fill_04(int sr, int sc, int count, vector<vector<int>> &board){

    board[sr][sc] = 0;
    for(int d=0;d<dir.size();d++){

        int r = sr + dir[d][0];
        int c = sc + dir[d][1];

        if(isValid(board, r, c)){
             flood_fill_04(r, c, count+1, board);
        }
    }

    return count;
}

int rotten_oranges(vector<vector<int>> &board){

    int count = 0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j] == 2){
                flood_fill_04(i, j, 0, board);
            }
        }
    }

     for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j] == 1){
                count++;
            }
        }
    }
    return count;
}

int rat_in_maze(int sr, int sc, int er, int ec, int rad, vector<vector<int>> &board, string asf){
    
}

void floodfillSet(){
    
    int sc = 0, sr = 0, ec = 2 , er = 2 ;
    vector<vector<int>> board(er+1, vector<int>(ec+1,1));
    //int rad = board[0].size()-1;
    //cout << flood_fill_02(sr, sc, er, ec, rad, board, "") << endl;

    //vector<vector<int>> board = {{2,1,1},{0,1,1},{1,0,1}};
   // cout<< rotten_oranges(board);
   int max = INT_MIN;
   string sp;
   string lp;
   cout<<flood_fill_01(sr, sc, er, ec, board, "", max, lp , sp)<<endl;
   cout<<max<<endl;
   cout<<lp<<endl;
}

void solve(){
    floodfillSet();
}

int main(){
    solve();
    return 0;
}