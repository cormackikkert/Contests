/*
ID: cormac.1
LANG: JAVA
TASK: nocows
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class nocows {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("nocows.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("nocows.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int N = Integer.parseInt(s.nextToken());
        int K = Integer.parseInt(s.nextToken());

        int[][] dp = new int[K+1][N+1];
        dp[1][1] = 1;
        dp[2][3] = 1;
        for (int depth = 3; depth <= K; ++depth) {
            for (int nodes = 1; nodes <= N; nodes += 2) {
                for (int rightTreeNodes = 1; rightTreeNodes < nodes; ++rightTreeNodes) {
                    for (int rightTreeHeight = 1; rightTreeHeight < depth; ++rightTreeHeight) {
                        if (rightTreeHeight == depth - 1)
                            dp[depth][nodes] += dp[depth - 1][nodes - rightTreeNodes - 1] * dp[rightTreeHeight][rightTreeNodes];
                        else
                            dp[depth][nodes] += 2 * dp[depth - 1][nodes - rightTreeNodes - 1] * dp[rightTreeHeight][rightTreeNodes];
                        dp[depth][nodes] %= 9901;
                    }
                }
            }
        }
        fout.println(dp[K][N]);
        fout.close();
    }
}
