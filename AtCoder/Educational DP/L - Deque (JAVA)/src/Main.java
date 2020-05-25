import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = Integer.parseInt(in.nextLine());
        long[] arr = new long[N];

        StringTokenizer s = new StringTokenizer(in.nextLine());
        for (int i = 0; i < N; ++i) {
            arr[i] = Integer.parseInt(s.nextToken());
        }

        // Stores score relative to Taro
        long[][] dp = new long[N][N];

        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) dp[i][j] = -1;

        for (int i = 0; i < N; ++i) {
            dp[N-1][i] = arr[i];
        }

        for (int turn = N-2; turn >= 0; --turn) {
            int length = N - turn; // # remaining pieces
            for (int leftMost = 0; leftMost + length <= N; ++leftMost) {

                int l = leftMost;
                int r = leftMost + length - 1;

                dp[turn][leftMost] = Math.max(
                        arr[r] - dp[turn+1][leftMost],
                        arr[l] - dp[turn+1][leftMost+1]);
            }
        }

        System.out.println(dp[0][0]);

    }
}
