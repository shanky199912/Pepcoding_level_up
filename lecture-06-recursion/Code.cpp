#include <iostream>

using namespace std;

int countsetbits_01(int n){

    int count = 0;
    while(n>0){
        count += (n & 1);
        n = (n>>1);
    }
    return count;
}

int countsetbits_02(int n){
    
    int count = 0;
    while(n>0){
        n = (n & (n-1));
        count++;
    }
    return count;
}

void setbits(){
    unsigned int n;
    cin>>n;

    //cout<<countsetbits_01(n);
    //cout<<__builtin_popcount(n)<<endl;
    cout<<countsetbits_02(n)<<endl;
}

void bitmasking(){
    setbits();
}

int main(){
    bitmasking();
    return 0;
}