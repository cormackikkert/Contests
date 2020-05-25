/*
ID: cormac.1
LANG: JAVA
TASK: beads
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class beads {
    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new FileReader("beads.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("beads.out")));

        StringTokenizer s = new StringTokenizer(f.readLine());
        final int N = Integer.parseInt(s.nextToken());

        s = new StringTokenizer(f.readLine());
        char[] beads = s.nextToken().toCharArray();

        int highest = -1;

        for (int l = 0; l < N; l++) {
            // Calculate left size
            char lFix = beads[l];
            int lSize = 1;
            while (lFix == 'w' || (lFix == beads[mod(l - lSize, N)] || 'w' == beads[mod(l - lSize, N)])) {
                if (lFix == 'w') {
                    lFix = beads[mod(l - lSize, N)];
                }
                lSize++;
                if (mod(l - lSize, N) == l) {
                    break;
                }
            }
            // Calculate right size
            char rFix = beads[mod(l+1, N)];
            int rSize = 1;
            while (rFix == 'w' || (rFix == beads[mod(l + rSize + 1, N)] || 'w' == beads[mod(l + rSize + 1, N)])) {
                if (rFix == 'w') {
                    rFix = beads[mod(l + rSize + 1, N)];
                }
                rSize++;
                if (mod(l + rSize + 1, N) == l) {
                    break;
                }
            }
            highest = Math.max(highest, lSize + rSize);
        }
        out.println(Math.min(highest, N));
        out.close();
    }

    public static int mod(int a, int b) {
        if (a < 0) {
            return mod(a + b, b);
        }
        return a % b;
    }
}
