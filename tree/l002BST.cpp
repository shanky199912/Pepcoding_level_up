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
    Node *curr = node;
    Node *pred = nullptr;
    Node *succ = nullptr;
    while (curr != nullptr)
    {
        if (curr->data == data)
        {
            if (curr->left == nullptr)
                cout << "Pred: " << (pred != nullptr ? pred->data : -1) << endl;
            else
            {
                pred = curr->left;
                while (pred->right != nullptr)
                    pred = pred->right;
                cout << "Pred: " << pred->data << endl;
            }

            if (curr->right == nullptr)
                cout << "Succ: " << (succ != nullptr ? succ->data : -1) << endl;
            else
            {
                succ = curr->right;
                while (succ->left != nullptr)
                    succ = succ->left;
                cout << "Succ: " << succ->data << endl;
            }

            break;
        }
        else if (data < curr->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else
        {
            pred = curr;
            curr = curr->right;
        }
    }
}

int idx = 0;
Node* constructBstFromPreOrderTraversal_(vector<int>& arr, int lb, int ele, int rb){
    if(ele > rb || ele < lb || idx == arr.size()) return nullptr;

    Node* node = new Node(arr[idx]);
    idx++;

    if(idx < arr.size()) node->left = constructBstFromPreOrderTraversal_(arr, lb, arr[idx], ele);
    if(idx < arr.size()) node->right = constructBstFromPreOrderTraversal_(arr, ele, arr[idx], rb);

    return node;
}

int heightOfBstFromPreOrder(vector<int>& arr, int lb, int rb){
    if(arr[idx] > rb || arr[idx] < lb || idx == arr.size()) return -1;

    Node* node = new Node(arr[idx]);
    idx++;

    int lh = heightOfBstFromPreOrder(arr, lb, arr[idx]);
    int rh = heightOfBstFromPreOrder(arr,arr[idx], rb);

    return max(lh, rh) + 1;
}

Node* constructBstFromPreOrderTraversal(){

    vector<int> preorder = {50,17,9,14,12,23,19,76,54,72,67};
    Node* root = constructBstFromPreOrderTraversal_(preorder,(int)-1e8, preorder[0], (int)1e8);
    int height = heightOfBstFromPreOrder(preorder, (int)-1e8, (int)1e8);
    cout<<height<<endl;
    return root;
}

Node* addData(Node* root, int data){
    if(root == nullptr) return new Node(data);

    if(data > root->data){
        root->right = addData(root->right, data);
    }
    else{
        root->left = addData(root->left, data);
    } 
    return root;
}

Node* addDataItr(Node* root, int data){
    if(root == nullptr) return new Node(data);

    Node *curr = root;
    Node* prev = nullptr;
    while(curr != nullptr){
        prev = curr;
        if(curr->data < data){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    if(prev->data > data) {
        prev->left = new Node(data);
    }
    else{
        prev->right = new Node(data);
    }
    return root;
}

Node* remove(Node* root, int data){ //O(log(n))
    if(root == nullptr) return nullptr;

    if(data > root->data){
        root->right = remove(root->right, data);
    }
    else if(data < root->data){
        root->left = remove(root->left, data);
    }
    else{
        //data mil gya mujhe
        if(root->left == nullptr || root->right == nullptr){ //only one node, node has only left, node has only right.
            return (root->left !=nullptr? root->left : root->right);
        }

        //node has both left and right -> replace node->data with max of lst or min of rst.
        int maxEle = maximum(root->left);
        root->data = maxEle;
        root->left = remove(root->left, maxEle);
    }
    return root;
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
    cout<<endl;
    // set1(root);
    // Node* ans = lca(root, 30,50);
    // cout<<ans->data;
    // inorderSuccessor_Predecessor(root, 10);
    Node* node = constructBstFromPreOrderTraversal();
    display(node);
}
int main(){
    solve();
    return 0;
}