#include <iostream>
#include <vector>
using namespace std;

//* 1st method
void moveZeroesToEnd(vector<int>& arr){
    int cnt = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != 0)
            arr[cnt++] = arr[i];
    }
    
    while(cnt < arr.size()){
        arr[cnt] = 0;
        cnt++;
    }
}

//* 2nd method -> 2 pointers
void moveZeroesToEnd_02(vector<int>& arr){
    int j =0;
    for(int i=1; i<arr.size(); i++){
        if(arr[i] != 0 && arr[j] == 0){
            swap(arr[i], arr[j]);
        }
        
        if(arr[j] != 0)
            j++;
    }
}

int main() {
	//code
	int t;
	cin >> t;
	while(t-- >0){
	    int n;
	    cin >> n;
	    vector<int> arr(n,0);
	    for(int i=0; i<n; i++)
	        cin >> arr[i];
	    
	    moveZeroesToEnd_02(arr);
	    for(int ele: arr)
	        cout << ele << " ";
	    cout << endl;
	}
	return 0;
}