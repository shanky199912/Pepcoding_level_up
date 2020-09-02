#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <cstring>

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

int fibo(int n, vector<int> &dp)
{
    if (n <= 1) //base case.
        return dp[n] = n;

    if (dp[n] != 0)
        return dp[n];

    int ans = fibo(n - 1, dp) + fibo(n - 2, dp);

    return dp[n] = ans;
}

int fiboDP(int N, vector<int> &dp)
{

    for (int n = 0; n <= N; n++)
    {
        if (n <= 1) //base case.
        {
            dp[n] = n;
            continue;
        }

        int ans = dp[n - 1] + dp[n - 2]; // fibo(n - 1, dp) + fibo(n - 2, dp);

        dp[n] = ans;
    }
    return dp[N];
}

int fibo_btr(int n)
{
    int a = 0;
    int b = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }

    return a;
}

//! MazePathSeries.==================================================================

int mazePathHV(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
    {
        return dp[sr][sc] = 1;
    }

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    int count = 0;
    if (sr + 1 <= er)
        count += mazePathHV(sr + 1, sc, er, ec, dp);

    if (sc + 1 <= ec)
        count += mazePathHV(sr, sc + 1, er, ec, dp);

    if (sr + 1 <= er && sc + 1 <= ec)
        count += mazePathHV(sr + 1, sc + 1, er, ec, dp);

    return dp[sr][sc] = count;
}

int mazePathHV_DP(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{

    for (sr = er; sr >= 0; sr--)
    {
        for (sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;
            if (sr + 1 <= er)
                count += dp[sr + 1][sc]; //mazePathHV(sr + 1, sc, er, ec, dp);

            if (sc + 1 <= ec)
                count += dp[sr][sc + 1]; //mazePathHV(sr, sc + 1, er, ec, dp);

            if (sr + 1 <= er && sc + 1 <= ec)
                count += dp[sr + 1][sc + 1]; //mazePathHV(sr + 1, sc + 1, er, ec, dp);

            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}

int mazePathMulti(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
    {
        return dp[sr][sc] = 1;
    }

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    int count = 0;
    for (int jump = 1; sr + jump <= er; jump++)
        count += mazePathMulti(sr + jump, sc, er, ec, dp);

    for (int jump = 1; sc + jump <= ec; jump++)
        count += mazePathMulti(sr, sc + jump, er, ec, dp);

    for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
        count += mazePathMulti(sr + jump, sc + jump, er, ec, dp);

    return dp[sr][sc] = count;
}

int mazePathMulti_DP(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{

    for (sr = er; sr >= 0; sr--)
    {
        for (sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;
            for (int jump = 1; sr + jump <= er; jump++)
                count += dp[sr + jump][sc]; //mazePathMulti(sr + jump, sc, er, ec, dp);

            for (int jump = 1; sc + jump <= ec; jump++)
                count += dp[sr][sc + jump]; //mazePathMulti(sr, sc + jump, er, ec, dp);

            for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
                count += dp[sr + jump][sc + jump]; //mazePathMulti(sr + jump, sc + jump, er, ec, dp);

            dp[sr][sc] = count;
        }
    }

    return dp[0][0];
}

int boardPath(int sp, int ep, vector<int> &dp)
{
    if (sp == ep)
    {
        return dp[sp] = 1;
    }

    if (dp[sp] != 0)
        return dp[sp];

    int count = 0;
    for (int dice = 1; sp + dice <= ep && dice <= 6; dice++)
        count += boardPath(sp + dice, ep, dp);

    return dp[sp] = count;
}

int boardPathDP(int sp, int ep, vector<int> &dp)
{

    for (sp = ep; sp >= 0; sp--)
    {
        if (sp == ep)
        {
            dp[sp] = 1;
            continue;
        }

        int count = 0;
        for (int dice = 1; sp + dice <= ep && dice <= 6; dice++)
            count += dp[sp + dice]; //boardPath(sp + dice, ep, dp);
        dp[sp] = count;
    }

    return dp[0];
}

int boardPath_best(int sp, int ep)
{
    list<int> ll;
    for (sp = ep; sp >= 0; sp--)
    {
        if (sp > ep - 2)
        {
            ll.push_front(1);
            continue;
        }

        if (ll.size() <= 6)
            ll.push_front(2 * ll.front());
        else
        {
            ll.push_front(2 * ll.front() - ll.back());
            ll.pop_back();
        }
    }

    return ll.front();
}

int boardPathWithDiceArrayDP(int sp, int ep, vector<int> &dp, vector<int> &diceArray)
{

    for (sp = ep; sp >= 0; sp--)
    {
        if (sp == ep)
        {
            dp[sp] = 1;
            continue;
        }

        int count = 0;
        for (int dice = 0; sp + diceArray[dice] <= ep && dice < diceArray.size(); dice++)
            count += dp[sp + diceArray[dice]]; //boardPath(sp + dice, ep, dp);
        dp[sp] = count;
    }

    return dp[0];
}

//* Leetcode 70.=================================================================================

int climbStairs_01(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return dp[n] = 1;
    }

    if (dp[n] != 0)
        return dp[n];

    int ans = climbStairs_01(n - 1, dp) + climbStairs_01(n - 2, dp);
    return dp[n] = ans;
}

int climbStairs_DP(int n, vector<int> &dp)
{
    int N = n;
    for (n = 0; n <= N; n++)
    {

        if (n <= 1)
        {
            dp[n] = 1;
            continue;
        }

        int ans = dp[n - 1] + dp[n - 2]; //climbStairs_01(n - 1, dp) + climbStairs_01(n - 2, dp);
        dp[n] = ans;
    }
    return dp[N];
}

int climbStairs_btr(int n)
{
    int a = 1;
    int b = 1;
    int sum = 1;
    for (int i = 2; i <= n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, 0);
    // return climbStairs_01(n, dp);
    // return climbStairs_DP(n,dp);
    return climbStairs_btr(n);
}

//* Leetcode -746 ============================================================

int minCostClimbingStairs(int n, vector<int> &dp, vector<int> &cost)
{
    if (n <= 1)
    {
        return dp[n] = cost[n];
    }

    if (dp[n] != 0)
        return dp[n];

    int ans = min(minCostClimbingStairs(n - 1, dp, cost),
                  minCostClimbingStairs(n - 2, dp, cost));
    return dp[n] = ans + cost[n];
}

int minCostClimbingStairsDP(int n, vector<int> &dp, vector<int> &cost)
{
    int N = n;
    for (int n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = cost[n];
            continue;
        }

        int ans = min(dp[n - 1], dp[n - 2]);
        dp[n] = ans + cost[n];
    }
    return dp[N];
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();

    cost.push_back(0);
    vector<int> dp(n + 1, 0);

    // return minCostClimbingStairs(n, dp, cost);
    return minCostClimbingStairsDP(n, dp, cost);
}

//* https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0
int friends_pairing_problem(int n, vector<int> &dp)
{

    if (n <= 1)
        return dp[n] = 1;

    if (dp[n] != 0)
        return dp[n];

    int single = friends_pairing_problem(n - 1, dp);
    int pairUp = friends_pairing_problem(n - 2, dp) * (n - 1);

    return dp[n] = single + pairUp;
}

int friends_pairing_problem_dp(int n, vector<int> &dp)
{
    int N = n;
    for (int n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = 1;
            continue;
        }

        int single = dp[n - 1];
        int pairUp = dp[n - 2] * (n - 1);

        dp[n] = single + pairUp;
    }
    return dp[N];
}

//* Leetcode -64 ======================================================

int minPathSum_(int sr, int sc, vector<vector<int>> &grid, vector<vector<int>> &dp)
{

    if (sr == grid.size() - 1 && sc == grid[0].size() - 1)
    {
        return dp[sr][sc] = grid[sr][sc];
    }

    if (dp[sr][sc] != 0)
    {
        return dp[sr][sc];
    }

    int minCost = (int)1e8;
    if (sr + 1 < grid.size())
    {
        minCost = min(minPathSum_(sr + 1, sc, grid, dp), minCost);
    }

    if (sc + 1 < grid[0].size())
    {
        minCost = min(minPathSum_(sr, sc + 1, grid, dp), minCost);
    }

    return dp[sr][sc] = minCost + grid[sr][sc];
}

int minPathSum_tab(vector<vector<int>> &grid, vector<vector<int>> &dp)
{

    for (int sr = grid.size() - 1; sr >= 0; sr--)
    {
        for (int sc = grid[0].size() - 1; sc >= 0; sc--)
        {
            if (sr == grid.size() - 1 && sc == grid[0].size() - 1)
            {
                dp[sr][sc] = grid[sr][sc];
                continue;
            }

            int minCost = (int)1e8;
            if (sr + 1 < grid.size())
            {
                minCost = min(dp[sr + 1][sc], minCost); //min(minPathSum_(sr + 1, sc, grid, dp), minCost);
            }

            if (sc + 1 < grid[0].size())
            {
                minCost = min(dp[sr][sc + 1], minCost); //min(minPathSum_(sr, sc + 1, grid, dp), minCost);
            }

            dp[sr][sc] = minCost + grid[sr][sc];
        }
    }
    return dp[0][0];
}

int minPathSum(vector<vector<int>> &grid)
{

    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    return minPathSum_tab(grid, dp);
}

//* https://practice.geeksforgeeks.org/problems/gold-mine-problem/0

int dir[3][2] = {{-1, 1}, {0, 1}, {1, 1}};
int goldmine(int sr, int sc, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (sc == grid[0].size() - 1)
    {
        return dp[sr][sc] = grid[sr][sc];
    }

    if (dp[sr][sc] != 0)
    {
        return dp[sr][sc];
    }

    int maxCoin = (int)-1e7;
    for (int d = 0; d < 3; d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];

        if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size())
        {
            maxCoin = max(maxCoin, goldmine(x, y, grid, dp));
        }
    }

    return dp[sr][sc] = maxCoin + grid[sr][sc];
}

int goldmineDP(vector<vector<int>> &grid)
{
    int dirG[3][2] = {{-1, 1}, {0, 1}, {1, 1}};
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int sc = m - 1; sc >= 0; sc--)
    {
        for (int sr = 0; sr < n; sr++)
        {
            if (sc == grid[0].size() - 1)
            {
                dp[sr][sc] = grid[sr][sc];
                continue;
            }

            int maxCoin = (int)-1e7;
            for (int d = 0; d < 3; d++)
            {
                int x = sr + dirG[d][0];
                int y = sc + dirG[d][1];

                if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size())
                {
                    maxCoin = max(maxCoin, dp[x][y]);
                }
            }

            dp[sr][sc] = maxCoin + grid[sr][sc];
        }
    }

    int maxAns = (int)-1e7;
    for (int i = 0; i < n; i++)
    {
        maxAns = max(maxAns, dp[i][0]);
    }
    return maxAns;
}

void goldmineSet()
{
    vector<vector<int>> grid = {{1, 3, 1, 5},
                                {2, 2, 4, 1},
                                {5, 0, 2, 3},
                                {0, 6, 1, 2}};
    int m = 4, n = 4;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxCoin = (int)-1e8;
    for (int i = 0; i < grid.size(); i++)
    {
        maxCoin = goldmine(i, 0, grid, dp);
    }
    cout << maxCoin << endl;
    display2D(dp);

    cout << goldmineDP(grid) << endl;
    display2D(dp);
}

//* https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/

int countWaysToPartition_into_k_subsets_rec(int n, int k, vector<vector<int>> &dp)
{
    if (n == k || k == 1)
    {
        return dp[n][k] = 1;
    }

    if (dp[n][k] != 0)
        return dp[n][k];

    int newGroupsWays = countWaysToPartition_into_k_subsets_rec(n - 1, k - 1, dp);
    int existingGroupsWays = countWaysToPartition_into_k_subsets_rec(n - 1, k, dp) * k;

    int totalWays = newGroupsWays + existingGroupsWays;
    return dp[n][k] = totalWays;
}

void partition_set_into_k_subsets()
{

    int n = 5;
    int k = 3;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    cout << countWaysToPartition_into_k_subsets_rec(n, k, dp) << endl;

    display2D(dp);
}

//Todo https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad/0

//! Substring and Subsequence Series.=========================================================================

vector<vector<bool>> isPlaindromeSubstring(string str)
{
    int n = str.length();
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
                dp[i][j] = true;
            else if (gap == 1 && str[i] == str[j])
                dp[i][j] = true;
            else
                dp[i][j] = str[i] == str[j] && dp[i + 1][j - 1];
        }
    }

    return dp;
}

string longestPlaindromeSubstring(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int maxLen = 0;
    int si = 0, ei = 0;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;
            else if (gap == 1 && str[i] == str[j])
                dp[i][j] = 2;
            else if (str[i] == str[j] && dp[i + 1][j - 1] != 0)
                dp[i][j] = gap + 1; //coz gap 0 se start ho rha hai issliye +1 kra.

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

int countAllPlaindromicSubstring(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int count = 0;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;
            else if (gap == 1 && str[i] == str[j])
                dp[i][j] = 2;
            else if (str[i] == str[j] && dp[i + 1][j - 1] != 0)
                dp[i][j] = gap + 1;

            count += dp[i][j] != 0 ? 1 : 0;
        }
    }

    return dp[0][n - 1];
}

int longestPlaindromeSubseq_Rec(string str, int si, int ei, vector<vector<int>> &dp, vector<vector<bool>> &isPalindrome)
{
    if (isPalindrome[si][ei])
        return dp[si][ei] = ei - si + 1;
    if (dp[si][ei] != 0)
        return dp[si][ei];

    int len = 0;
    if (str[si] == str[ei])
        len = longestPlaindromeSubseq_Rec(str, si + 1, ei - 1, dp, isPalindrome) + 2;
    else
        len = max(longestPlaindromeSubseq_Rec(str, si + 1, ei, dp, isPalindrome), longestPlaindromeSubseq_Rec(str, si, ei - 1, dp, isPalindrome));

    return dp[si][ei] = len;
}

int longestPlaindromeSubseq_DP(string str, int si, int ei, vector<vector<int>> &dp, vector<vector<bool>> &isPalindrome)
{

    for (int gap = 0; gap < str.length(); gap++)
    {
        for (si = 0, ei = gap; ei < str.length(); si++, ei++)
        {

            if (isPalindrome[si][ei])
            {
                dp[si][ei] = ei - si + 1;
                continue;
            }

            int len = 0;
            if (str[si] == str[ei])
                len = dp[si + 1][ei - 1] + 2;
            else
                len = max(dp[si + 1][ei], dp[si][ei - 1]);
            dp[si][ei] = len;
        }
    }

    return dp[0][str.length() - 1];
}

// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
int countPS_(string &s, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return dp[i][j] = 1;
    if (dp[i][j] != 0)
        return dp[i][j];

    int middleString = countPS_(s, i + 1, j - 1, dp);
    int excludingLast = countPS_(s, i, j - 1, dp);
    int excludingFirst = countPS_(s, i + 1, j, dp);

    int ans = excludingFirst + excludingLast;
    return dp[i][j] = (s[i] == s[j]) ? ans + 1 : ans - middleString;
}

// int countPS_(string &s, int i, int j, vector<vector<int>> &dp)
// {
//     for (int gap = 0; gap <)
//         if (i > j)
//             return 0;
//     if (i == j)
//         return dp[i][j] = 1;
//     if (dp[i][j] != 0)
//         return dp[i][j];

//     int middleString = countPS_(s, i + 1, j - 1, dp);
//     int excludingLast = countPS_(s, i, j - 1, dp);
//     int excludingFirst = countPS_(s, i + 1, j, dp);

//     int ans = excludingFirst + excludingLast;
//     return dp[i][j] = (s[i] == s[j]) ? ans + 1 : ans - middleString;
// }

int countPS(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    return countPS_(str, 0, str.length() - 1, dp);
}

//Leetcode - 1143 ======================================
int longestCommonSubsequence_(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{

    if (i == text1.length() || j == text2.length())
        return 0;
    if (dp[i][j] != 0)
        return dp[i][j];

    int ans = 0;
    if (text1[i] == text2[j])
        ans = longestCommonSubsequence_(text1, text2, i + 1, j + 1, dp) + 1;
    else
    {
        ans = max(longestCommonSubsequence_(text1, text2, i + 1, j, dp), longestCommonSubsequence_(text1, text2, i, j + 1, dp));
    }

    return dp[i][j] = ans;
}

int longestCommonSubsequence_tab(string &text1, string &text2, vector<vector<int>> &dp)
{

    for (int i = text1.length(); i >= 0; i--)
    {
        for (int j = text2.length(); j >= 0; j--)
        {
            if (i == text1.length() || j == text2.length())
            {
                dp[i][j] = 0;
                continue;
            }
            int ans = 0;
            if (text1[i] == text2[j])
                ans = dp[i + 1][j + 1] + 1; //longestCommonSubsequence_(text1, text2, i + 1, j + 1, dp) + 1;
            else
            {
                ans = max(dp[i + 1][j], dp[i][j + 1]); //max(longestCommonSubsequence_(text1, text2, i + 1, j, dp), longestCommonSubsequence_(text1, text2, i, j + 1, dp));
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
    return longestCommonSubsequence_tab(text1, text2, dp);
}

int maxAns = 0;
int longestCommonSubstring_(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{

    if (i == text1.length() || j == text2.length())
        return 0;
    if (dp[i][j] != 0)
        return dp[i][j];

    longestCommonSubstring_(text1, text2, i + 1, j, dp);
    longestCommonSubstring_(text1, text2, i, j + 1, dp);

    if (text1[i] == text2[j])
    {
        int a = longestCommonSubstring_(text1, text2, i + 1, j + 1, dp);
        maxAns = max(maxAns, a);
        return dp[i][j] = a;
    }

    return 0;
}

// int longestCommonSubstring_tab(string &text1, string &text2, vector<vector<int>> &dp)
// {

//     for (int i = text1.length(); i >= 0; i--)
//     {
//         for (int j = text2.length(); j >= 0; j--)
//         {
//             if (i == text1.length() || j == text2.length()){
//                 dp[i][j] = 0;
//                 continue;
//             }

//             if (text1[i] == text2[j]){
//                 int a = dp[i + 1][j + 1] + 1;
//             }

//             dp[i][j] = ans;
//         }
//     }
//     return dp[0][0];
// }

void stringSubstringSet()
{
    string str = "geeksforgeeks";
    int n = str.length();
    int si = 0, ei = n - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    vector<vector<bool>> isPlalindrome = isPlaindromeSubstring(str);
    // cout << longestPlaindromeSubstring("abcaacbefgpgf") << endl;

    // cout << longestPlaindromeSubseq_Rec(str, si, ei, dp, isPlalindrome) << endl;
    cout << longestPlaindromeSubseq_DP(str, si, ei, dp, isPlalindrome) << endl;

    display2D(dp);
}

//Leetcode - 1035 =================================================
int maxUncrossedLines_dp(vector<int> &A, vector<int> &B, vector<vector<int>> &dp)
{

    int n = A.size();
    int m = B.size();
    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {

            if (i == n || j == m)
            {
                dp[i][j] = 0;
                continue;
            }

            int ans = 0;
            if (A[i] == B[j])
            {
                ans = dp[i + 1][j + 1] + 1;
            }
            else
            {
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int maxUncrossedLines(vector<int> &A, vector<int> &B)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
    return maxUncrossedLines_dp(A, B, dp);
}

//Leetcode - 1458 ==============================================
int maxDotProduct_(vector<int> &nums1, vector<int> &nums2, int i, int j, vector<vector<int>> &dp)
{
    if (i == nums1.size() || j == nums2.size())
        return dp[i][j] = -1e8;
    if (dp[i][j] != 0)
        return dp[i][j];

    int val = nums1[i] * nums2[j];
    int a = maxDotProduct_(nums1, nums2, i + 1, j + 1, dp) + val;
    int b = maxDotProduct_(nums1, nums2, i + 1, j, dp);
    int c = maxDotProduct_(nums1, nums2, i, j + 1, dp);

    return dp[i][j] = max(max(a, b), max(c, val));
}

int maxDotProduct_tab(vector<int> &nums1, vector<int> &nums2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            if (i == n || j == m)
            {
                dp[i][j] = -1e8;
                continue;
            }

            int val = nums1[i] * nums2[j];
            int a = dp[i + 1][j + 1] + val;
            int b = dp[i + 1][j];
            int c = dp[i][j + 1];

            dp[i][j] = max(max(a, b), max(c, val));
        }
    }
    return dp[0][0];
}

int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    return maxDotProduct_tab(nums1, nums2, n, m);
}

//Coin change questions ============================================

// https://www.geeksforgeeks.org/find-number-of-solutions-of-a-linear-equation-of-n-variables/

//Leetcode - 322 Coin change ==============================================
int coinchange_(vector<int> &coins, int amt, int idx, vector<vector<int>> &dp)
{
    if (amt == 0)
    {
        return dp[idx][amt] = 0;
    }

    if (dp[idx][amt] != 0)
        return dp[idx][amt];

    int minCoin = (int)1e9;
    for (int i = idx; i < coins.size(); i++)
    {

        if (amt - coins[i] >= 0)
        {
            int count = coinchange_(coins, amt - coins[i], i, dp) + 1;

            if (count < minCoin)
                minCoin = count;
        }
    }

    return dp[idx][amt] = minCoin;
}

int coinchange_dp(vector<int> &coins, int amount, vector<vector<int>> &dp)
{
    for (int amt = 0; amt <= amount; amt++)
    {
        for (int idx = 0; idx < coins.size(); idx++)
        {
            if (amt == 0)
            {
                dp[idx][amt] = 0;
                continue;
            }

            int minCoin = (int)1e9;
            for (int i = idx; i < coins.size(); i++)
            {

                if (amt - coins[i] >= 0)
                {
                    int count = dp[idx][amt - coins[i]] + 1;
                    if (count < minCoin)
                        minCoin = count;
                }
            }

            dp[idx][amt] = minCoin;
        }
    }

    return dp[0][amount];
}

int coinChange(vector<int> &coins, int amount)
{
    if (amount < 1)
        return 0;

    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    int ans = coinchange_dp(coins, amount, dp);
    if (ans == 1e9)
        return -1;

    return ans;
}

int targetSum_(vector<int> &coins, int tar, int idx, vector<vector<int>> &dp)
{
    if (idx == coins.size())
    {
        if (tar == 0)
            return dp[idx][tar] = 1;
        return dp[idx][tar] = 0;
    }

    if (dp[idx][tar] != 0)
        return dp[idx][tar];

    int count = 0;
    if (tar - coins[idx] >= 0)
    {
        count += targetSum_(coins, tar - coins[idx], idx + 1, dp);
    }

    count += targetSum_(coins, tar, idx + 1, dp);
    return dp[idx][tar] = count;
}

int targetSum_02(vector<int> &coins, int tar, int idx, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (tar == 0)
            return dp[idx][tar] = 1;
        return dp[idx][tar] = 0;
    }

    if (dp[idx][tar] != 0)
        return dp[idx][tar];

    int count = 0;
    if (tar - coins[idx - 1] >= 0)
    {
        count += targetSum_02(coins, tar - coins[idx - 1], idx - 1, dp);
    }

    count += targetSum_02(coins, tar, idx - 1, dp);
    return dp[idx][tar] = count;
}

void targetSum()
{
    vector<int> coins = {2, 3, 5, 7};
    int tar = 10;
    vector<vector<int>> dp(coins.size() + 1, vector<int>(tar + 1, 0));
    cout << targetSum_(coins, tar, 0, dp) << endl;
    // cout << targetSum_02(coins, tar, coins.size(), dp) << endl;

    display2D(dp);
}

int knapsack_01(vector<int> &wt, vector<int> val, int W, int idx, vector<vector<int>> &dp)
{

    if (W == 0 || idx == 0)
    {
        return 0;
    }

    if (W - wt[idx - 1] >= 0)
    {
    }
}

// int knapsack_01(vector<int> &wt, vector<int> &arr, int W, vector<vector<int>> &dp)
// {
//     int Tar = W;

//     for (int idx = 0; idx < arr.size(); idx++)
//     {
//         for (int tar = 0; tar <= Tar; tar++)
//         {
//             if (idx == 0 || tar == 0)
//             {
//                 continue;
//             }

//             int maxProfit = -1e8;
//             if (tar - wt[idx - 1] >= 0)
//             {
//                 maxProfit = max(maxProfit, dp[idx - 1][tar - wt[idx - 1]] + arr[idx - 1]);
//             }

//             maxProfit = max(maxProfit, dp[idx - 1][tar]);
//             dp[idx][tar] = maxProfit;
//         }
//     }

//     return dp[arr.size()][W];
// }

//Todo int unboundedKnapsack()

void knapsack()
{
    vector<int> arr = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    vector<vector<int>> dp(wt.size() + 1, vector<int>(W + 1, 0));
    // cout << knapsack_01(wt, arr, W, dp) << endl;

    display2D(dp);
}

//Leetcode - 416 partition into 2 equal subsets ==========================================
bool canPartition_(vector<int> &nums, int n, int sum, vector<vector<int>> dp)
{

    if (n == 0 || sum == 0)
    {
        if (sum == 0)
            return dp[n][sum] = 1;
        return dp[n][sum] = 0;
    }

    if (dp[n][sum] != -1)
        return dp[n][sum];

    bool res = false;
    res = res || canPartition_(nums, n - 1, sum - nums[n - 1], dp);
    res = res || canPartition_(nums, n - 1, sum, dp);

    return dp[n][sum] = res ? 1 : 0;
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int ele : nums)
        sum += ele;

    if (sum % 2 != 0)
        return false;

    sum /= 2;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
    return canPartition_(nums, nums.size(), sum, dp);
}

//LIS SET ==============================================================

// int LIS_leftToRight_rec(vector<int> &arr, int idx)
// {

//     int oMax = 0;
//     LIS_leftToRight_rec()
// }

int LIS_leftToRight_DP(vector<int> &arr, vector<int> &dp)
{

    int N = arr.size();
    int oMax = 0;
    for (int i = 0; i < N; i++)
    {

        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {

            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        oMax = max(oMax, dp[i]);
    }

    return oMax;
}

int LDS_leftToRight_DP(vector<int> &arr, vector<int> &dp)
{

    int N = arr.size();
    int oMax = 0;
    for (int i = 0; i < N; i++)
    {

        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {

            if (arr[i] < arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        oMax = max(oMax, dp[i]);
    }

    return oMax;
}

int LIS_RightToLeft_DP(vector<int> &arr, vector<int> &dp)
{

    int N = arr.size();
    int oMax = 0;
    for (int i = N - 1; i >= 0; i--)
    {

        dp[i] = 1;
        for (int j = i + 1; j < N; j++)
        {

            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        oMax = max(oMax, dp[i]);
    }

    return oMax;
}

//GFG
int longestBitonicSubequence(vector<int> &arr, vector<int> &dp)
{
    //Todo First calculate LIS(l to r) , second calc LIS(r to l).
    vector<int> dp1(arr.size(), 0);
    vector<int> dp2(arr.size(), 0);

    LIS_RightToLeft_DP(arr, dp2);
    LIS_leftToRight_DP(arr, dp1);

    int omax = dp1[0] + dp2[0] - 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (dp1[i] + dp2[i] - 1 > omax)
        {
            omax = dp1[i] + dp2[i] - 1;
        }
    }

    return omax;
}

int maxSumIncreasingSubsequence(vector<int> &arr, vector<int> &dp)
{

    int N = arr.size();
    int oMax = 0;
    for (int i = 0; i < N; i++)
    {

        dp[i] = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {

            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }

        oMax = max(oMax, dp[i]);
    }

    return oMax;
}

//Leetcode - Russian Dolls
// int maxEnvelopes(vector<vector<int>>& envelopes) {

//     int n = envelopes.size();
//     if(n == 0) return 0;

//     pair<int, int> dimen[n];
//     for(int i=0; i<n; i++){
//         dimen[i] = make_pair(envelopes[i][0], envelopes[i][1]);
//     }

//     sort()
// }

int countLIS(vector<int> &arr)
{
    int N = arr.size();
    vector<int> dp(N, 0);
    vector<int> count(N, 0);

    int oMax = 0;
    int maxCount = 0;
    for (int i = 0; i < N; i++)
    {

        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {

            if (arr[i] >= arr[j])
            {
                if (dp[j] + 1 == oMax)
                {
                    count[i] += maxCount + 1;
                }
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        oMax = max(oMax, dp[i]);
    }

    return maxCount;
}

//* Leetcode - 91 Decode ways ====================================
int numDecodings_(string &s, int vidx, vector<int> &dp)
{

    if (vidx == s.length())
        return dp[vidx] = 1;

    if (dp[vidx] != -1)
    {
        return dp[vidx];
    }

    char ch = s[vidx];
    if (ch == '0')
    {
        return dp[vidx] = 0;
    }

    int count = 0;
    count += numDecodings_(s, vidx + 1, dp);

    if (vidx + 1 < s.length())
    {

        int num = (ch - '0') * 10 + (s[vidx + 1] - '0');
        if (num <= 26)
        {
            count += numDecodings_(s, vidx + 2, dp);
        }
    }

    return dp[vidx] = count;
}

int numDecodings(string s)
{

    vector<int> dp(s.length() + 1, -1);
    return numDecodings_(s, 0, dp);
}

//* https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0

// int count_subsequences(string &s, vector<int> &dp)
// {

//     int acount = 0;
//     int bcount = 0;
//     int ccount = 0;
// }

//*Leetcode - Distinct subsequences - 2 ==================================
// int distinctSubseqII(string str)
// {

//     str = "$" + str;
//     int n = str.length();
//     vector<int> dp(n, 0);
//     vector<int> lastOcurr(26, -1);

//     for (int i = 0; i < n; i++)
//     {

//         if (i == 0)
//         {
//             dp[i] = 1;
//             continue;
//         }

//     }
// }

//*Leetcode - 639 =========================================================
// int numDecodings(string s)
// {
// }

void LIS()
{
    // vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15, 8};
    vector<int> arr = {1, 101, 2, 3, 100, 4, 5};
    vector<int> dp(arr.size(), 0);
    // return LIS_leftToRight_DP(arr, dp);
    cout << maxSumIncreasingSubsequence(arr, dp) << endl;
    display(dp);
}

//Leetcode -300 - LIS ===================================================
int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);
    return LIS_leftToRight_DP(nums, dp);
}

//! Matrix chain multiplication (MCM) -> CUT STRATEGY ==============================

int mcm(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{

    if (si + 1 == ei)
    {
        return dp[si][ei] = 0;
    }

    if (dp[si][ei] != -1)
    {
        return dp[si][ei];
    }

    int ans = (int)1e9;
    for (int cut = si + 1; cut < ei; cut++)
    {

        int leftSum = mcm(arr, si, cut, dp);
        int rightSum = mcm(arr, cut, ei, dp);

        int total = leftSum + arr[si] * arr[cut] * arr[ei] + rightSum;

        if (total < ans)
            ans = total;
    }

    return dp[si][ei] = ans;
}

int mcm_dp(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{

    for (int gap = 1; gap < arr.size(); gap++)
    {

        for (int si = 0, ei = gap; ei < arr.size(); si++, ei++)
        {
            if (si + 1 == ei)
            {
                dp[si][ei] = 0;
                continue;
            }

            int ans = (int)1e9;
            for (int cut = si + 1; cut < ei; cut++)
            {

                int leftSum = dp[si][cut];  //mcm(arr, si, cut, dp);
                int rightSum = dp[cut][ei]; // mcm(arr, cut, ei, dp);

                int total = leftSum + arr[si] * arr[cut] * arr[ei] + rightSum;

                if (total < ans)
                    ans = total;
            }

            dp[si][ei] = ans;
        }
    }

    return dp[0][ei];
}

void mcm_dp_Path(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<string>> sdp(n, vector<string>(n, ""));

    for (int gap = 1; gap < arr.size(); gap++)
    {
        for (int si = 0, ei = gap; ei < arr.size(); si++, ei++)
        {
            if (si + 1 == ei)
            {
                dp[si][ei] = 0;
                sdp[si][ei] = (char)(si + 'A');
                continue;
            }

            int ans = (int)1e9;
            string sans = "";
            for (int cut = si + 1; cut < ei; cut++)
            {

                int leftSum = dp[si][cut];  //mcm(arr, si, cut, dp);
                int rightSum = dp[cut][ei]; // mcm(arr, cut, ei, dp);

                int total = leftSum + arr[si] * arr[cut] * arr[ei] + rightSum;

                if (total < ans)
                {
                    ans = total;
                    sans = "(" + sdp[si][cut] + sdp[cut][ei] + ")";
                }
            }

            dp[si][ei] = ans;
            sdp[si][ei] = sans;
        }
    }

    cout << dp[0][arr.size() - 1] << endl;
    cout << sdp[0][arr.size() - 1] << endl;
}

//* Leetcode - 132 Pallindrome Partitioning -2 =====================================
int dp1[1600][1600];
bool isPalin(string &s, int i, int j)
{
    if (i >= j)
        return true;
    if (dp1[i][j] != -1)
        return dp1[i][j];
    if (s[i] == s[j])
        return dp1[i][j] = isPalin(s, i + 1, j - 1);
    return dp1[i][j] = false;
}

int minPallindromicCut(string &s, int si, int ei, vector<vector<int>> &dp)
{

    if (si >= ei)
        return dp[si][ei] = 0;

    if (dp[si][ei] != -1)
        return dp[si][ei];

    if (isPalin(s, si, ei))
        return dp[si][ei] = 0;

    int minCut = (int)1e9;
    for (int cut = si + 1; cut <= ei; cut++)
    {

        int left;
        int right;

        if (dp[si][cut - 1] != -1)
            left = dp[si][cut - 1];
        else
        {
            left = minPallindromicCut(s, si, cut - 1, dp);
            dp[si][cut - 1] = left;
        }

        if (dp[cut][ei] != -1)
            right = dp[cut][ei];
        else
        {
            right = minPallindromicCut(s, cut, ei, dp);
            dp[cut][ei] = right;
        }

        int total = left + 1 + right;
        if (total < minCut)
            minCut = total;
    }

    return dp[si][ei] = minCut;
}

int minPallindromicCut_dp(string &s, vector<vector<int>> &dp)
{
    int n = s.length();
    for (int gap = 0; gap < n; gap++)
    {
        for (int si = 0, ei = gap; ei < n; si++, ei++)
        {
            if (gap == 0)
            {
                dp[si][ei] = 0;
                continue;
            }
            else if (gap == 1 && s[si] == s[ei])
            {
                dp[si][ei] = 0;
            }
            else if (s[si] == s[ei] && dp[si + 1][ei - 1] == 0)
            {
                dp[si][ei] = 0;
            }
            else
            {
                int minCut = (int)1e9;
                for (int cut = si + 1; cut <= ei; cut++)
                {
                    int left = dp[si][cut-1]; //minPallindromicCut(s, si, cut - 1, dp);

                    int right = dp[cut][ei]; //minPallindromicCut(s, cut, ei, dp);

                    int total = left + 1 + right;
                    if (total < minCut)
                        minCut = total;
                }

                dp[si][ei] = minCut;
            }
        }
    }

    return dp[0][n-1];
}

int minCut()
{

    string s = "abccbc";
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // memset(dp1, -1, sizeof dp1);
    cout << minPallindromicCut_dp(s, dp) << endl;
    display2D(dp);
}

void cutSet()
{
    minCut();
    // vector<int> arr = {2, 3, 4, 5, 6, 7};
    // //? vector<int> arr = {470, 36, 153, 122, 394 ,291, 290, 110 ,132, 174 ,265, 236, 49, 296, 378, 314, 334 ,199 ,450 ,356, 156, 294, 469, 157, 461, 434, 324, 287, 172, 359 ,178, 141, 246, 182, 262, 491, 324, 51 ,101, 455};
    // int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << mcm_dp(arr, 0, n - 1, dp) << endl;
    // mcm_dp_Path(arr);
}

//* https://practice.geeksforgeeks.org/problems/optimal-binary-search-tree/0

int costSearching(vector<int> &freq, int si, int ei)
{
    int sum = 0;
    for (int i = si; i <= ei; i++)
        sum += freq[si];
    return sum;
}

int optimalBST(vector<int> &freq, int si, int ei, vector<vector<int>> &dp)
{
    if (dp[si][ei] != 0)
        return dp[si][ei];

    int minCost = (int)1e9;
    for (int cut = si; cut <= ei; cut++)
    {

        int leftCost = (cut == si) ? 0 : optimalBST(freq, si, cut - 1, dp);
        int rightCost = (cut == ei) ? 0 : optimalBST(freq, cut + 1, ei, dp);

        int myCost = leftCost + costSearching(freq, si, ei) + rightCost;

        if (myCost < minCost)
            minCost = myCost;
    }

    return dp[si][ei] = minCost;
}

void optimalBST()
{
    vector<int> arr = {10, 12, 20};
    vector<int> freq = {2, 3, 4, 5, 6, 7};
}

void set2()
{
    int n = 10;
    vector<int> dp(n + 1, 0);
    cout << friends_pairing_problem_dp(n, dp) << endl;

    display(dp);
}

void pathSet()
{
    // int n = 3, m = 3;
    // vector<vector<int>> dp(n, vector<int>(m, 0));
    // cout << mazePathHV(0, 0, n - 1, m - 1, dp) << endl;
    // cout << mazePathHV_DP(0, 0, n - 1, m - 1, dp) << endl;
    // cout << mazePathMulti(0, 0, n - 1, m - 1, dp) << endl;
    // cout << mazePathMulti(0, 0, n - 1, m - 1, dp) << endl;

    int sp = 0, ep = 10;
    vector<int> dp(ep + 1, 0);
    // vector<int> diceArray{1, 2, 3, 4, 5, 6};
    cout << boardPathDP(sp, ep, dp) << endl;
    // cout << boardPathWithDiceArrayDP(sp, ep, dp, diceArray) << endl;
    cout << boardPath_best(sp, ep);

    // display(dp);
    // display2D(dp);
}

void set1()
{
    int n = 5;
    vector<int> dp(n + 1, 0);
    cout << fibo(n, dp) << endl;
    cout << fiboDP(n, dp) << endl;

    display(dp);
}

void solve()
{
    // set2();
    // set1();
    // pathSet();
    // goldmineSet();
    // targetSum();
    // knapsack();
    // LIS();
    cutSet();
    // partition_set_into_k_subsets();
}

int main()
{
    solve();
    return 0;
}