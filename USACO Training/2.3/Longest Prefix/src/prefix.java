/*
ID: cormac.1
LANG: JAVA
TASK: prefix
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class prefix {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("prefix.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("prefix.out")));

        ArrayList<char[]> primitives = new ArrayList<>();

        StringTokenizer s;

        out : while (true) {
            s = new StringTokenizer(fin.readLine());

            while (s.hasMoreTokens()) {
                String prim = s.nextToken();
                if (prim.equals(".")) break out;
                primitives.add(prim.toCharArray());
            }
        }

        StringBuilder constituentStringBuilder = new StringBuilder();
        String line;
        while ((line = fin.readLine()) != null) {
            constituentStringBuilder.append(line);
        }

        char[] constituents = constituentStringBuilder.toString().toCharArray();
        int N = constituents.length;

        boolean[] canStart = new boolean[N];
        canStart[0] = true;
        int max = 0;
        out :
        for (int i = 0; i < N; i++) {
            if (!canStart[i]) continue;
            max = i;
            for (char[] prim : primitives) {
                if (i + prim.length < N && canStart[i + prim.length]) continue;
                match : {
                    for (int j = 0; j < prim.length; j++) {
                        if (i + j >= N || constituents[i + j] != prim[j]) break match;
                    }
                    if (i + prim.length == N) {
                        max = N;
                        break out;
                    }
                    canStart[i + prim.length] = true;
                }
            }
        }
        fout.println(max);
        fout.close();

    }
}
