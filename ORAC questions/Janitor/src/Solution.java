import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("janitorin.txt"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("janitorout.txt")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int R = Integer.parseInt(s.nextToken());
        int C = Integer.parseInt(s.nextToken());
        int Q = Integer.parseInt(s.nextToken());

        int[][] levels = new int[R][C];
        int[][] connections = new int[R][C];

        for (int y = 0; y < R; y++) {
            s = new StringTokenizer(fin.readLine());
            for (int x = 0; x < C; x++)
                levels[y][x] = Integer.parseInt(s.nextToken());
        }

        int total = 0;

        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                for (int m = -1; m < 3; m++) {
                    int nx = x + ((m % 2 != 0) ? m : 0);
                    int ny = y + ((m % 2 != 0) ? 0 : m - 1);

                    if (0 <= nx && nx < C && 0 <= ny && ny < R) {
                        connections[y][x] += (levels[ny][nx] > levels[y][x]) ? 1 : 0;
                    }
                }
                if (connections[y][x] == 0) {
                    total += 1;
                }
            }
        }

        fout.println(total);

        int r;
        int c;
        int l;

        int startConnections;

        for (int q = 0; q < Q; q++) {
            s = new StringTokenizer(fin.readLine());
            r = Integer.parseInt(s.nextToken()) - 1;
            c = Integer.parseInt(s.nextToken()) - 1;
            l = Integer.parseInt(s.nextToken());

            startConnections = connections[r][c];

            for (int m = -1; m < 3; m++) {
                int nx = c + ((m % 2 != 0) ? m : 0);
                int ny = r + ((m % 2 != 0) ? 0 : m -1);

                if (0 <= nx && nx < C && 0 <= ny && ny < R) {
                    if (l < levels[ny][nx] && levels[r][c] > levels[ny][nx]) {
                        connections[ny][nx] -= 1;
                        connections[r][c] += 1;
                        if (connections[ny][nx] == 0) total++;
                    }
                    if (l > levels[ny][nx] && levels[r][c] < levels[ny][nx]) {
                        if (connections[ny][nx] == 0) total--;
                        connections[ny][nx] += 1;
                        connections[r][c] -= 1;
                    }
                }
            }
            levels[r][c] = l;
            if (connections[r][c] == 0 && startConnections != 0) total++;
            if (connections[r][c] != 0 && startConnections == 0) total--;
            fout.println(total);
        }
        fout.close();
    }
}
