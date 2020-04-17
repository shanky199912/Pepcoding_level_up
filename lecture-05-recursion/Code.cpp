#include<iostream>
#include<vector>

using namespace std;

int coin_change_comb_singlecoin_02(vector<int> coins, int target, string asf, int idx){

    if(target == 0 || idx == coins.size()){
        if(target == 0){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if(target - coins[idx] >= 0){
        count += coin_change_comb_singlecoin_02(coins,target-coins[idx], asf + to_string(coins[idx]), idx +1 );
    }
    count += coin_change_comb_singlecoin_02(coins, target, asf , idx + 1);
    return count;
}

int coin_change_comb_infinitecoin_02(vector<int> coins, int target, string asf, int idx){

    if(target == 0 || idx == coins.size()){
        if(target == 0){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if(target - coins[idx] >= 0){
        count += coin_change_comb_infinitecoin_02(coins,target-coins[idx], asf + to_string(coins[idx]), idx );
    }
    count += coin_change_comb_infinitecoin_02(coins, target, asf , idx + 1);
    return count;
}

int coin_change_permute_infinitecoin_02(vector<int> coins, int target, string asf, int idx){

    if(target == 0 || idx == coins.size()){
        if(target == 0){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if(target - coins[idx] >= 0){
        // pass 0 in idx  -> i.e open all the options for it.
        count += coin_change_permute_infinitecoin_02(coins,target-coins[idx], asf + to_string(coins[idx]), 0);
    }
    count += coin_change_permute_infinitecoin_02(coins, target, asf , idx + 1);
    return count;
}

int coin_change_permute_singlecoin_02(vector<int> coins, int target, string asf, int idx , vector<bool> vis){

    if(target == 0 || idx == coins.size()){
        if(target == 0){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if(vis[idx] == false){
        if(target - coins[idx] >= 0){
            vis[idx] = true;
            // pass 0 in idx  -> i.e open all the options for it.
            count += coin_change_permute_singlecoin_02(coins,target-coins[idx], asf + to_string(coins[idx]), 0 , vis);
            vis[idx] = false;
        }
    }
    count += coin_change_permute_singlecoin_02(coins, target, asf , idx + 1 , vis);
    return count;
}

//leetcode -singlenumber-2
int singleno(vector<int> arr){

    int ans = 0;
    int k = 3;
    for(int i=0;i<32;i++){
        int mask = (1<<i);
        int count = 0;

        for(int ele:arr){
            if((ele & mask)!=0){
                count++;
            }
        }

        if(count % k != 0){
            ans = (ans | mask);
        }
    }

    return ans;
}


void coinchange(){
    vector<int> coins = {2,3,5,7};
    vector<bool> vis(coins.size(),false);
    cout<<"------comb-single-coin---------"<<endl;
    cout<<coin_change_comb_singlecoin_02(coins, 10,"",0)<<endl;
    cout<<"-------comb-infinite-coin-------"<<endl;
    cout<<coin_change_comb_infinitecoin_02(coins,10,"",0)<<endl;
    cout<<"------permute-infinite-coin---------"<<endl;
    cout<<coin_change_permute_infinitecoin_02(coins,10,"",0)<<endl;
    cout<<"------permute-single-coin---------"<<endl;
    cout<<coin_change_permute_singlecoin_02(coins,10,"",0,vis)<<endl;
}

void queen_in_boxes(){

}

void solve(){
    coinchange();
    //queen_in_boxes();
}

int main(){
    solve();
    return 0;
}