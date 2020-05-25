/*
ID: cormac.1
LANG: JAVA
TASK: inflate
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class inflate {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("inflate.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("inflate.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int M = Integer.parseInt(s.nextToken());
        int N = Integer.parseInt(s.nextToken());

        int[] points = new int[N];
        int[] minutes = new int[N];

        for (int i = 0; i < N; ++i) {
            s = new StringTokenizer(fin.readLine());

            points[i] = Integer.parseInt(s.nextToken());
            minutes[i] = Integer.parseInt(s.nextToken());
        }

        int[] dp = new int[M+1];
        dp[0] = 0;

        for (int t = 1; t <= M; t++) {
            dp[t] = dp[t-1];
            for (int i = 0; i < N; ++i) {
                if (minutes[i] > t) continue;
                dp[t] = Math.max(dp[t], dp[t - minutes[i]] + points[i]);
            }
        }

        fout.println(dp[M]);
        fout.close();
    }
}
