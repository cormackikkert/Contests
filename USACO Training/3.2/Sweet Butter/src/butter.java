/*
ID: cormac.1
LANG: JAVA
TASK: butter
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class butter {
    static class Edge {
        int node;
        int weight;
        Edge(int n, int w) {
            this.node = n;
            this.weight = w;
        }
    }

    static class Node implements Comparator<Node>{
        int node;
        int dist;
        Node(int n, int d) {
            this.node = n;
            this.dist = d;
        }

        @Override
        public int compare(Node n1, Node n2) {
            return n1.dist - n2.dist;
        }
    }

    static int[] hasCow;
    static Vector<Vector<Edge>> connections;

    static int N, P, C;
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("butter.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("butter.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());

        N = Integer.parseInt(s.nextToken());
        P = Integer.parseInt(s.nextToken());
        C = Integer.parseInt(s.nextToken());

        hasCow = new int[P];
        connections = new Vector<>();

        for (int i = 0; i < N; ++i) {
            s = new StringTokenizer(fin.readLine());
            hasCow[Integer.parseInt(s.nextToken()) - 1]++;
        }

        for (int i = 0; i < P; ++i) connections.add(new Vector<>());

        for (int i = 0; i < C; ++i) {
            s = new StringTokenizer(fin.readLine());
            int a = Integer.parseInt(s.nextToken()) - 1;
            int b = Integer.parseInt(s.nextToken()) - 1;
            int l = Integer.parseInt(s.nextToken());
            connections.get(a).add(new Edge(b, l));
            connections.get(b).add(new Edge(a, l));
        }

        int minCost = Integer.MAX_VALUE;
        for (int i = 0; i < P; ++i) {
            minCost = Math.min(minCost, getCost(i));
        }

        fout.println(minCost);
        fout.close();
    }

    static int getCost(int start) {
        // Dijkstra
        boolean[] visited = new boolean[P];
        int[] distance = new int[P];

        for (int i = 0; i < P; ++i) {
            visited[i] = false;
            distance[i] = Integer.MAX_VALUE;
        }

        distance[start] = 0;

        int totalDist = 0;
        int foundCows = 0;

        PriorityQueue<Node> nodes = new PriorityQueue<>(P, new Node(0, 0));
        nodes.add(new Node(start, distance[start]));

        while (foundCows != N) {
            int n = nodes.poll().node;

            // Process node
            if (!visited[n]) {
                totalDist += distance[n] * hasCow[n];
                foundCows += hasCow[n];
                visited[n] = true;
            }

            // Search neighbours
            for (Edge neighbour : connections.get(n)) {
                if (visited[neighbour.node]) continue;
                if (neighbour.weight + distance[n] < distance[neighbour.node]) {
                    distance[neighbour.node] = neighbour.weight + distance[n];
                    nodes.add(new Node(neighbour.node, distance[neighbour.node]));
                }
            }
        }
        return totalDist;
    }
}
