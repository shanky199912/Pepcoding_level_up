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

int maximum(Node *root){
    if(root == nullptr) return (int)-1e8;
    return max(root->data, max( maximum(root->left) , maximum(root->right)));
}

int minimum(Node *root){
    if(root == nullptr) return (int)1e8;
    return min(root->data, min( minimum(root->left) , minimum(root->right)));
}

bool find(Node *root, int data){
    if(root == nullptr) return false;
    if(root->data == data) return true;

    bool res = false;
    res = res || find(root->left, data);
    res = res || find(root->right, data);

    return res;
}

bool find_02(Node *root, int data){
    if(root == nullptr) return false;
    if(root->data == data) return true;
    return find_02(root->left, data) || find_02(root->right, data);
}

//traversals

void preorder(Node* root){ //N,L,R;
    if(root == nullptr) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);    
}

void inorder(Node* root){ //L,N,R;
    if(root == nullptr) return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);    
}

void postorder(Node* root){ //L,R,N;
    if(root == nullptr) return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";    
}

bool rootToNode_(Node *root, int data, vector<Node*> &list){
    if(root == nullptr) return false;

    if(root->data == data){
        list.push_back(root);
        return true;
    }

    bool res = rootToNode_(root->left, data, list) || rootToNode_(root->right, data, list);
    if(res) list.push_back(root);

    return res;
}

void rootToNode(Node* root, int data){
    vector<Node *> path;
    bool res = rootToNode_(root, data, path);
    for(Node *n : path){
        cout<< n->data <<" ";
    }
}

void set1(Node* root){
    rootToNode(root, 80);
}

void solve(){
    vector<int> arr = {10,20,40,-1,-1,50,80,-1,-1,90,-1,-1,30,60,100,-1,-1,-1,70,110,-1,-1,120,-1,-1};
    Node *root = construct(arr);
    // display(root);
    set1(root);
}

int main(){
    solve();
    return 0; 
}