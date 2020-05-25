/*
ID: cormac.1
LANG: JAVA
TASK: ditch
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class ditch {

    static int N;
    static int M;

    static int[][] flow;
    static int[][] orig;

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("ditch.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("ditch.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        N = Integer.parseInt(s.nextToken());
        M = Integer.parseInt(s.nextToken());

        flow = new int[M][M];
        orig = new int[M][M];

        for (int i = 0; i < N; ++i) {
            s = new StringTokenizer(fin.readLine());

            int S = Integer.parseInt(s.nextToken());
            int E = Integer.parseInt(s.nextToken());
            int C = Integer.parseInt(s.nextToken());

            flow[S-1][E-1] += C;
            orig[S-1][E-1] += C;
        }

        fout.println(getFlow());

        fout.close();
    }

    public static int getFlow() {
        int totalFlow = 0;
        while (true) {
            // Find path from source to sink
            int[] parent = new int[M];
            boolean[] visited = new boolean[M];

            Queue<Integer> queue = new LinkedList<Integer>();
            queue.add(0);
            parent[0] = -1;
            visited[0] = true;


            while (queue.size() > 0) {
                int curNode = queue.poll();

                for (int i = 0; i < M; ++i) {
                    if (visited[i]) continue;
                    if (flow[curNode][i] > 0) {
                        queue.add(i);
                        parent[i] = curNode;
                        visited[i] = true;
                    }
                }
            }

            if (!visited[M-1]) break;

            int pathFlow = Integer.MAX_VALUE;

            for (int v = M - 1; v != 0; v = parent[v]) {
                pathFlow = Math.min(pathFlow, flow[parent[v]][v]);
            }

            for (int v = M - 1; v != 0; v = parent[v]) {
                flow[parent[v]][v] -= pathFlow;
                flow[v][parent[v]] += pathFlow;
            }
            totalFlow += pathFlow;
        }
        return totalFlow;
    }

}
