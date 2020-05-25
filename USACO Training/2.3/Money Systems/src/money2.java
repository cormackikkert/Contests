/*
ID: cormac.1
LANG: JAVA
TASK: money
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class money2 {
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

        long [] dp = new long [N+1];
        for (int v = 0; v < V; ++v) {
            for (int n = 1; n <= N; ++n) {
                for (int rep = 1; n + rep * coins[v] <= N; ++rep) {
                    dp[n+rep*coins[v]] += dp[n];
                }
            }
        }

        fout.println(dp[N]);
        fout.close();

    }
}
