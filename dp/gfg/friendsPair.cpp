#include <iostream>
#include <vector>
#define ll long long int
#define M 1000000007
using namespace std;

ll friends_pairing_problem_dp(ll n, vector<ll> &dp)
{
    ll N = n;
    for (ll n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = 1;
            continue;
        }

        ll single = dp[n - 1] % M;
        ll pairUp = (dp[n - 2] * (n - 1)) % M;

        dp[n] = (single + pairUp) % M;
    }
    return dp[N];
}

void set2()
{   
    int t;
    cin >> t;
    
    while(t-- >0){
        ll n;
        cin >> n;
        
        vector<ll> dp(n + 1, 0);
        ll ans = friends_pairing_problem_dp(n, dp);
        ans = ans % M;
        cout << ans << endl;
    }
}

int main() {
	//code
	set2();
	return 0;
}