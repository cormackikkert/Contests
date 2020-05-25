/*
ID: cormac.1
TASK: concom
LANG: JAVA
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class concom {
    static boolean[][] control = new boolean[100][100];
    static int[][] percent = new int[100][100];

    static int[] sum = new int[100];
    static boolean[] done = new boolean[100];

    static int current;

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("concom.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("concom.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int n = Integer.parseInt(s.nextToken());


        for (int t = 0; t < n; ++t) {
            s = new StringTokenizer(fin.readLine());
            int i = Integer.parseInt(s.nextToken()) - 1;
            int j = Integer.parseInt(s.nextToken()) - 1;
            int p = Integer.parseInt(s.nextToken());

            percent[i][j] = p;
        }
        for (int node = 0; node < 100; ++node) {
            current = node;
            sum = new int[100];
            done = new boolean[100];
            done[current] = true;
            search(node);
        }

        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                if (i == j) continue;
                if (control[i][j]) fout.println((i+1) + " " + (j+1));
            }
        }
        fout.close();
    }

    public static void search(int node) {
        for (int i = 0; i < 100; ++i) {
            sum[i] += percent[node][i];

            if (sum[i] > 50 && !done[i]) {
                control[current][i] = true;
                done[i] = true;
                search(i);
            }
        }
    }
}
