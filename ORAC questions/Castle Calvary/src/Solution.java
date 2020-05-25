import java.io.*;
import java.lang.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("cavalryin.txt"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("cavalryout.txt")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        int N = Integer.parseInt(s.nextToken());

        int[] occ = new int[N + 1];
        for (int i = 0; i < N; i++) {
            s = new StringTokenizer(fin.readLine());
            occ[Integer.parseInt(s.nextToken())]++;
        }

        boolean flag = false;
        for (int i = 1; i <= N; i++) if ((occ[i] > 0) && (occ[i] % i != 0)) flag = true;
        if (flag) fout.println("NO");
        else fout.println("YES");

        fout.close();
    }
}
