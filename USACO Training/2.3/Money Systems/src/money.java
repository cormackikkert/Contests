/*
ID: cormac.1
LANG: JAVA
TASK: money
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class money {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("money.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("money.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int V = Integer.parseInt(s.nextToken());
        int N = Integer.parseInt(s.nextToken());

        int[] coins = new int[V];

        int t = 0;
        s = new StringTokenizer(fin.readLine());
        while (true) {
            if (t == V) break;
            if (!s.hasMoreTokens())
                s = new StringTokenizer(fin.readLine());
            coins[t] = Integer.parseInt(s.nextToken());
            t++;
        }

        long [][] dp = new long [V][N+1];
        for (int n = 1; n <= N; ++n) {
            for (int j = 0; j < V; ++j) {
                int c = coins[j];
                if (n - c < 0) continue;
                if (n == c) dp[j][n] = 1;
                    for (int o = 0; o <= j; ++o) {
                        dp[j][n] += dp[o][n - c];
                    }
            }
        }
        long total = 0;
        for (int i = 0; i < V; ++i) {
            total += dp[i][N];
        }

        fout.println(total);
        fout.close();

    }
}
