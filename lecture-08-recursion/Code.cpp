#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

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

int main(){
    //wordbreak();
    crypto();
    return 0;
}