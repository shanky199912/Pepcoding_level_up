#include<iostream>
#include<vector>

using namespace std;
class Solution {

class Node{
public:
    bool wordEnd;
    vector<Node *> childs;
    string res ="";

    Node(){
        this->wordEnd = false;
        this->childs.assign(26, nullptr);
        this->res = ""; 
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
            int idx = word[i] - 'a';
            if(curr->childs[idx] == nullptr) curr->childs[idx] = new Node();

            curr = curr->childs[idx];
        }
        curr->wordEnd = true;
        curr->res = word;

    }

    vector<string> ans;
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    int n;
    int m;

    void findWords_dfs(Node* node, vector<vector<char>>& board, int r, int c) {
        
        if(node->wordEnd){
            node->wordEnd = false;
            ans.push_back(node->res);
        } //no need to return from here.
        char ch = board[r][c];
        board[r][c] = '#';
        for(int d=0; d<4; d++){
            int x = r + dir[d][0];
            int y = c + dir[d][1];

            if(x>=0 && x<n && y>=0 && y<m && board[x][y] != '#' && node->childs[board[x][y]-'a'] != nullptr)
                findWords_dfs(node->childs[board[x][y]-'a'], board, x, y);
        }
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        if(board.size() == 0 || board[0].size() == 0) return {};

        n = board.size();
        m = board[0].size();

        for(string& word: words){
            insert(word);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(root->childs[board[i][j]-'a'] != nullptr)
                    findWords_dfs(root->childs[board[i][j]-'a'], board, i, j);
            }
        }

        return ans;
    }
};