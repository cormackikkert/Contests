/*
ID: cormac.1
LANG: JAVA
TASK: stamps
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class stamps {
    public static void main(String[] args) throws IOException {
        int maxNum = 2000000;
        BufferedReader fin = new BufferedReader(new FileReader("stamps.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("stamps.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int K = Integer.parseInt(s.nextToken());
        int N = Integer.parseInt(s.nextToken());

        int dp[] = new int[maxNum];
        int[] stampValues = new int[N];

        int i = 0;
        while (true) {
            String line = fin.readLine();
            if (line == null) break;
            s = new StringTokenizer(line);
            while (s.hasMoreTokens()) {
                stampValues[i] = Integer.parseInt(s.nextToken());
                ++i;
            }
        }

        for (int k = 0; k < maxNum; ++k) dp[k] = Integer.MAX_VALUE;
        dp[0] = 0;

        for (int target = 1; target < maxNum; ++target) {
            for (int stamp : stampValues) {
                if (stamp > target) continue;
                dp[target] = Math.min(dp[target - stamp] + 1, dp[target]);
            }
            if (dp[target] > K) {
                fout.println(target - 1);
                break;
            }
        }

        fout.close();
    }
}
