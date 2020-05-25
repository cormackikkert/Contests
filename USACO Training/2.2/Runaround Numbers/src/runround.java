/*
ID: cormac.1
LANG: JAVA
TASK: runround
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class runround {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("runround.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("runround.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int M = Integer.parseInt(s.nextToken());

        do {
            M++;
        } while (!isRunRound(M));

        fout.println(M);
        fout.close();
    }

    public static boolean isRunRound(int x) {
        boolean[] done = new boolean[10];
        char[] data = Integer.toString(x).toCharArray();
        int index = 0;
        int count = 0;
        do {
            if (data[index] == '0') {
                return false;
            }
            if (done[data[index] - '0'])
                return (index == 0 && count == data.length);
            count++;
            done[data[index] - '0'] = true;
            index = (index + data[index] - '0') % data.length;
        } while (true);
    }
}
