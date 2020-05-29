#include<iostream>
#include<vector>

using namespace std;

class WordDictionary {

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
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *curr = root;
        for(int i=0; i<word.length(); i++){
            int idx = word[i] - 'a';
            if(curr->childs[idx] == nullptr) curr->childs[idx] = new Node();

            curr = curr->childs[idx];
        }
        curr->wordEnd++;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_(root, 0, word);
    }

    bool search_(Node* node, int si, string& word){

        if(si == word.length())
            return node.wordEnd !=0;
            
        bool res = false;
        if(word[si] == '.'){
            for(int i=0; i<26; i++){
                if(node->childs[i] != nullptr){
                    res = res || search_(node->childs[i], si+1, word);
                }
            }
        }
        else{
            int idx = word[si] - 'a';
            if(node.childs[idx] != nullptr)
                res = res || search_(node.childs[idx], si+1, word);
        }
        return res;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */