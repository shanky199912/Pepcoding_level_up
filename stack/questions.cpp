#include <iostream>
#include <vector>
#include <stack>
#include<algorithm>

using namespace std;

//Leetcode -20 - valid parenthesis ==========================================
bool isValid(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '[' || ch == '{')
            st.push(ch);
        else
        {
            if (st.size() == 0)
                return false;
            else if (st.top() == '(' && ch != ')')
                return false;
            else if (st.top() == '[' && ch != ']')
                return false;
            else if (st.top() == '{' && ch != '}')
                return false;
            else
                st.pop();
        }
    }

    return st.size() == 0;
}

//Leetcode - 1021 - remove Outermost parenthesis======================
string removeOuterParentheses(string str)
{
    string ans = "";
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' && count++ > 0)
            ans += ch;
        if (ch == ')' && count-- > 1)
            ans += ch;
    }

    return ans;
}

int minAddToMakeValid(string str)
{

    int closingBracketReq = 0;
    int openingBracketReq = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            closingBracketReq++;
        }
        else if (closingBracketReq > 0)
        {
            closingBracketReq--;
        }
        else
        {
            openingBracketReq++;
        }
    }

    return openingBracketReq + closingBracketReq;
}

int minAddToMakeValid_02(string str)
{
    int n = str.length();
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        if (st.top() != -1 && str[i] == ')' && str[st.top()] == '(')
            st.pop();
        else
            st.push(i);
    }

    return st.size() - 1;
}

string minRemoveToMakeValid(string str)
{
    int n = str.length();
    stack<int> st;
    st.push(-1);
    vector<bool> marked(n, false);

    for (int i = 0; i < n; i++)
    {
        if (st.top() != -1 && str[i] == ')' && str[st.top()] == '(')
        { //resolve the brackets.
            int val = st.top();
            st.pop();
            marked[i] = marked[val] = true;
        }
        else if (str[i] == '(')
        { // it can be resolved in future
            st.push(i);
        }
        else
        {
            if (str[i] != ')')
                marked[i] = true; //alphabet
            // do nothing if we encounter ')' here.
        }
    }

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (marked[i])
            ans += str[i];
    }
    return ans;
}

string minRemoveToMakeValid_02(string str)
{
    int n = str.length();
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        if (st.top() != -1 && str[i] == ')' && str[st.top()] == '(')
        { //resolve the brackets.
            st.pop();
        }
        else if (str[i] == '(')
        { // it can be resolved in future
            st.push(i);
        }
        else
        {
            if (str[i] == ')')
                str[i] = '*';
        }
    }

    while (st.top() != -1)
    {
        int val = st.top();
        st.pop();
        str[val] = '*';
    }

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (str[i] != '*')
            ans += str[i];
    }
    return ans;
}

string reverseParentheses(string str)
{
    int n = str.length();
    stack<char> st;
    string temp = "";

    for(int i=0; i<n; i++){
        if(str[i] != ')'){
            st.push(str[i]);
        }
        else{

            while(st.top() != '('){
                temp += st.top();
                st.pop();
            }
            st.pop();

            for(char ch : temp){
                st.push(ch);
            }
            temp = "";
        }
    }

    while(st.size() != 0){
        temp += st.top();
        st.pop();
    }

    reverse(temp.begin(), temp.end());
    return temp;
}

void solve()
{
}

int main()
{
    solve();
    return 0;
}