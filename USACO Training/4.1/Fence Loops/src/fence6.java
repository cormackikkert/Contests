/*
ID: cormac.1
LANG: JAVA
TASK: fence6
 */

import java.io.*;
import java.lang.*;
import java.math.BigInteger;
import java.util.*;

public class fence6 {
    static int N;

    static double[] length;
    static ArrayList<ArrayList<Integer>> neighbours = new ArrayList<>();

    static double[][] edges;
    static List<List<Integer>> connections;

    static Random rand = new Random();

    static HashMap<BitSet, Integer> mapping = new HashMap<>();
    static int cur = 0;
    static int getIndex(BitSet data) {
        if (mapping.containsKey(data)) return mapping.get(data);
        mapping.put(data, cur);
        cur++;
        return mapping.get(data);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("fence6.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("fence6.out")));

        N = Integer.parseInt(fin.readLine());

        edges = new double[N + 1][N + 1];
        for (int i = 0; i <= N; ++i)
            for (int j = 0; j <= N; ++j)
                edges[i][j] = Double.POSITIVE_INFINITY;

        length = new double[N + 1];
        for (int i = 0; i <= N; ++i) neighbours.add(new ArrayList<>());

        edges = new double[2 * N + 1][2 * N + 1];
        for (int i = 0; i < 2 * N + 1; ++i)
            for (int j = 0; j < 2 * N + 1; ++j)
                edges[i][j] = Double.POSITIVE_INFINITY;

        for (int i = 0; i < N; ++i) {
            StringTokenizer s = new StringTokenizer(fin.readLine());
            int S = Integer.parseInt(s.nextToken());
            int L = Integer.parseInt(s.nextToken());
            int n1 = Integer.parseInt(s.nextToken());
            int n2 = Integer.parseInt(s.nextToken());
            length[S] = L;

            s = new StringTokenizer(fin.readLine());
            BitSet leftHash = new BitSet();
            leftHash.set(S);
            for (int j = 0; j < n1; ++j) {
                int neighbour = Integer.parseInt(s.nextToken());
                leftHash.set(neighbour);
            }

            s = new StringTokenizer(fin.readLine());
            BitSet rightHash = new BitSet();
            rightHash.set(S);
            for (int j = 0; j < n2; ++j) {
                int neighbour = Integer.parseInt(s.nextToken());
                rightHash.set(neighbour);
            }

            edges[getIndex(leftHash)][getIndex(rightHash)] = L;
            edges[getIndex(rightHash)][getIndex(leftHash)] = L;

        }
        /*
        for (double[] row : edges) {
            for (double x : row) {
                System.out.print(x + " ");
            }
            System.out.println();
        }
         */
        N = mapping.size();

        connections = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            List nodeConnections = new ArrayList<>();
            for (int j = 0; j < N; ++j) {
                if (edges[i][j] != Double.POSITIVE_INFINITY)
                    nodeConnections.add(j);
            }
            connections.add(nodeConnections);
        }
        for (int i = 0; i < N; ++i) {
            System.out.println("---");
            System.out.println(i);
            for (int j : connections.get(i)) {
                System.out.println(j + " " + edges[i][j]);
            }
        }
        int best = Integer.MAX_VALUE;
        for (int i = 0; i < N; ++i) {
            System.out.println(i + " " + (int) (findCircuit(i) + 0.5));
            best = Math.min(best, (int) (findCircuit(i) + 0.5));
        }

        fout.println(best);
        fout.close();
    }

    public static double findCircuit(int startVertex)  {

        double smallestLoop = Double.POSITIVE_INFINITY;

        boolean[] visited = new boolean[N];
        double[] distance = new double[N];
        int[] parent = new int[N];

        for (int i = 0; i < N; ++i) {
            distance[i] = Integer.MAX_VALUE;
            parent[i] = -1;
        }

        distance[startVertex] = 0;

        PriorityQueue<Node> nodes = new PriorityQueue<>(N, new Node(0, 0));
        nodes.add(new Node(startVertex, 0));

        while (nodes.size() > 0) {
            int curNode = nodes.poll().node;
            if (visited[curNode]) continue;
            visited[curNode] = true;

            for (int neighbour : connections.get(curNode)) {
                if (parent[curNode] != neighbour && parent[neighbour] != curNode) {
                    smallestLoop = Math.min(smallestLoop, distance[curNode] + edges[curNode][neighbour] + distance[neighbour]);
                    if (distance[curNode] + edges[curNode][neighbour] + distance[neighbour] == 142) {
                        System.out.println("INFO");
                        System.out.println(curNode + " " + distance[curNode]);
                        System.out.println(neighbour + " " + distance[neighbour]);
                        System.out.println(edges[curNode][neighbour]);
                    }
                }
                if (visited[neighbour]) continue;
                if (distance[curNode] + edges[neighbour][curNode] < distance[neighbour]) {
                    distance[neighbour] = distance[curNode] + edges[neighbour][curNode];
                    nodes.add(new Node(neighbour, distance[neighbour]));
                    parent[neighbour] = curNode;
                }
            }
        }
        return smallestLoop;
    }

    static class Node implements Comparator<Node> {
        int node;
        double dist;
        Node (int n, double d) {
            this.node = n; this.dist = d;
        }
        @Override
        public int compare(Node n1, Node n2) {
            if (n1.dist > n2.dist)
                return 1;
            if (n2.dist > n1.dist)
                return -1;
            return 0;
        }
    }
}
