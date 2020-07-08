#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MyStack
{

    int N = 10000;
    int *arr;
    int sz = 0;
    int tos = -1;

public:
    MyStack()
    {
        this->arr = new int[N];
    }

    MyStack(int size)
    {
        this->arr = new int[size];
        this->N = size;
    }

    int size()
    {
        return this->sz;
    }

    bool isEmpty()
    {
        return this->sz == 0;
    }

    int top()
    {
        if (this->sz == 0)
        {
            return -1;
        }
        return this->arr[tos];
    }

    void push(int val)
    {
        if (this->sz == N)
        {
            cout << "Stack is full";
            return;
        }

        this->tos++;
        this->arr[tos] = val;
        this->sz++;
    }

    void pop()
    {
        if (this->sz == 0)
        {
            cout << "Stack is empty";
            return;
        }

        int rv = this->arr[tos];
        this->arr[tos] = -1;
        this->tos--;
        this->sz--;
    }

    ~MyStack()
    { //destructor
        delete this->arr;
    }
};

void solve()
{
    MyStack *st = new MyStack();
    for (int i = 1; i <= 10; i++)
    {
        st->push(i * 5);
    }

    while (!st->isEmpty())
    {
        cout << st->top() << " ";
        st->pop();
    }
}

// Class Questions ->
vector<int> nextGreaterFromLeftToRight(vector<int>& arr) //O(n) approach
{
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n, n);
    for (int i = 0; i < n; i++)
    {
        while(st.size() != 0 && arr[st.top()] < arr[i]){
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

vector<int> nextGreaterFromRightToLeft(vector<int>& arr) //O(n) approach
{
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = n-1; i >= 0; i--)
    {
        while(st.size() != 0 && arr[st.top()] < arr[i]){
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

vector<int> nextSmallerFromLeftToRight(vector<int>& arr) //O(n) approach
{
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n, n);
    for (int i = 0; i < n; i++)
    {
        while(st.size() != 0 && arr[st.top()] > arr[i]){
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

vector<int> nextSmallerFromRightToLeft(vector<int>& arr) //O(n) approach
{
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n, -1);
    for (int i = n-1; i >= 0; i--)
    {
        while(st.size() != 0 && arr[st.top()] > arr[i]){
            ans[st.top()] = i;
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

void set1()
{
    vector<int> arr = {2,-1,8,6,9,4,3,5};
    vector<int> ans = nextSmallerFromRightToLeft(arr);
    for(int ele: ans) cout << ele << " ";
    cout << endl;
}

int main()
{
    // solve();
    set1();
    return 0;
}