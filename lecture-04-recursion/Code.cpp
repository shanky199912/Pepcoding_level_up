#include<iostream>
#include<vector>

using namespace std;

int coinchange_permute_infinitecoin_01(vector<int> coins, int tar, string asf){

    if(tar == 0){
        cout<<asf<<endl;
        return 1;
    }

    int count = 0;
    for(int i=0;i<coins.size();i++){
        if(tar - coins[i]>=0)
            count += coinchange_permute_infinitecoin_01(coins, tar-coins[i], asf  + to_string(coins[i]));
    }

    return count;
}

int coinchange_comb_infinitecoin_01(vector<int> coins, int tar, int idx, string asf){

    if(tar == 0){
        cout<<asf<<endl;
        return 1;
    }

    int count = 0;
    for(int i=idx;i<coins.size();i++){
        if(tar - coins[i]>=0)
            count += coinchange_comb_infinitecoin_01(coins, tar-coins[i], i, asf  + to_string(coins[i]));
    }

    return count;
}

int coinchange_comb_singlecoin_01(vector<int> coins, int tar, int idx, string asf){

    if(tar == 0){
        cout<<asf<<endl;
        return 1;
    }

    int count = 0;
    for(int i=idx;i<coins.size();i++){
        if(tar - coins[i]>=0){
            count += coinchange_comb_singlecoin_01(coins, tar-coins[i], i+1, asf  + to_string(coins[i]));
        }
    }

    return count;
}

int coinchange_permute_singlecoin_01(vector<int> coins, int tar, int idx, string asf,vector<bool> vis){

    if(tar == 0){
        cout<<asf<<endl;
        return 1;
    }

    int count = 0;
    for(int i=idx;i<coins.size();i++){
        if(tar - coins[i]>=0){
            if(vis[i] == false){
                vis[i] = true;
                count += coinchange_permute_singlecoin_01(coins, tar-coins[i], 0, asf  + to_string(coins[i]),vis);
                vis[i] = false;
            }
        }
    }

    return count;
}

int coinchange_comb_singlecoin_02(vector<int> coins,int tar, int idx, string asf){

    if(idx == coins.size() || tar == 0){
        if(tar == 0){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    //aane ki call
    if(tar - coins[idx] >= 0){
        count += coinchange_comb_singlecoin_02(coins,tar-coins[idx], idx+1, asf + to_string(coins[idx]));
    }
    //nhi aane ki call
    count += coinchange_comb_singlecoin_02(coins,tar,idx+1,asf);

    return count;
}

int coinchange_comb_infinitecoin_02(vector<int> coins,int tar, int idx, string asf){

    if(idx == coins.size() || tar == 0){
        if(tar == 0){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    //aane ki call
    if(tar - coins[idx] >= 0){
        count += coinchange_comb_infinitecoin_02(coins,tar-coins[idx], idx, asf + to_string(coins[idx]));
    }
    //nhi aane ki call
    count += coinchange_comb_infinitecoin_02(coins,tar,idx+1,asf);

    return count;
}

int coinchange_permute_infinitecoin_02(vector<int> coins,int tar, int idx, string asf){

    if(idx == coins.size() || tar == 0){
        if(tar == 0){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    //aane ki call
    if(tar - coins[idx] >= 0){
        count += coinchange_permute_infinitecoin_02(coins,tar-coins[idx], 0, asf + to_string(coins[idx]));
    }
    //nhi aane ki call
    count += coinchange_permute_infinitecoin_02(coins,tar,idx+1,asf);

    return count;
}

int coinchange_permute_singlecoin_02(vector<int> coins,int tar, int idx, string asf,vector<bool> vis){

    if(idx == coins.size() || tar == 0){
        if(tar == 0){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    //aane ki call
    if(tar - coins[idx] >= 0){
        if(vis[idx] == false){
            vis[idx] = true;
            count += coinchange_permute_singlecoin_02(coins,tar-coins[idx], 0, asf + to_string(coins[idx]),vis);
            vis[idx] = false;
        }
    }
    //nhi aane ki call
    count += coinchange_permute_singlecoin_02(coins,tar,idx+1,asf, vis);

    return count;
}

int queens_in_boxes_1d_permute(vector<bool> boxes, int tq, string asf, int cq){

    if(tq == 0){
        cout<<asf<<endl;
        return 1;
    }

    int count = 0;
    for(int b = 0; b<boxes.size();b++){
        if(boxes[b] == false){
            boxes[b] = true;
            count += queens_in_boxes_1d_permute(boxes, tq-1, asf + "B" + to_string(b) +"Q"+ to_string(cq)+" ", cq+1 );
            boxes[b] = false;
        }
    }

    return count;
}

int queens_in_boxes_1d_combine(int n, int cqpi, int tq, string asf, int cq){

    if(tq == 0){
        cout<<asf<<endl;
        return 1;
    }

    int count = 0;
    for(int b = cqpi +1; b<n;b++){
        count += queens_in_boxes_1d_combine(n, b, tq-1, asf + "B" + to_string(b) +"Q"+ to_string(cq)+ " ", cq+1 );
    }

    return count;
}

int queen_in_boxes_combine_1D_02(int n, int cqpi, int cb, int tq, string asf){
    if(tq == 0 || cb == n){
        if(tq == 0){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    count += queen_in_boxes_combine_1D_02(n, cqpi+1, cb+1, tq-1, asf+ "B" + to_string(cb) +"Q"+ to_string(cqpi) +" " );

    count+= queen_in_boxes_combine_1D_02(n,cqpi,cb+1,tq,asf);

    return count;
}

void queen_in_boxes(){
    int n = 5, tq = 3;
    vector<bool> boxes(n,false);

    cout<<"------Permute--queen--in--boxes--1D-------"<<endl;
    cout<<queens_in_boxes_1d_permute(boxes, tq, "", 0)<<endl;
    cout<<"------Permute--queen--in--boxes--1D-------"<<endl;
    cout<<"------Combine--queen--in--boxes--1D-------"<<endl;
    cout<<queens_in_boxes_1d_combine(boxes.size(), -1, tq, "", 0)<<endl;
    cout<<"------Combine--queen--in--boxes--1D-------"<<endl;
    cout<<queen_in_boxes_combine_1D_02(boxes.size(),0,0,tq,"")<<endl;
}

void coinchange_subseq(){
    vector<int> coins = {2,3,5,7};
    int tar = 10;
    vector<bool> vis(coins.size(),false);
    cout<<coinchange_comb_singlecoin_02(coins,tar,0,"")<<endl;
    cout<<"-------"<<endl;
    cout<<coinchange_comb_infinitecoin_02(coins,tar,0,"")<<endl;
    cout<<"-------"<<endl;
    cout<<coinchange_permute_infinitecoin_02(coins,tar,0,"")<<endl;
    cout<<"-------"<<endl;
    cout<<coinchange_permute_singlecoin_02(coins,tar,0,"",vis)<<endl;
    cout<<"-------"<<endl;
    
}

void coinchange_set1(){
    vector<int> coins = {2,3,5,7};
    int tar = 10;
    vector<bool> vis(coins.size(),false);
    cout<<coinchange_permute_infinitecoin_01(coins,tar,"")<<endl;
    cout<<"---------"<<endl;
    cout<<coinchange_comb_infinitecoin_01(coins,tar,0,"")<<endl;
    cout<<"---------"<<endl;
    cout<<coinchange_comb_singlecoin_01(coins,tar,0,"")<<endl;
    cout<<"---------"<<endl;
    cout<<coinchange_permute_singlecoin_01(coins,tar,0,"",vis)<<endl;
}

void coinchange(){
    //coinchange_set1();
    // coinchange_subseq();
    queen_in_boxes();
}

void solve(){
    coinchange();
}

int main(){
    solve();
    return 0;
}