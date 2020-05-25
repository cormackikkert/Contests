import java.util.Scanner;

import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static double[][][] dp;
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        N = Integer.parseInt(s.nextLine());

        int[] count = new int[3];
        StringTokenizer st = new StringTokenizer(s.nextLine());
        for (int i =0 ; i < N; ++i) {
            int dish = Integer.parseInt(st.nextToken()) - 1;
            count[dish]++;
        }

        dp = new double[301][301][301];

        for (int i = 0; i <= 300; ++i) {
            for (int j = 0; j <= 300; ++j) {
                for (int k = 0; k <= 300; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }

        dp[0][0][0] = 0;

        System.out.println(getExpectedValue(count[2], count[1], count[0]));
    }

    static double getExpectedValue(int a, int b, int c) {
        if (dp[a][b][c] != -1) {
            return dp[a][b][c];
        }

        double expected = 0;
        if (a != 0)
            expected += a * getExpectedValue(a-1, b+1, c);
        if (b != 0)
            expected += b * getExpectedValue(a, b-1, c+1);
        if (c != 0)
            expected += c * getExpectedValue(a, b, c-1);

        double score = N/((double)(a + b + c)) + expected/(double)(a + b + c);
        dp[a][b][c] = score;
        return score;

    }
}
