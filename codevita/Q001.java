import java.util.Scanner;
public class Q001{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        char[][] arr = new char[N][N];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                arr[i][j] = sc.next().charAt(0);
            }
        }

        moveAll_C_ToCorrectPos(arr,N);

        int ans1 = findLargetSquareMatrix(arr, N); //original
        rotateMatrix(arr); //CW1
        int ans2 = findLargetSquareMatrix(arr,N); //RIGHT - BOTTOM
        rotateMatrix(arr);//CW2
        int ans3 = findLargetSquareMatrix(arr,N); //tOP - BOTTOM
        rotateMatrix(arr);//CW3
        int ans4 = findLargetSquareMatrix(arr,N); //LEFT - BOTTOM
        
        int res = Math.max(ans1, Math.max(ans2, Math.max(ans3, ans4)));
        System.out.println(res);


        // char[][] mat = {{'a','b','c','d'}, {'e','f','g','h'}, {'i','j','k','l'}, {'m','n','o','p'}};
        // display2D(mat);
        // rotateMatrix(mat);
        // display2D(mat);
    }

    public static int findLargetSquareMatrix(char[][] arr, int n){

        char[][] newarr = new char[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                newarr[i][j] = arr[i][j];
            }
        }

        for(int i =0; i<n; i++){
            for(int j=0; j<n; j++){
                if(newarr[i][j] == 'C')
                    newarr[i][j] = '0';
                else{
                    newarr[i][j] = '1';
                }
            }
        }

        int[][]  dp = new int[n][n];
        for(int j = 0; j<n; j++){
            if(newarr[n-1][j] == '1')
                dp[n-1][j] = 1;
        }

        for(int i = 0; i<n; i++){
            if(newarr[i][n-1] == '1')
                dp[i][n-1] = 1;
        }

        for(int i=n-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                if(newarr[i][j] == '1'){
                    dp[i][j] = Math.min(dp[i+1][j], Math.min(dp[i][j+1], dp[i+1][j+1])) + 1;
                }
            }
        }

        return dp[0][0];
    }

    public static void moveAll_C_ToCorrectPos(char[][] arr, int n){

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                if(i-1 >=0 && arr[i-1][j] == 'C'){
                    while(i < n && (arr[i][j] == '-' || arr[i][j] == 'D')){
                        arr[i-1][j] = '-';
                        arr[i][j] = 'C';
                        i++;
                    }
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(arr[i][j] == 'D'){
        //             arr[i][j] = '-';
        //         }
        //     }
        // }

        display2D(arr);
    }

    public static void display(char[] arr){
    
        for (char ele : arr)
            System.out.print(ele + " ");
        System.out.println();
    }

    public static void display2D(char[][] arr){
        for (char[] ar : arr)
            display(ar);
        System.out.println();
    }

    public static void rotateMatrix(char[][] arr){

        for(int gap=0; gap < arr.length; gap++){
            for(int si=0, ei=gap; ei < arr.length; si++, ei++){

                char temp = arr[si][ei];
                arr[si][ei] = arr[ei][si];
                arr[ei][si] = temp;
            }
        }
        
        for(int i=0; i<arr.length; i++){
            int li = 0;
            int ri = arr[i].length-1;

            while(li < ri){
                char temp = arr[i][li];
                arr[i][li] = arr[i][ri];
                arr[i][ri] = temp;

                li++;
                ri--;
            }
        }

    }
}