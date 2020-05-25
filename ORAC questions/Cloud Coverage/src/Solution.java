import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("cloudin.txt"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("cloudout.txt")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int N = Integer.parseInt(s.nextToken());
        int K = Integer.parseInt(s.nextToken());

        int[] friends = new int[N];
        int curDist = 0;
        int dist;
        for (int i = 0; i < N - 1; i++) {
            s = new StringTokenizer(fin.readLine());
            dist = Integer.parseInt(s.nextToken());
            friends[i] = dist;
            if (i < K) curDist += dist;
        }

        int maxDist = curDist;

        for (int i = K; i < N - 1; i++) {
            curDist += friends[i];
            curDist -= friends[i - K];
            maxDist = Math.min(curDist, maxDist);
        }
        fout.println(maxDist);
        fout.close();
    }
}
