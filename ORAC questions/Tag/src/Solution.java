import java.io.*;
import java.lang.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("tagin.txt"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("tagout.txt")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int N = Integer.parseInt(s.nextToken());
        int M = Integer.parseInt(s.nextToken());
        int[] teams = new int[N+1];
        teams[1] = 2;
        teams[2] = 1;

        int a;
        int b;
        for (int i = 0; i < M; i++) {
            s = new StringTokenizer(fin.readLine());
            a = Integer.parseInt(s.nextToken());
            b = Integer.parseInt(s.nextToken());
            teams[b] = teams[a];
        }

        int red = 0;
        int blue = 0;
        for (int i = 1; i <= N; i++) {
            if (teams[i] == 2) red++;
            if (teams[i] == 1) blue++;
        }

        fout.println(red + " " + blue);
        fout.close();


    }
}
