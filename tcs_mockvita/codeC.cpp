#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findNoOfChoclates(int a, int b, vector<vector<int>> &dp)
{

    int maxd = max(a, b);
    int mind = min(a, b);

    if (mind == 0)
        return dp[a][b] = 0;
    if (mind == 1)
        return dp[a][b] = a * b;

    if (dp[a][b] != -1)
        return dp[a][b];

    int count = maxd / mind;
    int newd = maxd % mind;

    count += findNoOfChoclates(newd, mind, dp);

    return dp[a][b] = count;
}

void solve()
{
    int p, q, r, s;
    cin >> p;
    cin >> q;

    cin >> r;
    cin >> s;

    vector<vector<int>> dp(q + 1, vector<int>(s + 1, -1));
    int choclates = 0;
    for (int i = p; i <= q; i++)
    {
        for (int j = r; j <= s; j++)
        {
            choclates += findNoOfChoclates(i, j, dp);
        }
    }

    cout << choclates << endl;
}

auto SpeedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int main()
{
    solve();
    return 0;
}