import java.io.*;
import java.lang.*;
import java.util.*;

public class Solution {
    static class Pair {
        int point;
        int parity;
        Pair(int a, int b) {
            this.point = a;
            this.parity = b;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("evadingin.txt"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("evadingout.txt")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        int N = Integer.parseInt(s.nextToken());
        int E = Integer.parseInt(s.nextToken());
        int X = Integer.parseInt(s.nextToken());
        int K = Integer.parseInt(s.nextToken());


        ArrayList<ArrayList<Integer>> neighbours = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i <= N; ++i) neighbours.add(new ArrayList<Integer>());

        for (int i = 0; i < E; ++i) {
            s = new StringTokenizer(fin.readLine());
            int a = Integer.parseInt(s.nextToken());
            int b = Integer.parseInt(s.nextToken());
            neighbours.get(b).add(a);
            neighbours.get(a).add(b);
        }

        int[][] distance = new int[2][N+1];
        for (int i = 0; i <= N; ++i) for (int j = 0; j < 2; ++j) distance[j][i] = -1;
        distance[0][X] = 0;

        Queue<Pair> queue = new LinkedList<Pair>();
        queue.add(new Pair(X, 0));

        while (queue.size() > 0) {
            Pair cur = queue.poll();
            for (int neighbour : neighbours.get(cur.point)) {
                if (distance[1-cur.parity][neighbour] == -1) {
                    distance[1-cur.parity][neighbour] = distance[cur.parity][cur.point] + 1;
                    queue.add(new Pair(neighbour,  1- cur.parity));
                }
            }
        }
        int total = 0;
        for (int i = 1; i <= N; ++i) {
            if (distance[K%2][i] <= K && distance[K%2][i] != -1) {
                ++total;
            }
        }

        fout.println(total);
        fout.close();

    }
}
