import java.util.*;
public class Code{

    public static void main(String[] args) {
        long start  = System.currentTimeMillis();
        // String str = sieveOfEratosthenes(200000);
        // int n =sieveOfEratosthenes(200000);
        // System.out.println(n);
        String string = sieveOfEratosthenes(200000);
        int i = 3;
        //starting index -> end index(si + 6)
        String ros = string.substring(i,i+5);
        System.out.println(ros);
        long end  = System.currentTimeMillis();
        System.out.println(end-start);
    }

    public static String sieveOfEratosthenes(int n){
        
        String str = "";
        int count = 0;
        boolean prime[] = new boolean[n+1]; 
        for(int i=0; i<n; i++){
            prime[i] = true;
        }
        
        for(int p=2; p*p<=n; p++){
            if(prime[p]== true){
                
                for(int i=p*p; i<=n; i+=p){
                    prime[i] = false;
                }
            }
        }
        
        for(int i=2; i<=n; i++){
            if(prime[i] == true){
                str += i;
                count++;
            }
        }
        
        return str;
        // return count;
    }
}
// public static void main(String[] args) {
        
//     Scanner s = new Scanner(System.in);
//     int n = s.nextInt();
    
//     List<Integer> ans = new ArrayList<>();
//     dfs(n, 0, ans);
//     for(Integer e: ans){
//         System.out.println(e);
//     }
// }

// public static void dfs(int n, int cidx, List<Integer> list){
    
//     for(int i=0;i<=9;i++){
        
//         if(cidx+i<n && (cidx+i)!=0){
//             list.add(cidx+i);
            
//             if((cidx+i)*10 < n){
//                 dfs(n,(cidx+i)*10,list);
//             }
//         }
//     }
// }

// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// void two_spheres_(vector<vector<int>> &sacc, vector<vector<int>> &scord, int sx,int sy,int sz, int dx,int dy,int dz){
    
//     if(sx==dx && sy==dy && sz==dz){
//         cout<<"YES"<<endl;
//         return;
//     }
    
//     int a1x = sacc[0][0];
//     int a1y = sacc[0][1];
//     int a1z = sacc[0][2];
//     int a2x = sacc[1][0];
//     int a2y = sacc[1][1];
//     int a2z = sacc[1][2];
    
//     if((a1x <0 || a1y<0 || a1z<0)&&(a2x >0 || a2y>0 || a2z>0)){
//         cout<<"NO"<<endl;
//     }
    
//     if((a1x>0 &&a2x>0) || (a1x<0 && a2x<0))
//         two_spheres_(sacc, scord, sx+a1x, sy, sz, dx+a2x, dy, dz);
    
//     if((a1y>0 &&a2y>0) || (a1y<0 && a2y<0))
//         two_spheres_(sacc, scord, sx, sy+a1y, sz,dx, dy+a2y, dz);
    
//     if((a1z>0 &&a2z>0) || (a1z<0 && a2z<0))
//         two_spheres_(sacc, scord, sx, sy, sz+a1z, dx, dy, dz+a2z);
    
// //     if((a1z>0 &&a2z>0) || (a1z<0 && a2z<0))
// //         two_spheres_(sacc, scord, sx+a1x,, sy, sz+a1z, dx+a2x, dy, dz+a2z);
    
// //     if((a1z>0 &&a2z>0) || (a1z<0 && a2z<0))
// //         two_spheres_(sacc, scord, sx, sy, sz+a1z, dx, dy, dz+a2z);
    
// //     if((a1z>0 &&a2z>0) || (a1z<0 && a2z<0))
// //         two_spheres_(sacc, scord, sx, sy, sz+a1z, dx, dy, dz+a2z);
    
    
//     return;
// }

// void two_spheres(){
//     int t;
//     cin >> t;
    
//     while(t-- >0){
//         int r1, r2;
//         cin >> r1 >> r2;
        
//         int x, y, z;
//         int ai,aj,az;
//         vector<vector<int>> sacc;
//         vector<vector<int>> scord;
//         vector<int> cord;
//         vector<int> acc;
        
//         for(int i=0; i<2; i++){
//             cin >> x >> y >> z;
//             cin >> ai >> aj >> az;
//             cord = {x,y,z};
//             acc = {ai,aj,az};
            
//             scord.push_back(cord);
//             sacc.push_back(acc);
//         }
        
//         int sx = scord[0][0];
//         int sy = scord[0][1];
//         int sz = scord[0][2];
//         int dx = scord[1][0];
//         int dy = scord[1][1];
//         int dz = scord[1][2];
//         two_spheres_(sacc,scord,sx,sy,sz,dx,dy,dz);
//     }
// }

// auto SpeedUp = [](){
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 0;
// }();

// int main() {
//     two_spheres();
//     return 0;
// }

// import java.io.*;
// import java.util.*;

// public class Solution {

//     public static void main(String[] args) {
//         Scanner s = new Scanner(System.in);
//         int t = s.nextInt();
        
//         while(t--){
//             int n = s.nextInt();
//             int[][] arr = new int[n][5];
//             for(int i=0; i<n; i++){
//                 for(int j=0; j<5; j++){
//                     arr[i][j] = s.nextInt();
//                 }
//             }
            
//             int ans = maxEnergy(arr);
//         }
//     }
    
//     public static int maxEnergy(int[][] arr){
        
//         int n = arr.length-1;
//         int m = arr[0].length-1;
        
//         int[][] board = new int[n+1][5];
//         int midx = n+1;
//         int midy = 3;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 board[i][j] = arr[i][j];
//             }
//         }
        
//         int maxe = dfs(board, midx, midy,0);
        
//     }
    
//     static int max = 0;
//     public void dfs(int[][] board, int midx, int midy, int maxe){
        
//         if(midx == 0){
//             if(maxe > max){
//                 max = maxe;
//                 return;
//             }
//             return;
//         }
        
//         if(midx-1>=0){
//             dfs(board, midx-1, midy, maxe + board[i])
//         }
//         if(midx-1>=0 && midy-1>=0){
            
//         }
//         if(midx-1>=0 && midy+1<5){
            
//         }
//     }
    
//     public static void detonate(int[][] board){
        
//     }
// }