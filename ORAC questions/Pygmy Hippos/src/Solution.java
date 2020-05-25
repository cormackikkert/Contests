import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("hippoin.txt"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("hippoout.txt")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int N = Integer.parseInt(s.nextToken());

        s = new StringTokenizer(fin.readLine());
        int h1 = Integer.parseInt(s.nextToken());

        s = new StringTokenizer(fin.readLine());
        int h2 = Integer.parseInt(s.nextToken());

        s = new StringTokenizer(fin.readLine());
        int h3 = Integer.parseInt(s.nextToken());

        fout.println(Math.max(Math.max(h2 - h1 - 1, h3 - h2 - 1) + Math.max(h1 - 1, N - h3),  h1 - 1 + N - h3));
        fout.close();

    }
}
