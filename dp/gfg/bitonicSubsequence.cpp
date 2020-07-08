#include <iostream>
#include <vector>

using namespace std;

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

int LIS_RightToLeft_DP(vector<int> &arr, vector<int> &dp)
{

    int N = arr.size();
    int oMax = 0;
    for (int i = N-1; i >=0; i--)
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

int longestBitonicSubequence(vector<int>& arr){
    //Todo First calculate LIS(l to r) , second calc LIS(r to l).
    vector<int> dp1(arr.size(), 0);
    vector<int> dp2(arr.size(), 0);

    LIS_RightToLeft_DP(arr, dp2);
    LIS_leftToRight_DP(arr, dp1);

    int omax = dp1[0] + dp2[0] -1;
    for(int i=0; i<arr.size(); i++){
        if(dp1[i] + dp2[i] -1 > omax){
            omax = dp1[i] + dp2[i] -1;
        }
    }

    return omax;

}

void set(){
    int t;
    cin >> t;
    
    while(t-- >0){
        int n;
        cin >> n;
        
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            arr[i] = a;
        }
        
        cout << longestBitonicSubequence(arr) << endl;
    }
}

int main() {
	//code
	set();
	return 0;
}