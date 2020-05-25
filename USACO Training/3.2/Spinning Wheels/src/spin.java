/*
ID: cormac.1
LANG: JAVA
TASK: spin
 */

import java.io.*;
import java.lang.*;
import java.util.*;

public class spin {
    static class Interval {
        int a;
        int b;
        Interval(int a, int b) {
            this.a = a;
            this.b = b;
        }
        boolean contains(int x) {
            if (this.a < this.b) return (this.a <= x && x <= this.b);
            else return (this.a <= x || x <= this.b);
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("spin.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("spin.out")));

        int[] rot = new int[5];
        ArrayList<ArrayList<Interval>> wedges = new ArrayList<>();

        StringTokenizer s;
        for (int i = 0; i < 5; ++i) {
            s = new StringTokenizer(fin.readLine());
            rot[i] = Integer.parseInt(s.nextToken());
            wedges.add(new ArrayList<>());
            int numWedges = Integer.parseInt(s.nextToken());
            for (int j = 0; j < numWedges; ++j) {
                int a = Integer.parseInt(s.nextToken());
                int b = Integer.parseInt(s.nextToken());
                wedges.get(i).add(new Interval(a, (a + b) % 360));
            }
        }

        search :
        {
            for (int t = 0; t < 360; ++t) {
                for (int j = 0; j < 360; ++j) {
                    doesHaveGap:
                    {
                        for (int wheel = 0; wheel < 5; ++wheel) {
                            boolean pierces = false;
                            for (Interval x : wedges.get(wheel)) {
                                Interval rep = new Interval((x.a + t * rot[wheel]) % 360, (x.b + t * rot[wheel]) % 360);
                                if (rep.contains(j)) {
                                    pierces = true;
                                }
                            }
                            if (!pierces) break doesHaveGap;
                        }
                        fout.println(t);
                        break search;
                    }
                }
            }
            fout.println("none");
        }
        fout.close();
    }
}
