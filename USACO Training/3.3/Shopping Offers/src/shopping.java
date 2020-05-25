/*
ID: cormac.1
LANG: JAVA
TASK: shopping
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class shopping {
    static int[][][][][] dp;
    static int[][] offerObjects;
    static int[] offerPrice;
    static int[] regularCost;
    static int[] idToIndex = new int[1001];
    static int[] products = new int[5];

    static int S;

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("shopping.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("shopping.out")));

        S = Integer.parseInt(fin.readLine());
        offerObjects = new int[S][1001];
        offerPrice = new int[S];

        for (int i = 0; i < S; ++i) {
            StringTokenizer s = new StringTokenizer(fin.readLine());
            int n = Integer.parseInt(s.nextToken());
            for (int j = 0; j < n; ++j) {
                int c = Integer.parseInt(s.nextToken());
                int k = Integer.parseInt(s.nextToken());
                offerObjects[i][c] = k;
            }
            offerPrice[i] = Integer.parseInt(s.nextToken());
        }

        int B = Integer.parseInt(fin.readLine());
        regularCost = new int[5];

        for (int i = 0; i <= 1000; ++i) idToIndex[i] = -1;

        products = new int[5];

        for (int i = 0; i < B; ++i) {
            StringTokenizer s = new StringTokenizer(fin.readLine());
            int c = Integer.parseInt(s.nextToken());
            int k = Integer.parseInt(s.nextToken());
            int p = Integer.parseInt(s.nextToken());

            products[i] = k;
            regularCost[i] = p;
            idToIndex[c] = i;
        }

        dp = new int[6][6][6][6][6];

        for (int i1 = 0; i1 <= 5; ++i1)
            for (int i2 = 0; i2 <= 5; ++i2)
                for (int i3 = 0; i3 <= 5; ++ i3)
                    for (int i4 = 0; i4 <= 5; ++i4)
                        for (int i5 = 0; i5 <= 5; ++i5)
                            dp[i1][i2][i3][i4][i5] = -1;

        dp[0][0][0][0][0] = 0;

        fout.println(calcCost(products));
        fout.close();
    }


    static public int calcCost(int[] p) {
        if (dp[p[0]][p[1]][p[2]][p[3]][p[4]] != -1) {
            return dp[p[0]][p[1]][p[2]][p[3]][p[4]];
        }

        int totalCost = Integer.MAX_VALUE;

        // Remove one element
        for (int i = 0; i < 5; ++i) {
            if (p[i] == 0) continue;
            int[] newP = p.clone();
            newP[i] -= 1;

            totalCost = Math.min(totalCost, regularCost[i] + calcCost(newP));
        }

        // Use groups
        for (int offer = 0; offer < S; ++offer) {

            int[] numObjects = p.clone();
            int[] offerObject = offerObjects[offer];
            int price = offerPrice[offer];

            useObject : {

                for (int i = 0; i <= 1000; ++i) {
                    if (idToIndex[i] == -1 && offerObject[i] != 0) break useObject;
                    if (idToIndex[i] == -1) continue;

                    numObjects[idToIndex[i]] -= offerObject[i];

                    if (numObjects[idToIndex[i]] < 0) break useObject;
                }
                totalCost = Math.min(totalCost, price + calcCost(numObjects));
            }
        }

        dp[p[0]][p[1]][p[2]][p[3]][p[4]] = totalCost;
        return totalCost;
    }
}
