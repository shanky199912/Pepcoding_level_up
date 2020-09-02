#include <iostream>
#include <vector>
using namespace std;

int kadansAlgo(vector<int>& arr){
    int osum = 0;
    int csum = 0;
    for(int ele: arr){
        if(csum < 0)
            csum = ele;
        else
            csum += ele;
        
        if(csum > osum)
            osum = csum;
    }
    return osum;
}

int maxCircularSubarraySum_(vector<int>& arr, int n){
    
    int kadan = kadansAlgo(arr);
    
    int arr_sum = 0; //array_Sum
    for(int i =0; i<n; i++){
        arr_sum += arr[i];
        arr[i] = -arr[i];  //Invert the array
    }  
    
    int invertKadan = kadansAlgo(arr); //non-contributing elements pe kadan lag gyi
    int ans = invertKadan + arr_sum; 
    
    int res = max(ans, kadan);
    return (res == 0) ? -1 : res;
}

void solve(){
    int t;
    cin >> t;
    while(t-- >0){
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++){
            int val;
            cin >> val;
            arr[i] = val;
        }
        cout << maxCircularSubarraySum_(arr, n) << endl;
    }
}

int main() {
    solve();
    return 0;
}
