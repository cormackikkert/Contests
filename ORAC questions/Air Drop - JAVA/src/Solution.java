import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
    static int N;
    static int[] drops;

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("dropin.txt"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("dropout.txt")));

        N = Integer.parseInt(fin.readLine());

        drops = new int[N];

        for (int i = 0; i < N; ++i) {
            drops[i] = Integer.parseInt(fin.readLine());
        }


        int[][] dp = new int[N][N];

        int highest = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= i; ++j) {
                int jump = drops[i] - drops[j];
                int last = getIndex(drops[j] - jump, 0, N-1);

                if (last != -1) {
                    dp[i][j] = 1 + dp[j][last];
                } else {
                    dp[i][j] = 1;
                }
                highest = Math.max(highest, dp[i][j]);
            }
        }

        fout.println(highest + ((N == 1) ? 0 : 1));
        fout.close();

    }

    static int getIndex(int item, int lo, int hi) {
        if (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (drops[mid] == item) return mid;
            if (drops[mid] < item) return getIndex(item, mid+1, hi);
            if (drops[mid] > item) return getIndex(item, lo, mid -1);
        }
        return -1;
    }
}
