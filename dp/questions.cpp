#include <iostream>
#include <vector>

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
// //Leetcode - 70 =======================================
// int climbStairs(int n)
// {
//     vector<int> dp(n + 1, 0);
//     return climbStairs_(0, n, dp);
// }

// int climbStairs_(int src, int n, vector<int> &dp)
// {
//     if (src == n)
//     {
//         return dp[src] = 1;
//     }

//     if (dp[src] != 0)
//         return dp[src];

//     int count = 0;
//     for (int step = 1; step + src <= n && step <= 2; step++)
//     {
//         count += climbStairs_(step + src, n, dp);
//     }

//     return dp[src] = count;
// }

// int climbStairs_Tab(int src, int n, vector<int> &dp)
// {

//     for (int src = n; src >= 0; src--)
//     {
//         if (src == n)
//         {
//             dp[src] = 1;
//             continue;
//         }

//         int count = 0;
//         for (int step = 1; step + src <= n && step <= 2; step++)
//         {
//             count += dp[src+step];
//         }

//         dp[src] = count;
//     }

//     return dp[0];
// }

// //Leetcode 746 ==========================================
// int minCostClimbingStairs(vector<int>& cost) {
//     int n = cost.size();
//     vector<int> dp(n+1, 0);
//     return minCostClimbingStairs_(n,cost,dp);
// }

// int minCostClimbingStairs_(int index, vector<int>& cost, vector<int>& dp){
//     if(index == 0 || index == 1){
//         return dp[index] = cost[index];
//     }

//     if(dp[index] != 0) return dp[index];

//     return dp[index] = cost[index] + min(minCostClimbingStairs_(index-1, cost, dp), minCostClimbingStairs_(index-2, cost, dp));
// }

// int minCostClimbingStairs_Tab(int index, vector<int>& cost, vector<int>& dp){

//     for(index = 0; index <=cost; index++){

//     }

//     if(index == 0 || index == 1){
//         return dp[index] = cost[index];
//     }

//     if(dp[index] != 0) return dp[index];

//     return dp[index] = cost[index] + min(minCostClimbingStairs_(index-1, cost, dp), minCostClimbingStairs_(index-2, cost, dp));
// }

int minStepsToReduceToOne(int N, vector<int> &dp){

    if(N == 1) return dp[N] = 0;

    if(dp[N] != -1) return dp[N];

    int a = (N % 3 == 0 ? minStepsToReduceToOne(N/3, dp) + 1: (int)1e8);
    int b = (N % 2 == 0 ? minStepsToReduceToOne(N/2, dp) + 1: (int)1e8);
    int c = minStepsToReduceToOne(N-1, dp) + 1;

    return dp[N] = min(a, min(b,c));
}


void solve()
{   
    int n = 21;
    vector<int> dp(n+1, -1);
    cout << minStepsToReduceToOne(n, dp) << endl;

    display(dp);
}

int main()
{
    solve();
    return 0;
}