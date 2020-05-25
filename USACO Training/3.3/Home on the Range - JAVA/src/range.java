/*
ID: cormac.1
LANG: JAVA
TASK: range
 */

import java.io.*;
import java.lang.*;
import java.util.*;

public class range {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("range.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("range.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int N = Integer.parseInt(s.nextToken());
        int land[][] = new int[N][N];

        for (int i = 0; i < N; ++i) {
            int j = 0;
            for (char c : fin.readLine().toCharArray()) {
                land[i][j] = (c == '1') ? 1 : 0;
                ++j;
            }
        }

        int landSum[][] = new int[N+1][N+1];

        for (int y = 1; y <= N; ++y) {
            for (int x = 1; x <= N; ++x) {
                landSum[y][x] = land[y-1][x-1] + landSum[y-1][x] + landSum[y][x-1] - landSum[y-1][x-1];
            }
        }

        for (int squareSize = 2; squareSize <= N; ++squareSize) {
            int freq = 0;
            for (int sy = 1; sy + squareSize - 1 <= N; ++sy) {
                for (int sx = 1; sx + squareSize - 1 <= N; ++sx) {
                    int area = landSum[sy + squareSize - 1][sx + squareSize - 1] -
                            landSum[sy-1][sx + squareSize - 1] -
                            landSum[sy + squareSize - 1][sx-1] +
                            landSum[sy-1][sx-1];
                    if (area == squareSize * squareSize) ++freq;
                }
            }
            if (freq != 0) {
                fout.println(squareSize + " " + freq);
            }
        }

        fout.close();
    }
}
