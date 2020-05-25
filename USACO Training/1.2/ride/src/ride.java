/*
ID: cormac.1
LANG: JAVA
TASK: ride
 */

import java.io.*;
import java.util.*;

public class ride {
    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new FileReader("ride.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ride.out")));

        StringTokenizer s1 = new StringTokenizer(f.readLine());
        StringTokenizer s2 = new StringTokenizer(f.readLine());

        int n1 = 1;
        for (char c: s1.nextToken().toCharArray()) {
            n1 = (n1 * ((int) c % 64)) % 47;
        }

        int n2 = 1;
        for (char c: s2.nextToken().toCharArray()) {
            n2 = (n2 * ((int) c % 64)) % 47;
        }

        out.println((n1 == n2) ? "GO" : "STAY");
        out.close();
    }
}
