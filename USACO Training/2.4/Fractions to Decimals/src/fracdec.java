/*
ID: cormac.1
TASK: fracdec
LANG: JAVA
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class fracdec {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("fracdec.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("fracdec.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int N = Integer.parseInt(s.nextToken());
        int D = Integer.parseInt(s.nextToken());

        int oN = N;
        int oD = D;

        HashMap<Integer, Integer> loc = new HashMap<>();

        int st = 0;
        int en = 0;

        int t = 0;
        StringBuilder result = new StringBuilder();

        boolean hasDecimal = false;
        boolean repeats = false;
        boolean addZero = false;

        while (true) {
            if (loc.containsKey(N) && hasDecimal) {
                st = loc.get(N);
                en = t;
                repeats = true;
                break;
            }
            loc.put(N, t);
            int X = 1;
            if (N == 0) {
                break;
            } else if (N < D) {
                result.append('0');
                N *= 10;
            } else {
                result.append(N / D);
                X = (int) (Math.log10(N / D)) + 1;
                N = N % D;
                N *= 10;
            }

            addZero = false;
            if (oN < D * Math.pow(10, t+X) && !hasDecimal) {
                result.append('.');
                addZero = true;
                hasDecimal = true;
            }

            t+= X;
        }
        String answer = "";
        if (repeats)
            answer = result.substring(0, st+1) + "("+result.substring(st+1,en+1) + ")";
        else
            answer = result + ((addZero) ? "0" : "");
        for (int i = 0; i < answer.length(); ++i) {
            fout.print(answer.charAt(i));
            if (i % 76 == 75) fout.println();
        }
        fout.println();
        fout.close();
    }
}
