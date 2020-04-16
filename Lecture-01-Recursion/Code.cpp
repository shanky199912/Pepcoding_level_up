#include <iostream>
#include <vector>

using namespace std;

int minimum02(vector<int> arr, int vidx){
    if(vidx == arr.size()-1){
        return arr[vidx];
    }

    int faith = minimum02(arr,vidx+1);
    int minr =  min(faith,arr[vidx]);
    return minr;
}

int minimum01(vector<int> arr, int vidx){
    if(vidx == arr.size()-1){
        return arr[vidx];
    }

    int min = minimum01(arr,vidx+1);
    return (min < arr[vidx]) ? min : arr[vidx];
}

int maximum02(vector<int> arr, int vidx){
    if(vidx == arr.size()-1){
        return arr[vidx];
    }

    int faith = maximum02(arr,vidx+1);
    int maxr =  max(faith,arr[vidx]);
    return maxr;
}

int maximum01(vector<int> arr, int vidx){
    if(vidx == arr.size()-1){
        return arr[vidx];
    }

    int max = maximum01(arr,vidx+1);
    return (max > arr[vidx]) ? max : arr[vidx];
}

void display(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<< arr[i]<<" ";
    }
}

//set2 --------------------------------
int powerBtr(int n, int p){
    if(n == 0){
        return 0;
    }
    
    if(p == 0){
        return 1;
    }

    int faith = powerBtr(n, p/2);
    return (p%2 == 0)? faith * faith : faith * faith * n;
}

int power(int n , int p){
    if(n == 0){
        return 0;
    }
    if(p == 0){
        return 1;
    }

    int faith = power(n , p-1);
    return n * faith;
}

int fact(int n){
    if(n == 0){
        return 1;
    }

    int smalAns = fact(n-1);
    return n * smalAns;
}
//set1 --------------------------------------------

void set2(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    //vector<int> arr = {2,3,6,4,1};
    cout<<maximum02(arr,0)<<endl;
    cout<<minimum02(arr,0)<<endl;
    cout<<minimum01(arr,0);
   // display(arr);
}

void set1(){
   // cout<<fact(5);
   //cout<<power(2,10);
   //cout<<powerBtr(2,11);
}

void solve(){

    //cout<<"Hello from c++";
    //set1();
    set2();
}

int main(){

    solve();
    return 0;
}
