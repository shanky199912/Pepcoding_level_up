#include <iostream>
#include <vector>
#include <list>

using namespace std;

void display(vector<int> &arr)
{
    for (int ele : arr)
        cout << ele << " ";
    cout << endl;
}

void display2D(vector<vector<int>> &arr)
{
    for (vector<int> ar : arr)
        display(ar);
    cout << endl;
}

void display_bool(vector<bool> &arr)
{
    for (bool ele : arr)
        cout << ele << " ";
    cout << endl;
}

void display2D_bool(vector<vector<bool>> &arr)
{
    for (vector<bool> ar : arr)
        display_bool(ar);
    cout << endl;
}

vector<vector<bool>> isPlaindromeSubstring(string &str)
{
    int n = str.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int gap = 0; gap < n; gap++)
    {

        for (int i = 0, j = gap; j < n; i++, j++)
        {

            if (gap == 0)
            {
                dp[i][j] = true;
            }
            else if (gap == 1 && str[i] == str[j])
            {
                dp[i][j] = true;
            }
            else if (str[i] == str[j])
            {
                dp[i][j] = dp[i + 1][j - 1];
            }
        }
    }
    return dp;
}

void longestPallindromicSubstring(string &str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int maxLen = 0;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {

            if (gap == 0)
            {
                dp[i][j] = gap + 1;
            }
            else if (gap == 1 && str[i] == str[j])
            {
                dp[i][j] = gap + 1;
            }
            else if (str[i] == str[j] && dp[i + 1][j - 1] != 0)
            {
                dp[i][j] = gap + 1;
            }

            if (dp[i][j] > maxLen)
            {
                maxLen = dp[i][j];
            }
        }
    }

    cout << maxLen << endl;
    display2D(dp);
}

string longestPallindromicSubstring_ans(string &str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int maxLen = 0;
    int si = 0, ei = 0;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {

            if (gap == 0)
            {
                dp[i][j] = gap + 1;
            }
            else if (gap == 1 && str[i] == str[j])
            {
                dp[i][j] = gap + 1;
            }
            else if (str[i] == str[j] && dp[i + 1][j - 1] != 0)
            {
                dp[i][j] = gap + 1;
            }

            if (dp[i][j] > maxLen)
            {
                maxLen = dp[i][j];
                si = i;
                ei = j;
            }
        }
    }

    return str.substr(si, (ei - si + 1));
}

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
                dp[i][j] = gap + 1;
            }
            else if (gap == 1 && str[i] == str[j])
            {
                dp[i][j] = gap + 1;
            }
            else if (str[i] == str[j] && dp[i + 1][j - 1] != 0)
            {
                dp[i][j] = gap + 1;
            }

            count += dp[i][j] == 0 ? 0 : 1;
        }
    }

    return count;
}

void set()
{
    string str = "aaaabbaa";
    // vector<vector<bool>> isPlalindrome = isPlaindromeSubstring(str);
    // display2D_bool(isPlalindrome);
    longestPallindromicSubstring(str);
    cout << longestPallindromicSubstring_ans(str) << endl;
    // cout << countAllPallindromeSubstrings(str) << endl;
}

void solve()
{
    set();
}

int main()
{
    solve();
    return 0;
}