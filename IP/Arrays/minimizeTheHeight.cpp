#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mininmizeTheDiff(vector<int>& arr, int k){
    
    int n = arr.size();
    
    sort(arr.begin(),  arr.end());
    
    int ans = arr[n-1]-arr[0];
    
    int small = arr[0] + k;
    int big = arr[n-1] - k;
    
    if(small > big){
        swap(small, big);    
    }
    
    for(int idx = 1; idx < n-1; idx++){
        
        int addition = arr[idx] + k;
        int subtraction = arr[idx] - k;
        
        //* Coz iske vajeh se koi change nhi aa skta mere ans me.
        if(addition <= big || subtraction >= small)
            continue;
        
        //* Otherwise -> big-subtraction < addition - small => update small
        //* else update big.
        if(big-subtraction <= addition - small)
            small = subtraction;
        else
            big = addition;
    }
    
    return min(ans, big - small);
}

int main() {
	//code
	int t;
	cin >> t;
	while(t-- >0){
	    int k;
	    cin >> k;
	    int N;
	    cin >> N;
	    
	    vector<int> arr(N,0);
	    for(int i=0; i<N; i++){
	        cin >> arr[i];
	    }
	    
	    int ans = mininmizeTheDiff(arr, k);
	    cout << ans << endl;
	}
	return 0;
}