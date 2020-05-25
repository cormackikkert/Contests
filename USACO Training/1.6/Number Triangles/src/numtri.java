/*
ID: cormac.1
LANG: JAVA
TASK: numtri
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class numtri {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("numtri.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("numtri.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int R = Integer.parseInt(s.nextToken());

        int[][] grid = new int[R][R];
        int[][] dp = new int[R][R];

        for (int i = 0; i < R; i++) {
            s = new StringTokenizer(fin.readLine());
            for (int j = 0; j <= i; j++) {
                grid[i][j] = Integer.parseInt(s.nextToken());
                if (i == R - 1) dp[i][j] = grid[i][j];
            }
        }

        for (int r = R - 2; r >= 0; r--) {
            for (int j = 0; j <= r; j++) {
                dp[r][j] = grid[r][j] + Math.max(dp[r+1][j], dp[r+1][j+1]);
            }
        }

        fout.println(dp[0][0]);
        fout.close();

    }
}
