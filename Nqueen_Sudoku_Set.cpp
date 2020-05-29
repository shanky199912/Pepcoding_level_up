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

int queen_in_boxes_combine_2D(int n, int m, int cb,int tq, string asf){

    if(tq == 0){
        cout<<asf<<endl;
        return 1;
    }
    int count = 0;
    for(int i=cb+1; i< n * m; i++){

        int row = i/m;
        int col = i%m;

        count += queen_in_boxes_combine_2D(n,m,i,tq-1,asf + "(" + to_string(row) + "," + to_string(col) + ")");
    }
    return count;
}

int queen_in_boxes_permute_2D(int n, int m, int cb,int tq, string asf, vector<vector<bool>> &vis){

    if(tq == 0){
        cout<<asf<<endl;
        return 1;
    }
    int count = 0;
    for(int i=0; i< n * m; i++){

        int row = i/m;
        int col = i%m;
        if(vis[row][col]== false){
            vis[row][col] = true;
            count += queen_in_boxes_permute_2D(n,m,i,tq-1,asf + "(" + to_string(row) + "," + to_string(col) + ")", vis);
            vis[row][col] = false;
        }
    }
    return count;
}

int queen_in_boxes_combine_2D_subseq(int n, int m, int idx,int tq, string asf){

    if (idx == n*m || tq == 0){
        if(tq == 0){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;

    int row = idx/m;
    int col = idx%m;

    count += queen_in_boxes_combine_2D_subseq(n,m,idx+1,tq-1,asf + "(" + to_string(row) + "," + to_string(col) + ")");
    count += queen_in_boxes_combine_2D_subseq(n,m,idx+1,tq,asf);

    return count;
}

bool isQueenSafeToPlaceAtThisPosition(vector<vector<bool>> &board, int row, int col){

    vector<vector<int>> dir = {{0,-1},{-1,-1},{-1,0},{-1,1}};

    for(int d = 0; d<dir.size(); d++){

        for(int rad=1; rad< board.size(); rad++){

            int r = row + rad * dir[d][0];
            int c = col + rad * dir[d][1];

            if(r>=0 && c>=0 && r<board.size() && c<board.size()){

                if(board[r][c])
                    return false;
            }
            else
                break;
        }
    }

    return true;
}

int nqueen_01(vector<vector<bool>> &board, int qpsf, int idx, string asf){

    if(qpsf == board.size()){
        cout<<asf<<endl;
        return 1;
    }
    int count = 0;

    for(int b=idx; b<board.size() * board.size(); b++){

        int r = b/board.size();
        int c = b%board.size();

        if(isQueenSafeToPlaceAtThisPosition(board,r,c)){
            board[r][c] = true;
            count += nqueen_01(board, qpsf+1, b+1,  asf + "(" + to_string(r) + "," + to_string(c) + ")");
            board[r][c] = false;
        }
    }

    return count;
}

int nqueen_01_subseq(vector<vector<bool>> &board, int qpsf, int idx, string asf){

    if(idx == board.size() * board.size() || qpsf == board.size()){
        if(qpsf == board.size()){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;

    int row = idx/board.size();
    int col = idx%board.size();

    if(isQueenSafeToPlaceAtThisPosition(board, row, col)){
        board[row][col] = true;
        count += nqueen_01_subseq(board, qpsf+1, idx+1, asf + "(" + to_string(row) + "," + to_string(col) + ")");
        board[row][col] = false;
    }

    count += nqueen_01_subseq(board,qpsf, idx+1,asf);

    return count;
}

vector<bool> rowA(4,false);
vector<bool> colA(4,false);
vector<bool> diag(7,false);
vector<bool> adiag(7,false);

int nqueen_02(int m, int n, int qpsf, int idx, string asf){

    if(qpsf == n){
        cout<<asf<<endl;
        return 1;
    }

    int count = 0;
    for(int i=idx; i<m*n; i++){

        int row = i/m;
        int col = i%m;

        if(!rowA[row] && !colA[col] && !diag[row-col+m-1]&&!adiag[row+col]){
            rowA[row] = true;
            colA[col] = true;
            diag[row-col+m-1] = true;
            adiag[row+col] = true;

            count+= nqueen_02(m,n,qpsf+1,i+1, asf + "(" + to_string(row) + "," + to_string(col) + ")");

            rowA[row] = false;
            colA[col] = false;
            diag[row-col+m-1] = false;
            adiag[row+col] = false;
        }
    }

    return count;
}

int row_ = 0;
int col_ = 0;
int diag_ = 0;
int adiag_ = 0;

int nqueen_03(int n, int m, int idx, int qpsf, string asf){

    if(qpsf == n){
        cout<<asf<<endl;
        return 1;
    }
    int count = 0;
    for(int i=idx; i< m*n; i++){

        int r = i/m;
        int c = i%m;

        int xmask = (1<<r);
        int ymask = (1<<c);
        int dmask = (1<<r-c+m-1);
        int admask = (1<<r+c);

        if(!(row_ & xmask) && !(col_ & ymask) && !(diag_ & dmask) && !(adiag_ & admask)){

            row_ ^= xmask;
            col_ ^= ymask;
            diag_ ^= dmask;
            adiag_ ^= admask;

            count += nqueen_03(n,m,i+1,qpsf+1, asf + "(" + to_string(r) + "," + to_string(c) + ")");

            row_ ^= xmask;
            col_ ^= ymask;
            diag_ ^= dmask;
            adiag_ ^= admask;
        }
    }

    return count;
}

int nqueen_03_subseq(int n, int m, int idx, int qpsf, string asf){

    if(idx == m*n || qpsf == n){
        if(qpsf == n){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
  
    int r = idx/m;
    int c = idx%m;

    int xmask = (1<<r);
    int ymask = (1<<c);
    int dmask = (1<<r-c+m-1);
    int admask = (1<<r+c);

    if(!(row_ & xmask) && !(col_ & ymask) && !(diag_ & dmask) && !(adiag_ & admask)){

        row_ ^= xmask;
        col_ ^= ymask;
        diag_ ^= dmask;
        adiag_ ^= admask;

        count += nqueen_03_subseq(n,m,idx+1,qpsf+1, asf + "(" + to_string(r) + "," + to_string(c) + ")");

        row_ ^= xmask;
        col_ ^= ymask;
        diag_ ^= dmask;
        adiag_ ^= admask;
    }

    count+= nqueen_03_subseq(n,m,idx+1,qpsf, asf);

    return count;
}

// arrangments a jayenge queens ke place krne ke .
int nqueen_03_subseq_permute(int n, int m, int idx, int qpsf, string asf, vector<vector<bool>>& vis){

    if(idx == m*n || qpsf == n){
        if(qpsf == n){
            cout<<asf<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
  
    int r = idx/m;
    int c = idx%m;

    int xmask = (1<<r);
    int ymask = (1<<c);
    int dmask = (1<<r-c+m-1);
    int admask = (1<<r+c);

    if(!(row_ & xmask) && !(col_ & ymask) && !(diag_ & dmask) && !(adiag_ & admask) && !vis[r][c]){

        row_ ^= xmask;
        col_ ^= ymask;
        diag_ ^= dmask;
        adiag_ ^= admask;
        vis[r][c] = true;

        count += nqueen_03_subseq_permute(n,m,0,qpsf+1, asf + "(" + to_string(r) + "," + to_string(c) + ")", vis);

        vis[r][c] = false;
        row_ ^= xmask;
        col_ ^= ymask;
        diag_ ^= dmask;
        adiag_ ^= admask;
    }

    count+= nqueen_03_subseq_permute(n,m,idx+1,qpsf, asf, vis);

    return count;
}

int nqueen_04(int n, int m, int r, int tnq, string asf){

    if(r == n || tnq == 0){
        if(tnq == 0){
            cout<<asf<<endl;
        }
    }
    int count = 0;
    for(int i = 0; i<n; i++){
        for(int j=0; j< m; j++){

            int row = r;
            int col = j;

            int xmask = (1<<row);
            int ymask = (1<<col);
            int dmask = (1<<row-col+m-1);
            int admask = (1<<row+col);

            if(!(row_ & xmask) && !(col_ & ymask) && !(diag_ & dmask) && !(adiag_ & admask)){

                row_ ^= xmask;
                col_ ^= ymask;
                diag_ ^= dmask;
                adiag_ ^= admask;

                count += nqueen_04(n,m,r+1,tnq-1, asf + "(" + to_string(row) + "," + to_string(col) + ")");

                row_ ^= xmask;
                col_ ^= ymask;
                diag_ ^= dmask;
                adiag_ ^= admask;
            }

        }
    }
    
    return count;
}



void nqueens(){
    int n =4, m=4;
    vector<vector<bool>> board(n, vector<bool>(m, false));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    rowA.resize(n,false);
    colA.resize(n,false);
    diag.resize(n+m-1,false);
    adiag.resize(n+m-1,false);

    // cout<<nqueen_01(board, 0, 0, "")<<endl;
    //cout<<nqueen_01_subseq(board, 0, 0, "")<<endl;
    //cout<<nqueen_02(m,n,0,0,"")<<endl;
    cout<<nqueen_03_subseq_permute(m,n,0,0,"",vis)<<endl;

}

void queen_in_boxes(){
    int n = 2, tq = 3, m=2;
    vector<bool> boxes(4,false);
    vector<vector<bool>> vis(n,vector<bool>(n,false));

    // cout<<"------Permute--queen--in--boxes--1D-------"<<endl;
    // cout<<queens_in_boxes_1d_permute(boxes, tq, "", 0)<<endl;
    // cout<<"------Permute--queen--in--boxes--1D-------"<<endl;
    // cout<<"------Combine--queen--in--boxes--1D-------"<<endl;
    // cout<<queens_in_boxes_1d_combine(boxes.size(), -1, tq, "", 0)<<endl;
    // cout<<"------Combine--queen--in--boxes--1D-------"<<endl;
    // cout<<queen_in_boxes_combine_1D_02(boxes.size(),0,0,tq,"")<<endl;
    cout<<"------Combine--queen--in--boxes--2D-------"<<endl;
    cout<<queen_in_boxes_combine_2D(n,m,-1,tq,"")<<endl;
    cout<<"------Permute--queen--in--boxes--2D-------"<<endl;
    cout<<queen_in_boxes_permute_2D(n,m,-1,tq,"",vis)<<endl;
    cout<<"------queen_in_boxes_combine_2D_subseq-------"<<endl;
    cout<<queen_in_boxes_combine_2D_subseq(n,m,0,tq,"")<<endl;
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
    //queen_in_boxes();
    nqueens();
}

void solve(){
    coinchange();
}

int main(){
    solve();
    return 0;
}