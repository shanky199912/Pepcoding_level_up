#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
        int data;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int data){
            this->data = data;
        }

        Node(){

        }
};

int idx = 0;
Node* construct(vector<int>& arr){

    if(idx >= arr.size() || arr[idx] == -1){
        idx++;
        return nullptr;
    }

    Node *node = new Node(arr[idx]);
    idx++;
    node->left = construct(arr);
    node->right = construct(arr);

    return node;
}

void display(Node *node){
    if(node == nullptr) return;

    string str = "";
    str += ((node->left != nullptr) ? to_string(node->left->data): ".");
    str += " <- " + to_string(node->data) + " -> ";
    str += ((node->right != nullptr) ? to_string(node->right->data): ".");
    cout<<str<<endl;

    display(node->left);
    display(node->right);
}

//basics
int size(Node *node){
    if(node == nullptr) return 0;
    return size(node->left) + size(node->right) + 1;
}

int height(Node *node){
    if(node == nullptr) return -1; //in terms of edges.
    return max(height(node->left), height(node->right)) + 1;
}



void solve(){
    vector<int> arr = {10,20,40,-1,-1,50,80,-1,-1,90,-1,-1,30,60,100,-1,-1,-1,70,110,-1,-1,120,-1,-1};
    Node *root = construct(arr);
}

int main(){
    return 0; 
}