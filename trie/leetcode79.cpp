#include<iostream>
#include<vector>

using namespace std;
class Solution {
    
class Node{
public:
    bool wordEnd;
    vector<Node *> childs;

    Node(){
        this->wordEnd = false;
        this->childs.assign(256, nullptr);
    }
};

Node* root = nullptr;
public:
    Solution() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *curr = root;
        for(int i=0; i<word.length(); i++){
            int idx = word[i] - 'A';
            if(curr->childs[idx] == nullptr) curr->childs[idx] = new Node();

            curr = curr->childs[idx];
        }
        curr->wordEnd = true;
    }

    int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    int n;
    int m;
    
    bool dfs(Node *node, vector<vector<char>>& board, int r, int c){
        
        if(node->wordEnd){
            return node->wordEnd;
        }
        char ch = board[r][c];
        bool ans = false;
        board[r][c] = '#';
        for(int d=0; d<4; d++){
            int x = r + dir[d][0];
            int y = c + dir[d][1];
            
            if(x>=0 && y>=0 && x<n && y<m && board[x][y] != '#'
               && node->childs[board[x][y]-'A'] != nullptr){
                ans = dfs(node->childs[board[x][y]-'A'], board, x, y);
                if(ans) return true;
            } 
        }
        board[r][c] = ch;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        if(board.size() == 0 || board[0].size() == 0) return false;
        
        Node *root = new Node();
        
        n = board.size();
        m = board[0].size();
       
        insert(word);
       
        bool res  = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(root->childs[board[i][j]-'A'] != nullptr){
                    res = dfs(root->childs[board[i][j]-'A'], board, i, j);
                    if(res) return true;
                }
            }
        }
        return res;    
    }
};