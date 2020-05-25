/*
ID: cormac.1
LANG: JAVA
TASK: preface
 */

import java.io.*;
import java.util.*;
import java.lang.*;

/*
I: 1    L: 50    M: 1000
V: 5    C: 100
X: 10   D: 500
 */
public class preface {
    static int I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000;

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("preface.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new PrintWriter("preface.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int N = Integer.parseInt(s.nextToken());

        int[] occurance = new int[7];
        for (int i = 1; i <= N; i++) {
            // System.out.println(i + ", " + getRomanNum(i));
            for (char x : getRomanNum(i).toCharArray()) {
                switch (x) {
                    case 'I': occurance[0]++; break;
                    case 'V': occurance[1]++; break;
                    case 'X': occurance[2]++; break;
                    case 'L': occurance[3]++; break;
                    case 'C': occurance[4]++; break;
                    case 'D': occurance[5]++; break;
                    case 'M': occurance[6]++; break;
                }
            }
        }

        for (int i = 0; i < 7; i++) {
            if (occurance[i] == 0) continue;
            switch (i) {
                case 0: fout.print("I "); break;
                case 1: fout.print("V "); break;
                case 2: fout.print("X "); break;
                case 3: fout.print("L "); break;
                case 4: fout.print("C "); break;
                case 5: fout.print("D "); break;
                case 6: fout.print("M "); break;
            }
            fout.println(occurance[i]);
        }
        fout.close();
    }

    public static String getRomanNum(int N) {
        if (N >= M)
            return "M" + getRomanNum(N - M);
        else if (N >= D)
            if (N >= M - C)
                return "CM" + getRomanNum(N - (M - C));
            else
                return "D" + getRomanNum(N - D);
        else if (N >= C)
            if (N >= D - C)
                return "CD" + getRomanNum(N - (D - C));
            else
                return "C" + getRomanNum(N - C);
        else if (N >= L)
            if (N >= C - X)
                return "XC" + getRomanNum(N - (C - X));
            else
                return "L" + getRomanNum(N - L);
        else if (N >= X)
            if (N >= L - X)
                return "XL" + getRomanNum(N - (L - X));
            else
                return "X" + getRomanNum(N - X);
        else if (N >= V)
            if (N >= X - I)
                return "IX" + getRomanNum(N - (X - I));
            else
                return "V" + getRomanNum(N - V);
        else if (N >= I)
            if (N >= V - I)
                return "IV" + getRomanNum(N - (V - I));
            else
                return "I" + getRomanNum(N - I);
        else
            return "";
    }
}
