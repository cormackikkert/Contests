/*
ID: cormac.1
LANG: JAVA
TASK: milk3
 */

import java.io.*;
import java.lang.*;
import java.util.*;

public class milk3 {
    static HashSet<String> seen;
    static TreeSet<Integer> values;

    static int[] caps = new int[3];
    static Integer[] levels = new Integer[3];

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("milk3.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("milk3.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        caps[0] = Integer.parseInt(s.nextToken());
        caps[1] = Integer.parseInt(s.nextToken());
        caps[2] = Integer.parseInt(s.nextToken());

        levels[0] = 0;
        levels[1] = 0;
        levels[2] = caps[2];

        seen = new HashSet<String>(caps[0] * caps[1] * caps[2]);
        values = new TreeSet<Integer>();

        DFS();

        String output = "";
        for (Integer x : values) {
            output += x + " ";
        }
        output = output.substring(0, output.length() - 1);
        fout.println(output);
        fout.close();
    }

    public static void DFS() {
        if (levels[0] == 0) values.add(levels[2]);

        seen.add(Arrays.toString(levels));

        for (int b1 = 0; b1 < 3; b1++) {
            for (int b2 = 0; b2 < 3; b2++) {
                if (b1 == b2) continue;

                int pour = Math.min(levels[b1], caps[b2] - levels[b2]);

                levels[b1] -= pour;
                levels[b2] += pour;

                if (!seen.contains(Arrays.toString(levels)))
                    DFS();

                levels[b1] += pour;
                levels[b2] -= pour;

            }
        }
    }
}
