#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
        Node* left = nullptr;
        Node* right = nullptr;
        int data = 0;

        Node(int data){
            this->data = data;
        }

        Node(){

        }
};

Node* constructBst(vector<int>& arr, int si, int ei){
    if(si > ei) return nullptr;

    int mid = (si + ei) >> 1; // (si + ei)/2 = mid;
    Node* node = new Node(arr[mid]);
    node->left = constructBst(arr, si, mid-1);
    node->right = constructBst(arr, mid+1, ei);
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

bool height(Node* node){
    if(node == nullptr) return -1;
    return max(height(node->left), height(node->right)) + 1;
}

int size(Node *node){
    if(node == nullptr) return 0;
    return size(node->left) + size(node->right) + 1;
}

bool find(Node* node, int data){
    Node* curr = node;
    while(curr != nullptr){
        if(curr->data == data) return true;
        else if(curr->data < data) curr = curr->right;
        else
        {
            curr = curr -> left;
        } 
    }
    return false;
}

int maximum(Node* root){
    Node* curr = root;
    while(curr->right != nullptr){
        curr = curr->right;
    }
    return curr->data;
}

int minimum(Node* root){
    Node* curr = root;
    while(curr->left != nullptr){
        curr = curr->left;
    }
    return curr->data;
}

Node* lca(Node* root, int p, int q){
    Node* curr = root;
    while(curr != nullptr){
        if((curr->data <= p && curr->data >= q) || (curr->data <=q && curr->data >= p)){
            return curr;
        }
        else if(curr->data < p && curr->data < q){
                curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return nullptr;
}

void nodesinrange(Node* node, int a, int b, vector<int>& arr){
    if(node == nullptr) return;

    nodesinrange(node->left, a, b, arr);
    if(node->data >= a && node->data <= b){
        arr.push_back(node->data);
    }
    nodesinrange(node->right, a,b, arr);
}

Node* predess = nullptr;
Node* success = nullptr;
void inorderSuccessor_Predecessor(Node* node, int data){
    if(node == nullptr){
        return;
    }

        inorderSuccessor_Predecessor(node->left, data);
        if(predess != nullptr && predess->data == data){
            success = node;
            cout<<success->data;
        }
        if(node->data == data){
            cout<<predess->data;
            predess = node;
        }else{
            predess = node;
        }

        inorderSuccessor_Predecessor(node->right, data);
}

void set1(Node* node){
    vector<int> ans;
    nodesinrange(node, 20, 50, ans);
    for(int e: ans){
        cout<<e<<" ";
    }
}
void solve(){
    vector<int> arr = {10,20,30,40,50,60,70,80,90,100,110,120,130};
    Node* root = constructBst(arr, 0, arr.size()-1);
    display(root);
    // set1(root);
    // Node* ans = lca(root, 30,50);
    // cout<<ans->data;
    inorderSuccessor_Predecessor(root, 10);
}
int main(){
    solve();
    return 0;
}