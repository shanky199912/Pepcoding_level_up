#include<iostream>
#include<vector>

using namespace std;

bool isQueenSafe(vector<vector<bool>> board , int row, int col){

    vector<vector<int>> dir = {{0,-1},{-1,-1},{-1,0},{-1,1}};

    for(int d = 0;d<dir.size();d++){

        for(int rad = 1;rad<=board.size();rad ++){

            int r = row + rad* dir[d][0];
            int c = col + rad* dir[d][1];

            if(r>=0 && c>=0 && r<board.size() && c<board[0].size()){
                if(board[r][c])
                    return false;
            
            }
            else
                break;
        }
    }

    return true;
}
int nqueens_01(vector<vector<bool>> board, int tnq, string asf, int cqpi){

    if(tnq == 0){
        cout<<asf<<endl;
        return 1;
    }

    int count = 0;
    for(int b=cqpi + 1; b<board.size() * board.size(); b++){

        int row = b/board.size();
        int col = b%board.size();

        if(isQueenSafe(board,row,col)){
            board[row][col] = true;
            count += nqueens_01(board, tnq-1, asf + "(" + to_string(row) + "," + to_string(col) + ")", b);
            board[row][col] = false;
        }

    }

    return count;
}

vector<bool> rowA(4,false);
vector<bool> colA(4,false);
vector<bool> diag(7,false);
vector<bool> adiag(7,false);

int nqueens_02(vector<vector<bool>> board, int tnq, string asf, int cqpi){

    if(tnq == 0){
        cout<<asf<<endl;
        return 1;
    }

    int count = 0;
    int n = board.size();
    for(int b=cqpi + 1; b<board.size() * board.size(); b++){

        int row = b/board.size();
        int col = b%board.size();

        if(!rowA[row] && !colA[col] && !diag[row-col +n-1] && !adiag[row + col]){

            rowA[row] = true;
            colA[col] = true;
            diag[row-col +n-1] = true;
            adiag[row +col] = true;

            count += nqueens_02(board, tnq-1, asf + "(" + to_string(row) + "," + to_string(col) + ")", b);

            rowA[row] = false;
            colA[col] = false;
            diag[row-col +n-1] = false;
            adiag[row + col] = false;
        }

    }

    return count;
}

int row_ = 0;
int col_ = 0;
int diag_ = 0;
int adiag_ = 0;

int nqueens_03(int m, int n, int tnq, string asf, int cqpi){

    if(tnq == 0){
        cout<<asf<<endl;
        return 1;
    }

    int count = 0;
    for(int b=cqpi + 1; b<n * m; b++){

        int row = b/m;
        int col = b%m;

        //idx nikal liye bits me mene.
        int maskX = (1<<row);
        int maskY = (1<<col);

        //!(row_ & (1<<row)) -> (row_ & (1<<row))==0
        if(!(row_ & (1<<row)) && !(col_ & (1<<col)) && !(diag_ & (1<<row-col+m-1)) && !(adiag_ & (1<<row+col))){

            row_ ^= (1<<row);
            col_ ^= (1<<col);
            diag_ ^= (1<<row-col+m-1);
            adiag_ ^= (1<<row+col);

            count += nqueens_03(m,n, tnq-1, asf + "(" + to_string(row) + "," + to_string(col) + ")", b);

            row_ &= ~(1<<row);
            col_ &= ~(1<<col);
            diag_ &= ~(1<<row-col+m-1);
            adiag_ &= ~(1<<row+col);
        }

    }

    return count;
}

//sudoku
bool isSafeToPlaceNumber(vector<vector<int>> &board, int row, int col, int num){

    //row ka check
    for(int i=0;i<board[0].size();i++){
        if(board[row][i] == num)
            return false;
    }   

    //col ka check
    for(int j=0;j<board.size();j++){
        if(board[j][col] == num)
            return false;
    }

    //sub matrix ka check
    for(int i=0;i<sqrt(board.size());i++){

    }
}

void solve(){
    int n =4;
    int N =4;
    int M =4;
    vector<vector<bool>> board(n, vector<bool>(n,false));

    // rowA.resize(N,false);
    // colA.resize(N,false);
    // diag.resize(N,false);
    // adiag.resize(N,false);
    // in java use -> rowA = new boolean[]; -> and just declare the static array above.
   // cout<<nqueens(board,4,"",-1)<<endl;
   cout<<nqueens_03(N,M,4,"",-1)<<endl;
   cout<<nqueens_02(board,4,"",-1)<<endl;

}
int main(){
    solve();
    return 0;
}