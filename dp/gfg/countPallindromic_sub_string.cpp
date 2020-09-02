//* https://practice.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string/0
#include <iostream>
#include <vector>

using namespace std;

int countAllPallindromeSubstrings(string &str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int count = 0;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (gap == 1 && str[i] == str[j])
            {
                dp[i][j] = 2;
            }
            else if (str[i] == str[j] && dp[i + 1][j - 1] != 0)
            {
                dp[i][j] = gap + 1;
            }

            if(dp[i][j] > 1){
                count += 1;
            }
        }
    }

    return count;
}

void set(){
    int t;
    cin >> t;
    
    while(t-- >0){
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        cout << countAllPallindromeSubstrings(s) << endl;
    }
}

int main() {
	//code
	set();
	return 0;
}