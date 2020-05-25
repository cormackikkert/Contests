/*
ID: cormac.1
TASK: cowtour
LANG: JAVA
 */

import java.io.*;
import java.lang.*;
import java.util.*;

public class cowtour {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("cowtour.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("cowtour.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int N = Integer.parseInt(s.nextToken());
        int[] posx = new int[N];
        int[] posy = new int[N];
        for (int i = 0; i < N; ++i) {
            s = new StringTokenizer(fin.readLine());
            posx[i] = Integer.parseInt(s.nextToken());
            posy[i] = Integer.parseInt(s.nextToken());
        }

        double[][] adjMatrix = new double[N][N];
        for (int i = 0; i < N; ++i) {
            char[] values = fin.readLine().toCharArray();
            for (int j = 0; j < N; ++j) {
                if (values[j] == '1') {
                    adjMatrix[i][j] = Math.sqrt(Math.pow(posx[i] - posx[j], 2) + Math.pow(posy[i] - posy[j], 2));
                } else {
                    adjMatrix[i][j] = (i == j) ? 0 : Double.POSITIVE_INFINITY;
                }
            }
        }

        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    adjMatrix[i][j] = Math.min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }

        double minCost = Double.POSITIVE_INFINITY;
        double diameter = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {

                if (adjMatrix[i][j] != Double.POSITIVE_INFINITY) {
                    diameter = Math.max(diameter, adjMatrix[i][j]);
                    continue;
                }

                double L = 0;
                double R = 0;

                for (int p = 0; p < N; ++p) {
                    if (adjMatrix[p][i] != Double.POSITIVE_INFINITY) {
                        R = Math.max(R, adjMatrix[p][i]);
                    }
                    if (adjMatrix[p][j] != Double.POSITIVE_INFINITY){
                        L = Math.max(L, adjMatrix[p][j]);
                    }
                }
                minCost = Math.min(minCost, L + R + Math.sqrt(Math.pow(posx[i] - posx[j], 2) + Math.pow(posy[i] - posy[j], 2)));

            }
        }
        fout.printf("%.6f", Math.max(minCost, diameter));
        fout.println();

        fout.close();
    }
}
