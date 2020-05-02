#include<iostream>
#include<vector>

using namespace std;

class Trie {

class Node{
public:
    int wordEnd;
    vector<Node*> childs;

    Node(){
        this->wordEnd = 0;
        this->childs.assign(26, nullptr); 
    }
};

Node* root = nullptr;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string& word) {
        Node* curr = root;
        int n = word.length();
        for(int i=0; i<n; i++){
            int idx = word[i] -'a';
            if(curr->childs[idx] == nullptr) curr->childs[idx] = new Node();

            curr = curr->childs[idx];
        }
        curr->wordEnd++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string& word) {
        Node* curr = root;
        int n = word.length();
        for(int i=0; i<n; i++){
            int idx = word[i] -'a';
            curr = curr->childs[idx];

            if(curr == nullptr) return false;
        }
        return curr->wordEnd > 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string &prefix) {
        Node* curr = root;
        int n = prefix.length();
        for(int i=0; i<n; i++){
            int idx = prefix[i] -'a';
            curr = curr->childs[idx];

            if(curr == nullptr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
