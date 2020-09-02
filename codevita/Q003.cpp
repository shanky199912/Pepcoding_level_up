#include<iostream>
#include<vector>

using namespace std;

bool isPalin(string &s)
{   
    if(s.length() == 1)
        return true;
    if(s.length() == 0)
        return true;
    int i = s.length()-1;
    int j=0;
    while(i > j) {
        if(s[i] != s[j]) {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

vector<string> ans;
bool checkIfSubstringPallindrome(string str, int si, int ei, int count){

	if(str.length() == 0)
		return false;
    if(count == 1){
        if(isPalin(str)){
            ans.push_back(str);
            return true;
        }
        return false;
    }

    string s1 = str.substr(si, ei-si+1);
    string ros = str.substr(si+1);

	bool res = false;
    if(isPalin(s1)){
		ans.push_back(s1);
        res = res ||  checkIfSubstringPallindrome(ros, si+1, ei+1, count-1);
    }

    res = res || checkIfSubstringPallindrome(ros, si, ei+1, count);
	
	if(res)
		return true;
	else{
		ans.pop_back();
		return false;
	}
}

void solve(){
    string str;
    cin >> str;
    int n = str.length();
    if(n < 3)
        cout << "Impossible" << endl;
    
	int counter = 3;
    checkIfSubstringPallindrome(str,0,0,counter);

    if(ans.size() == 0)
        cout << "Impossible" << endl;
    else{
        for(int i=0; i<ans.size(); i++)
            cout << ans[i] << endl;
    }
}

int main(){
    solve();
    return 0;
}