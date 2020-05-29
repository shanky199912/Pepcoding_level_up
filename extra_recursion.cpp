#include<iostream>
#include<vector>

using namespace std;

//leetcode - lexicographic numbers
void laxcigraphicalOrder(int st, int end)
{
    //here we need to print the end also , sometimes the questions says not to print end, in that case
    // make the changes accordingly.
    cout << st << endl;
    for (int i = 0; i < 10; i++)
        if (st * 10 + i <= end)
            laxcigraphicalOrder(st * 10 + i, end);
        else
            break;

//for printing the rest of the numbers < 10 , like after 1 is printing all its numbers, we come here do the
//same work for 2,3,....9
    if (st + 1 < 10 && st + 1 <= end)
        laxcigraphicalOrder(st + 1, end);
}

//leetcode
int numTilePossibilities(string &str)
{
    if (str.length() == 0)
    {
        return 0;
    }

    int count = 0;
    // vector<bool> vis(26, false);
    int vis = 0;
    for (int i = 0; i < str.length(); i++)
    {
        // int chIdx = str[i] - 'A';
        int mask = 1 << (str[i] - 'A');

        // if (vis[chIdx] == false)
        if ((vis & mask) == 0)
        {
            vis ^= mask;
            string nstr = str.substr(0, i) + str.substr(i + 1);
            count += numTilePossibilities(nstr) + 1;
        }
    }
    return count;
}


//  List<String> res;
//     public List<String> generateParenthesis(int n) {
//         res=new ArrayList<>();
//         generateParenthesis("",0,0,n);
//         return res;
//     }
//
//     public void generateParenthesis(String ans,int OB,int CB,int n){
//         if(OB+CB==2*n) {
//             res.add(ans);
//             return;
//         }
//
//         if(OB<n)
//           generateParenthesis(ans+"(", OB+1,CB,n);
//         if(CB<OB)
//           generateParenthesis(ans+")", OB,CB+1,n);
//
//     }

//Samsung favourite question- Aeroplane Game 

int main(){
    return 0;
}