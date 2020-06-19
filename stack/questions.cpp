#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//Leetcode -20 - valid parenthesis
bool isValid(string s) {
    stack<char> st;

    for(int i=0; i<s.length(); i++){

        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }

        while(st.size() != 0){
            char tp = st.top();
            if(tp == '(' && s[i] == ')'){
                st.pop();
                continue;
            }
            else if(tp == '{' && s[i] == '}'){
                st.pop();
                continue;
            }
            else if(tp == '[' && s[i] == ']'){
                st.pop();
                continue;
            }
            else{
                return false;
            }
        }
    }

    return true;
}

int main(){

}