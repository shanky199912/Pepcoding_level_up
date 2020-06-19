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
vector<int> nextGreater(vector<int> arr)
{
    stack<int> st;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
    }
}

void set1()
{
}

int main()
{
    // solve();
    set1();
    return 0;
}