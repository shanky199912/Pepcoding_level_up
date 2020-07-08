import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

class l001 {
    static Scanner sc;
    static long ll = 1000000007;

    public static void main(String[] args) {

        set();
    }

    public static void display(int[] arr) {
        for (int ele : arr)
            System.out.print(ele + " ");
        System.out.println();
    }

    public static void display2D(int[][] arr) {
        for (int[] ar : arr)
            display(ar);
        System.out.println();
    }

    public static void set() {
        // friendsPairSet();
        goldmineSet();
    }

    // * GFG https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0
    // ======================
    public static void friendsPairSet() {
        // code
        sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            long[] dp = new long[n + 1];

            long ans = friendsPairing(n, dp);
            ans = ans % ll;
            System.out.println(ans);
        }

        sc.close();
    }

    public static long friendsPairing(int n, long[] dp) {

        if (n == 0 || n == 1) {
            return dp[n] = 1;
        }

        if (dp[n] != 0)
            return dp[n];

        long single = friendsPairing(n - 1, dp) % ll;
        long pair = (friendsPairing(n - 2, dp) * (n - 1)) % ll;

        return dp[n] = (single + pair) % ll;
    }

    public static long friendsPairingDP(int N, long[] dp) {

        for (int n = 0; n < N; n++) {

            if (n == 0 || n == 1) {
                dp[n] = 1;
                continue;
            }

            long single = dp[n - 1] % ll;
            long pair = (dp[n - 2] * (n - 1)) % ll;

            dp[n] = (single + pair) % ll;
        }

        return dp[N];
    }

    // * Leetcode 64 - MINIMUM PATH SUM
    // ====================================================
    int[][] dir = { { 0, 1 }, { 1, 0 } };

    public int minPathSum(int[][] grid) {
        // int[][] dp = new int[grid.length][grid[0].length];
        return minPathSum_dp(grid);
    }

    // Recursive solution with memoization.
    public int minPathSum_(int[][] grid, int r, int c, int[][] dp) {

        if (r == grid.length - 1 && c == grid[0].length - 1) {
            return dp[r][c] = grid[r][c];
        }

        if (dp[r][c] != 0)
            return dp[r][c];

        int minSum = (int) 1e8;
        for (int d = 0; d < 2; d++) {
            int x = r + dir[d][0];
            int y = c + dir[d][1];

            if (x >= 0 && y >= 0 && x < grid.length && y < grid[0].length) {
                minSum = Math.min(minSum, minPathSum_(grid, x, y, dp));
            }
        }

        return dp[r][c] = minSum + grid[r][c];
    }

    // DP solution ->Tabulation : Converted memoization to tabulation.
    public int minPathSum_dp(int[][] grid) {

        int n = grid.length;
        int m = grid[0].length;
        int[][] dp = new int[n][m];

        for (int r = n - 1; r >= 0; r--) {
            for (int c = m - 1; c >= 0; c--) {

                if (r == grid.length - 1 && c == grid[0].length - 1) {
                    dp[r][c] = grid[r][c];
                    continue;
                }

                int minSum = (int) 1e8;
                for (int d = 0; d < 2; d++) {
                    int x = r + dir[d][0];
                    int y = c + dir[d][1];

                    if (x >= 0 && y >= 0 && x < grid.length && y < grid[0].length) {
                        minSum = Math.min(minSum, dp[x][y]);
                    }
                }

                dp[r][c] = minSum + grid[r][c];
            }
        }

        return dp[0][0];
    }

    // * https://practice.geeksforgeeks.org/problems/gold-mine-problem/0

    public static void goldmineSet() {
        int[][] grid = { { 1, 3, 1, 5 }, { 2, 2, 4, 1 }, { 5, 0, 2, 3 }, { 0, 6, 1, 2 } };
        int n = grid.length;
        int m = grid[0].length;

        int[][] dp = new int[n][m];
        int maxCoin = (int) -1e8;
        for (int i = 0; i < n; i++) {
            maxCoin = Math.max(maxCoin, goldmine(grid, i, 0, dp));
        }

        System.out.println(maxCoin);
        display2D(dp);

        System.out.println(goldmineDP(grid));
        display2D(dp);
    }

    static int[][] dirG = { { 0, 1 }, { 1, 1 }, { -1, 1 } };

    public static int goldmine(int[][] grid, int r, int c, int[][] dp) {

        if (c == grid[0].length - 1) {
            return dp[r][c] = grid[r][c];
        }

        if (dp[r][c] != 0)
            return dp[r][c];

        int maxCoin = (int) -1e8;
        for (int d = 0; d < 3; d++) {
            int x = r + dirG[d][0];
            int y = c + dirG[d][1];

            if (x >= 0 && y >= 0 && x < grid.length && y < grid[0].length) {
                maxCoin = Math.max(maxCoin, goldmine(grid, x, y, dp));
            }
        }

        return dp[r][c] = maxCoin + grid[r][c];
    }

    public static int goldmineDP(int[][] grid) {

        int n = grid.length, m = grid[0].length;
        int[][] dp = new int[n][m];

        for (int c = m - 1; c >= 0; c--) {

            for (int r = 0; r < n; r++) {

                if (c == m - 1) {
                    dp[r][c] = grid[r][c];
                    continue;
                }

                int maxCoin = (int) -1e8;
                for (int d = 0; d < 3; d++) {
                    int x = r + dirG[d][0];
                    int y = c + dirG[d][1];

                    if (x >= 0 && y >= 0 && x < n && y < m) {
                        maxCoin = Math.max(maxCoin, goldmine(grid, x, y, dp));
                    }
                }

                dp[r][c] = maxCoin + grid[r][c];
            }
        }

        int maxAns = (int) -1e8;
        for (int i = 0; i < n; i++) {
            maxAns = Math.max(dp[i][0], maxAns);
        }

        return maxAns;
    }
}