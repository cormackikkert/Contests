/*
ID: cormac.1
LANG: JAVA
TASK: ariprog
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class ariprog {
    static Comparator<ArrayList<Integer>> compareAriProg = new Comparator<ArrayList<Integer>>() {
        @Override
        public int compare(ArrayList<Integer> a1, ArrayList<Integer> a2) {
            if (a1.get(1) < a2.get(1)) return -1;
            if (a1.get(1) == a2.get(1)) return (a1.get(0) < a2.get(0)) ? -1 : 1;
            return 1;
        }
    };

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("ariprog.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("ariprog.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int N = Integer.parseInt(s.nextToken());
        s = new StringTokenizer(fin.readLine());
        int M = Integer.parseInt(s.nextToken());

        HashSet<Integer> bisquares = new HashSet<Integer>(M * M + M * M);

        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i <= M; i++) {
            for (int j = i; j <= M; j++) {
                bisquares.add(i * i + j * j);
            }
        }
        int high = M * M + M * M;
        for (int a : bisquares) {
            for (int d = 1; d <= high; d++) {

                if (a + (N - 1) * d > high) break;
                boolean correct = true;
                for (int c = 0; c < N; c++) {
                    if (!bisquares.contains(a + c * d)) {
                        correct = false;
                        break;
                    }
                }
                if (correct) {
                    ArrayList<Integer> temp = new ArrayList<Integer>();
                    temp.add(a);
                    temp.add(d);
                    ans.add(temp);
                }
            }
        }

        Collections.sort(ans, compareAriProg);
        boolean printed = false;
        for (ArrayList<Integer> prog : ans) {
            printed = true;
            fout.println(prog.get(0) + " " + prog.get(1));
        }
        if (!printed) fout.println("NONE");
        fout.close();
    }
}

