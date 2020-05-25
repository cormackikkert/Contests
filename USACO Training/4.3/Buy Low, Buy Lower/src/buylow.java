/*
ID: cormac.1
LANG: JAVA
TASK: buylow
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class buylow {
    static Set<String> answers = new HashSet<>();
    static int N;
    static int[] nums;
    static int[] cur;
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("buylow.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("buylow.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        N = Integer.parseInt(s.nextToken());
        nums = new int[N];
        int index = 0;
        while (true) {
            try {
                s = new StringTokenizer(fin.readLine());
            } catch (Exception e) { break;}
            while (s.hasMoreTokens()) {
                nums[index++] = Integer.parseInt(s.nextToken());
            }
        }

        int[] dp = new int[N];
        for (int i = 0; i < N; ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] > nums[i]) dp[i] = Math.max(dp[i], 1 + dp[j]);
            }
        }

        int max = Integer.MIN_VALUE;
        for (int i = 0; i < N; ++i) max = Integer.max(max, dp[i]);

        cur = new int[max + 1];

        getSequences(dp, max + 1, N);

        fout.println(max + " " + answers.size());
        fout.close();
    }

    public static void getSequences(int[] dp, int max, int index) {
        if (max == 1) {
            cur[0] = nums[index];
            answers.add(Arrays.toString(cur));
            return;
        }
        for (int i = 0; i < index; ++i) {
            if (dp[i] == max - 1 && (index == N || nums[i] > nums[index])) {
                cur[max - 1] = nums[i];
                getSequences(dp, max - 1, i);
            }
        }
    }


}
