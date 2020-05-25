/*
ID: cormac.1
LANG: JAVA
TASK: subset
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class subset {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("subset.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("subset.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int N = Integer.parseInt(s.nextToken());

        int target = (N * (N + 1)) / 4;

        int[][] dp = new int[target + 1][N + 1];

        for (int curSum = 1; curSum <= target; curSum++) {
            if (curSum <= N) dp[curSum][curSum] = 1;
            for (int other = 1; other <= N && curSum - other >= 0; other++) {
                for (int j = other + 1; j <= N; j++) {
                    dp[curSum][other] += dp[curSum - other][j];
                }
            }
        }
        long total = 0;
        for (int i = 1; i <= N; i++) {
            total += dp[target][i];
        }
        if (target * 4 / N != N+1)
            fout.println(0);
        else
            fout.println(total / 2);
        fout.close();
    }
}
