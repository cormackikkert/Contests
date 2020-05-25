/*
ID: cormac.1
LANG: JAVA
TASK: frac1
 */

import java.io.*;
import java.util.*;
import java.lang.*;

class Fraction implements Comparable<Fraction> {
    int n;
    int d;
    Fraction(int x, int y) {
        n = x;
        d = y;
    }
    @Override public int compareTo(Fraction other) {
        int l1 = this.n * other.d;
        int l2 = other.n * this.d;
        if (l1 < l2) return -1;
        if (l1 == l2) return 0;
        return 1;
    }
}

public class frac1 {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("frac1.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("frac1.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int N = Integer.parseInt(s.nextToken());

        TreeSet<Fraction> done = new TreeSet<>();

        for (int d = 1; d <= N; d++) {
            for (int n = 0; n <= d; n++) {
                done.add(new Fraction(n, d));
            }
        }

        for (Fraction f : done) {
            fout.println(f.n + "/" + f.d);
        }
        fout.close();
    }

}
