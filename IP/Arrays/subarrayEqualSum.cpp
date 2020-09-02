#include <iostream>
#include <vector>
using namespace std;

void subArrayWithGivenSum(vector<int>& arr, int n, int sum){
    
    for(int i=0; i<n; i++){
        int csum = arr[i];
        for(int j=i+1; j<=n; j++){
            if(csum == sum){
                cout << i+1 << " " << j << endl;
                return;
            }
            
            if(csum > sum || j == n)
                break;
            
            csum += arr[j];
        }
    }
    
    cout << -1 << endl;
}

void solve(){
    int t;
    cin >> t;
    while(t-- >0){
        int n, sum;
        cin >> n >> sum;
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++){
            int val;
            cin >> val;
            arr[i] = val;
        }
        subArrayWithGivenSum(arr, n, sum);
    }
}

int main() {
    solve();
    return 0;
}
