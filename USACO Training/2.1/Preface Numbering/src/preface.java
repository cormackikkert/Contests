/*
ID: cormac.1
LANG: JAVA
TASK: preface
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class preface {
    class Num {
        String s = "";
        Num(String a) {
            s = a;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("preface.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("preface.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int N = Integer.parseInt(s.nextToken());

        /*
            I : 1
            V : 5
            X : 10
            L : 50
            C : 100
            D : 500
            M : 1000
         */
        String[] pages = new String[N+1];
        pages[0] = "";

        char[] values = "IVXLCDM".toCharArray();

        for (int i = 1; i < N; i++) {
            String curbest = "";

            // add compound
            for (char x : values) {

            }
            // subtract compound
        }
    }
}
