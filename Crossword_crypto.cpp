#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

//wordbreak.========================================================
unordered_set<string> map;

int wordbreak_(string str, string ans){

    if(str.length() == 0){
        cout<<ans<<endl;
        return 1;
    }

    int count = 0;
    for(int i=1;i<=str.length();i++){
        string ros = str.substr(0,i);
        if(map.find(ros)!=map.end()){
            count += wordbreak_(str.substr(i), ans + ros +" ");
        }
    }

    return count;
}
void wordbreak(){

    vector<string> dic{ "i","like","ilike","sam","sung","samsung","and","man","go","mango"};
    for(string str:dic){
        map.insert(str);
    }

    string str = "ilikesamsungandmango";
    cout<<wordbreak_(str,"")<<endl;

}

//cryptoarithmetic.========================================================

string str1 ="send";
string str2 = "more";
string str3 = "money";
vector<int> mapping(26,0);
int numused =0;

int stringToNumber(string &str){
    int res = 0;
    for(int i=0;i<str.length(); i++){
        int idx = str[i] -'a';
        res = res * 10 + mapping[idx];
    }
    return res;
}

int crypto_(string str, int idx){

    if(idx == str.length()){

        int a = stringToNumber(str1);
        int b = stringToNumber(str2);
        int c = stringToNumber(str3);
        //agar pehli digit zero na ho to yeh condtn lgao
        //&& mapping[str1[0]-'a']!=0 && mapping[str2[0]-'a']!=0 && mapping[str3[0]-'a']!=0
        if((a + b == c)){

          return 1;
        }
        return 0;
    }

    int count  = 0;
    for(int num=0; num<=9;num++){

        int mask = (1<<num);
        if((numused & mask)==0){

            numused ^= mask;
            mapping[str[idx]-'a'] = num;

            count += crypto_(str, idx+1);

            numused ^= mask;
            mapping[str[idx]-'a'] = 0;

        }
    }

    return count;
}

void crypto(){

    string str = str1 + str2 + str3;
    int freq = 0;
    for(int i=0;i<str.length();i++){

        int idx = (1<<(str[i]-'a'));
        freq |= idx;
    }

    str = "";
    for(int i=0;i<26; i++){
        int mask = (1<<i);
        if((freq & mask)!=0){
            str += (char)(i+'a');
        }
    }

    cout << str<<endl;
    cout<<crypto_(str,0)<<endl;
}

//crossword.========================================================
vector<vector<char>> board{{'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                           {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                           {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
                           {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                           {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
                           {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
                           {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
                           {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                           {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
                           {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

vector<string> words = {"agra", "norway", "england", "gwalior"};

bool canPlaceWordH(int r, int c , string &word){

    for(int i=0; i<word.length(); i++){

        if((c+i)< board.size() && board[r][c+i] !='-' && board[r][c+i] != word[i]){
            return false;
        }
    }
    return true;
}

vector<bool> placeWordH(int r, int c , string &word){

    vector<bool> mark(word.length(), false);
    for(int i=0; i< word.length(); i++){

        if(board[r][c+i] == '-'){
            mark[i] = true;
            board[r][c+i] = word[i];
        }
    }
    return mark;
}

void unplaceWordH(int r, int c , string &word, vector<bool> &mark){

    for(int i=0; i< word.length(); i++){
        if(mark[i]){
            board[r][c+i] = '-';
        }
    }
}


bool canPlaceWordV(int r, int c , string &word){

    for(int i=0; i<word.length(); i++){

        if((r+i)< board.size() && board[r+i][c] !='-' && board[r+i][c] != word[i]){
            return false;
        }
    }
    return true;
}

vector<bool> placeWordV(int r, int c , string &word){
   
    vector<bool> mark(word.length(), false);
    for(int i=0; i< word.length(); i++){

        if(board[r+i][c] == '-'){
            mark[i] = true;
            board[r+i][c] = word[i];
        }
    }
    return mark;
}

void unplaceWordV(int r, int c , string &word, vector<bool> &mark){

    for(int i=0; i< word.length(); i++){
        if(mark[i]){
            board[r+i][c] = '-';
        }
    }
}

bool crossword_(int idx){

    if(idx == words.size()){
        //print the crossword
        for(vector<char> &ar: board){
            for(char ch: ar){
                cout<<ch<<" ";
            }
            cout<<endl;
        }

        return true;
    }

    bool ans = false;
    string word = words[idx];
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){

            if(board[i][j] == '-' || board[i][j] == word[0]){

                if(canPlaceWordH(i,j,word)){
                    //place the word horizontally
                    vector<bool> mark = placeWordH(i,j,word);
                    ans = ans || crossword_(idx+1);
                    unplaceWordH(i,j,word,mark);
                }

                if(canPlaceWordV(i,j,word)){
                    //place the word vertically
                    vector<bool> mark = placeWordV(i,j,word);
                    ans = ans || crossword_(idx+1);
                    unplaceWordV(i,j,word,mark);
                }

            }
        }
    }
    return ans;
}

void crossword(){
    cout<<crossword_(0)<<endl;
}

int main(){
    //wordbreak();
    //crypto();
    crossword();
    return 0;
}