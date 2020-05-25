import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("streetin.txt"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("streetout.txt")));
        StringTokenizer s = new StringTokenizer(fin.readLine());
        int N = Integer.parseInt(s.nextToken());
        int K = Integer.parseInt(s.nextToken());
        fout.println((int)Math.ceil(((double) N - K) / (double) (K + 1)));
        fout.close();
    }
}
