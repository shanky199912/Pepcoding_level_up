#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
        Node* left = nullptr;
        Node* right = nullptr;
        int data = 0;

        int height = 0;
        int bal = 0;

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

void calBalFacAndHeight(Node* node){ //O(1)

    int lh = -1;
    int rh = -1;

    if(node->left != nullptr) lh = node->left->height;
    if(node->right != nullptr) rh = node->right->height;

    int height = max(lh , rh) + 1;
    node->height = height;
    int bal = (lh - rh);
    node->bal = bal;
}
//LL
Node* LL(Node* A){  //O(1)

    Node *B = A->left;
    Node *Bkaright = B->right;

    B->right = A;
    A->left = Bkaright;

    calBalFacAndHeight(A);
    calBalFacAndHeight(B);

    return B;
}

//RR
Node* RR(Node* A){  //O(1)

    Node *B = A->right;
    Node *Bkaleft = B->left;

    B->left = A;
    A->right = Bkaleft;

    calBalFacAndHeight(A);
    calBalFacAndHeight(B);

    return B;
}


void solve(){
    vector<int> arr = {10,20,30,40,50,60,70,80,90,100,110,120,130};
    Node* root = constructBst(arr, 0, arr.size()-1);
    display(root);
    cout<<endl;
}

int main(){
    solve();
    return 0;
}