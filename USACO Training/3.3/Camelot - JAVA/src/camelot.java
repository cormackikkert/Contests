/*
ID: cormac.1
LANG: JAVA
TASK: camelot
 */

import java.io.*;
import java.util.*;
import java.lang.*;

public class camelot {
    public static int kingDist(int px, int py, int ex, int ey) {
        return Math.min(Math.abs(px - ex), Math.abs(py - ey)) + Math.abs(Math.abs(px - ex) - Math.abs(py - ey));

    }
    static class Node implements Comparator<Node> {
        boolean hasKing;
        int x;
        int y;
        int dist;

        Node(boolean hasKing, int x, int y, int dist) {
            this.hasKing = hasKing;
            this.x = x;
            this.y = y;
            this.dist = dist;
        }

        @Override
        public int compare(Node n1, Node n2) {
            return n1.dist - n2.dist;
        }
    }

    static int R;
    static int C;

    static int KX = -1;
    static int KY = -1;

    static int[][] totalKnightCost;
    static int[][] kingCost;

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("camelot.in"));
        PrintWriter fout = new PrintWriter(new BufferedWriter(new FileWriter("camelot.out")));

        StringTokenizer s = new StringTokenizer(fin.readLine());
        R = Integer.parseInt(s.nextToken());
        C = Integer.parseInt(s.nextToken());

        String line;
        while ((line = fin.readLine()) != null) {
            s = new StringTokenizer(line);
            while (s.hasMoreTokens()) {
                int x = s.nextToken().charAt(0) - 'A';
                int y = Integer.parseInt(s.nextToken()) - 1;

                if (KX == -1) {
                    KX = x;
                    KY = y;
                    totalKnightCost = new int[R][C];
                    kingCost = new int[R][C];


                    for (int a = 0; a < C; ++a) {
                        for (int b = 0; b < R; ++b) {
                            kingCost[b][a] = kingDist(a, b, KX, KY);
                        }
                    }
                } else {
                    dijkstra(x, y);
                }
            }
        }



        int minCost = Integer.MAX_VALUE;
        for (int x = 0; x < C; ++x) {
            for (int y = 0; y < R; ++y) {
                minCost = Math.min(minCost, totalKnightCost[y][x] + kingCost[y][x]);
            }
        }

        fout.println(minCost);
        fout.close();
    }

    static int[][] KNIGHT_DELTAS = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    public static void dijkstra(int startx, int starty) {
        int[][][] distance = new int[2][R][C];
        for (int[][] r1 : distance) {
            for (int[] r2 : r1) {
                Arrays.fill(r2, Integer.MAX_VALUE);
            }
        }
        boolean[][][] processed = new boolean[2][R][C];

        distance[0][starty][startx] = 0;

        PriorityQueue<Node> queue = new PriorityQueue<>(R * C, new Node(false, 0, 0, 0));
        queue.add(new Node(false, startx, starty, 0));

        while (queue.size() > 0) {
            Node item = queue.poll();

            int kint = item.hasKing ? 1 : 0;
            int x = item.x;
            int y = item.y;

            if (processed[kint][y][x]) continue;
            processed[kint][y][x] = true;

            // Knight moves
            for (int[] delta : KNIGHT_DELTAS) {
                int mx = delta[0];
                int my = delta[1];
                if (!(0 <= x + mx && x + mx < C && 0 <= y + my && y + my < R)) continue;

                if (distance[kint][y][x]  + 1 < distance[kint][y + my][x + mx]) {
                    distance[kint][y + my][x + mx] = distance[kint][y][x] + 1;
                    queue.add(new Node(kint == 1, x + mx, y + my,
                            distance[kint][y + my][x + mx]));
                }
            }

            // Pick up king move
            if (kint == 0) {
                if (distance[0][y][x] + kingDist(x, y, KX, KY) < distance[1][y][x]) {
                    distance[1][y][x] = distance[0][y][x] + kingDist(x, y, KX, KY);
                    queue.add(new Node(true, x, y, distance[1][y][x]));
                }
            }
        }

        for (int x = 0; x < C; ++x) {
            for (int y = 0; y < R; ++y) {
                if (totalKnightCost[y][x] != Integer.MAX_VALUE)
                    totalKnightCost[y][x] += distance[0][y][x];

                kingCost[y][x] = Math.min(kingCost[y][x], distance[1][y][x] - distance[0][y][x]);
            }
        }
    }
}
