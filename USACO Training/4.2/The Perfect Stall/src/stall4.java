/*
ID: cormac.1
LANG: JAVA
TASK: stall4
 */

import java.io.*;
import java.lang.*;
import java.util.*;

public class stall4 {
    static int N;
    static int M;
    static int[][] flow;
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("stall4.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("stall4.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        N = Integer.parseInt(s.nextToken());
        M = Integer.parseInt(s.nextToken());

        flow = new int[2+N+M][2+N+M];
        for (int i = 0; i < N; ++i) {
            s = new StringTokenizer(fin.readLine());
            int S = Integer.parseInt(s.nextToken());
            for (int j = 0; j < S; ++j) {
                flow[i+1][Integer.parseInt(s.nextToken())+N] = 1;
            }
        }

        // super-source
        for (int i = 0; i < N; ++i) flow[0][i+1] = 1;

        // super-sink
        for (int i = 0;i < M; ++i) flow[N+1+i][1+N+M] = 1;

        int total = 0;
        for (int pathFlow = 0; pathFlow != -1; pathFlow = augment()) {

            total += pathFlow;
        }
        fout.println(total);
        fout.close();
    }

    public static int augment() {
        // BFS to find path
        int[] parent = new int[2+N+M];
        boolean[] visited = new boolean[2+N+M];

        Queue<Integer> queue = new LinkedList<>();

        queue.add(0);
        parent[0] = -1;
        visited[0] = true;

        while (queue.size() > 0) {
            int curNode = queue.poll();

            for (int n = 0; n < 2 + N + M; ++n) {
                if (visited[n]) continue;
                if (flow[curNode][n] > 0) {
                    queue.add(n);
                    visited[n] = true;
                    parent[n] = curNode;
                }
            }

        }

        if (!visited[1 + N + M]) return -1;

        int pathFlow = Integer.MAX_VALUE;
        for (int v = 1 + N + M; v != 0; v = parent[v]) {
            pathFlow = Math.min(pathFlow, flow[parent[v]][v]);
        }

        for (int v = 1 + N + M; v != 0; v = parent[v]) {
            int p = parent[v];
            flow[p][v] -= pathFlow;
            flow[v][p] += pathFlow;
        }

        return pathFlow;
    }
}
