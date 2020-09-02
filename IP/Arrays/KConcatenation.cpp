#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int
#define MOD 1000000007
using namespace std;

int kadansAlgo(vector<int>& arr){
    lli osum = 0
    lli csum = 0;
    for(int ele: arr){
        if(csum < 0)
            csum = ele;
        else
            csum += ele;
        
        if(csum > osum)
            osum = csum;
    }
    return (int)osum;
}

int Kconcatenation(vector<int>& arr, int n, int k){
    
    int kadan = kadansAlgo(arr);
    lli sum = 0;
    for(int ele: arr)
        sum += ele;
    
    //case-1:
    if(k == 1)
        return kadan;

    lli prefix = 0;
    lli suffix = 0;
    lli maxPrefixSum = 0;
    lli maxSuffixSum = 0;

    //calc prefix sum
    for(int ele: arr){
        prefix = (prefix + ele);
        maxPrefixSum = max(maxPrefixSum, prefix); 
    }

    //calc suffix sum
    for(int i=n-1; i>=0; i--){
        suffix = (suffix + arr[i]);
        maxSuffixSum = max(maxSuffixSum, suffix); 
    }

    //case 2:
    if(sum >=0)
        return max(kadan, (int)(sum * (k-2) + maxPrefixSum + maxSuffixSum));
    else //case-3:
        return max(kadan, (int)(maxPrefixSum + maxSuffixSum));
}

void solve(){
    int t;
    cin >> t;
    while(t-- >0){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++){
            int val;
            cin >> val;
            arr[i] = val;
        }
        cout << Kconcatenation(arr, n, k) << endl;
    }
}

int main() {
    solve();
    return 0;
}
