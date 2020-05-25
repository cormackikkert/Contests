/*
ID: cormac.1
LANG: JAVA
TASK: hamming
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class hamming {
    static int N;
    static int B;
    static int D;

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("hamming.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("hamming.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        N = Integer.parseInt(s.nextToken());
        B = Integer.parseInt(s.nextToken());
        D = Integer.parseInt(s.nextToken());

        fout.println(search(new int[] {}));
        fout.close();
    }

    public static String search(int[] set) {
        if (set.length == N) {
            String a = "";
            for (int i = 0; i < set.length; i++) {

                if (i > 0 && i % 10 == 0) a += "\n";
                a += set[i];
                if (i != set.length - 1 && ((i + 1) % 10 != 0)) a += " ";
            }
            return a;
        }
        for (int i = 0; i < Math.pow(2, B); i++) {
            if (set.length >= 1 && i <= set[set.length - 1]) continue;
            boolean shouldAdd = true;
            for (int include : set)
                if (hammingDist(i, include) < D) {
                    shouldAdd = false;
                    break;
                }
            if (shouldAdd) {
                int[] newSet = new int[set.length + 1];
                for (int j = 0; j < set.length; j++)
                    newSet[j] = set[j];
                newSet[set.length] = i;

                String ans = search(newSet);
                if (ans != null) return ans;
            }
        }
        return null;
    }

    public static int hammingDist(int a, int b) {
        int c = a ^ b;
        int t = 0;
        while (c > 0) {
            if (c % 2 == 1) t++;
            c /= 2;
        }
        return t;
    }
}
