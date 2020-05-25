import java.io.*;
import java.lang.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("partyin.txt"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("partyout.txt")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int N = Integer.parseInt(s.nextToken());
        int M = Integer.parseInt(s.nextToken());
        int A = Integer.parseInt(s.nextToken());
        int B = Integer.parseInt(s.nextToken());

        boolean[][] cons = new boolean[N][N];
        int[][] consInParty = new int[N][2];

        boolean[] removedFromParty = new boolean[N];

        for (int i = 0; i < M; i++) {
            s = new StringTokenizer(fin.readLine());
            int p1 = Integer.parseInt(s.nextToken()) - 1;
            int p2 = Integer.parseInt(s.nextToken()) - 1;
            cons[p1][p2] = true;
            cons[p2][p1] = true;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (cons[i][j]) consInParty[i][0]++;
                else consInParty[i][1]++;
            }
            consInParty[i][1]--;
        }

        boolean isGood;
        while (true) {
            isGood = true;
            for (int i = 0; i < N; i++) {
                if (removedFromParty[i]) continue;

                if (consInParty[i][0] < A || consInParty[i][1] < B) {
                    isGood = false;
                    removedFromParty[i] = true;
                    for (int j = 0; j < N; j++) {
                        if (i == j) continue;
                        if (cons[i][j]) consInParty[j][0]--;
                        else consInParty[j][1]--;
                    }
                }
            }
            if (isGood) break;
        }

        int total = N;
        for (int i = 0; i < N; i++) {
            if (removedFromParty[i]) total--;
        }

        fout.println(total);
        fout.close();
    }
}
