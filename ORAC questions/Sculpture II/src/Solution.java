import java.io.*;
import java.util.*;
import java.lang.*;


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("artin.txt"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("artout.txt")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int N = Integer.parseInt(s.nextToken());
        int curHeight = 0;
        int maxHeight = 0;

        Stack<Integer[]> blocks = new Stack<Integer[]>();

        for (int n = 0; n < N; n++) {
            s = new StringTokenizer(fin.readLine());

            int t = Integer.parseInt(s.nextToken());
            int w = Integer.parseInt(s.nextToken());
            int h = Integer.parseInt(s.nextToken());

            while ((blocks.size() > 0) && (blocks.peek()[0] <= t)) {
                curHeight -= blocks.pop()[1];
            }

            blocks.push(new Integer[]{w + t, h});
            curHeight += h;
            maxHeight = Math.max(maxHeight, curHeight);
        }

        fout.println(maxHeight);
        fout.close();
    }
}
